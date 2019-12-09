#include <iostream>
#include "TestTensorFlow.h"
#include "tensorflow/core/public/session.h"
#include "tensorflow/core/platform/env.h"
#include "tensorflow/core/lib/io/path.h"
#include "tensorflow/cc/ops/standard_ops.h"
#include "tensorflow/core/lib/core/errors.h"




float PredictUsedTFmodel(float data[])
{
	//定义变量
	std::string modelPath = "Astar_pipeline.pb";

	//模型的输入输出layer
	std::string inputLayer = "inputs";
	std::string outputLayer = "pred";

	//声明Session和GraphDef
	auto options = tensorflow::SessionOptions();
	options.config.set_allow_soft_placement(true);
	std::unique_ptr<tensorflow::Session> session(tensorflow::NewSession(options));
	tensorflow::GraphDef graphdef;

	//读取pb模型文件
	tensorflow::Status status = ReadBinaryProto(tensorflow::Env::Default(), modelPath, &graphdef);
	if (!status.ok())
	{
		std::cout << status.ToString() << std::endl;
		return  -1;
	}

	//将graphdef和session关联
	status = session->Create(graphdef);
	if (!status.ok())
	{
		std::cout << status.ToString() << std::endl;
		return  -1;
	}

	// 数组变成Tensor数据
	tensorflow::Tensor input_tensor(tensorflow::DT_FLOAT, tensorflow::TensorShape({ 1, 21 }));
	auto input_tensor_mapped = input_tensor.tensor<float, 2>();
	
	float *pdata = data;
	for (int x = 0; x < 21; x++)
	{
		float *psource_value = pdata + x;
		input_tensor_mapped(0, x) = *psource_value;
	}



	//预测
	std::vector<tensorflow::Tensor> finalOutput;
	std::vector<std::pair<tensorflow::string, tensorflow::Tensor> > inputs;
	inputs.push_back(std::make_pair(inputLayer, input_tensor));

	status = session->Run(inputs, { outputLayer }, {}, &finalOutput);
	if (!status.ok())
	{

		std::cout << status.ToString() << std::endl;
		return -1;

	}
	auto output_y = finalOutput[0].scalar<float>();
	//std::cout << output_y() << "\n";

	float h;
	h = output_y();

	return h;
}






//测试tensorflow
//#include "TestTensorFlow.h"
//
//#include "tensorflow/cc/client/client_session.h"
//#include "tensorflow/cc/ops/standard_ops.h"
//#include "tensorflow/core/framework/tensor.h"


//int main() {
//	using namespace tensorflow;
//	using namespace tensorflow::ops;
//	Scope root = Scope::NewRootScope();
//	// Matrix A = [3 2; -1 0]
//	auto A = Const(root, { { 3.f, 2.f },{ -1.f, 0.f } });
//	// Vector b = [3 5]
//	auto b = Const(root, { { 3.f, 5.f } });
//	// v = Ab^T
//	auto v = MatMul(root.WithOpName("v"), A, b, MatMul::TransposeB(true));
//	std::vector<Tensor> outputs;
//	ClientSession session(root);
//	// Run and fetch v
//	TF_CHECK_OK(session.Run({ v }, &outputs));
//	// Expect outputs[0] == [19; -3]
//	LOG(INFO) << outputs[0].matrix<float>();
//	return 0;
//}
