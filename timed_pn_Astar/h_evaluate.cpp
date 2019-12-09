
#include "h_evaluate.h"
#include "output.h"
#include "TestTensorFlow.h"
#include <iostream>

/*
* Comments: 对数据进行预处理
* Param Tree *Tr :  树
* @Return void
*/


float scale(float num, float mean, float std)
{
	float res;
	res = (num - mean) / std;
	return res;
}


int  class_num_search(AstarNode *n, int index[], int *m_class, int row, int col)
{
	int flag = 0;
	int class_num = -1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (n->new_m[index[j]] == *(m_class + i * row + j))
			{
				flag = 1;
				//printf("%2d\t %2d\t ", n->new_m[index[j]], *(m_class + i * row + j));
			}
			else
			{
				flag = 0;
				break;
			}
		}
		//printf("\n");
		if (flag == 1)
		{
			class_num = i;
			break;
		}
	}
	if(flag != 1)
		throw "Misclassification occurs!!!";
	return class_num;
}


 void Prepare_data_for_prediction(AstarTree *Tr, float data[])
{
	struct AstarNode *P;
	P = (*Tr).former;
	data[0] = scale(P->new_m[0], 0.466444, 0.678948);
	data[1] = scale(P->new_m[11], 0.194992, 0.396227);
	data[2] = scale(P->new_m[12], 0.644407, 0.734680);
	data[3] = scale(P->new_m[16], 0.144407, 0.351532);
	data[4] = scale(P->new_m[17], 0.761269, 0.689909);
	data[5] = scale(P->new_m[19], 0.337896, 0.473033);
	data[6] = scale(P->new_m[20], 0.337229, 0.472803);
	int index_1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int m_class_1[27][10] = { {0,0,0,0,0,0,0,0,0,0}, \
							  {1,0,0,0,0,0,0,0,0,0},  \
							  {0,1,0,0,0,0,0,0,0,0},  \
							  {0,0,1,0,0,0,0,0,0,0},  \
							  {0,0,0,1,0,0,0,0,0,0},  \
							  {0,0,0,0,1,0,0,0,0,0},  \
							  {0,0,0,0,0,1,0,0,0,0},  \
							  {0,0,0,0,0,0,0,0,1,0},  \
							  {0,0,0,0,0,0,0,0,0,1},  \
							  {1,0,0,0,1,0,0,0,0,0},  \
							  {1,0,0,0,0,1,0,0,0,0},  \
							  {0,1,0,0,1,0,0,0,0,0},  \
							  {0,1,0,0,0,1,0,0,0,0},  \
							  {0,1,0,0,0,0,0,0,1,0},  \
							  {0,0,0,0,0,1,0,0,1,0},  \
							  {1,0,0,0,0,0,0,0,0,1},  \
							  {0,0,0,0,1,0,0,0,0,1},  \
							  {0,1,0,0,0,1,0,0,1,0},  \
							  {1,0,0,0,1,0,0,0,0,1},  \
							  {0,0,0,1,0,0,0,0,1,0},  \
							  {0,0,1,0,0,0,0,0,0,1},  \
							  {0,0,0,0,0,0,1,0,0,0},  \
							  {0,0,0,0,1,0,1,0,0,0},  \
							  {0,0,0,0,0,1,1,0,0,0},  \
							  {0,0,0,0,0,0,0,1,0,0},  \
							  {1,0,0,0,0,0,0,1,0,0},  \
							  {0,1,0,0,0,0,0,1,0,0},  \
	};
	int class_num_1 = -1;
	//class_num_1 = class_num_search(P, index_1, *m_class_1, 27, 10);
	int flag_1 = 0;
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (P->new_m[index_1[j]] == m_class_1[i][j])
			{
				flag_1 = 1;
				//printf("%2d\t %2d\t ", n->new_m[index[j]], *(m_class + i * row + j));
			}
			else
			{
				flag_1 = 0;
				break;
			}
		}
		//printf("\n");
		if (flag_1 == 1)
		{
			class_num_1 = i;
			break;
		}
	}
	if (flag_1 != 1)
		throw "Misclassification occurs!!!";
	data[7] = scale(class_num_1, 9.252254, 7.152419);
	printf("%2d\t", class_num_1);


	int index_2[4] = {13, 14, 15, 18};
	int m_class_2[31][4] = { {2,1,1,2},\
							{1,1,1,2},\
							{1,0,1,1},\
							{1,1,0,1},\
							{0,0,1,1},\
							{0,1,0,1},\
							{1,1,1,1},\
							{0,1,1,1},\
							{0,0,0,0},\
							{0,1,0,0},\
							{0,0,1,0},\
							{2,0,0,0}, \
							{1,0,0,0}, \
							{2,1,0,0}, \
							{0,1,1,0}, \
							{0,0,0,2}, \
							{2,0,1,0}, \
							{1,1,0,0}, \
							{1,0,1,0}, \
							{0,1,0,2}, \
							{2,1,1,0}, \
							{2,0,0,2}, \
							{0,0,1,2}, \
							{1,1,1,0}, \
							{1,0,0,2}, \
							{2,1,0,2}, \
							{0,1,1,2}, \
							{2,0,1,2}, \
							{1,1,0,2}, \
							{1,0,1,2}, \
							{1,0,0,1}, \
	};
	int class_num_2 = -1;
	//class_num_2 = class_num_search(P, index_2, *m_class_2, 31, 4);
	int flag_2 = 0;
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (P->new_m[index_2[j]] == m_class_2[i][j])
			{
				flag_2 = 1;
				//printf("%2d\t %2d\t ", n->new_m[index[j]], *(m_class + i * row + j));
			}
			else
			{
				flag_2 = 0;
				break;
			}
		}
		//printf("\n");
		if (flag_2 == 1)
		{
			class_num_2 = i;
			break;
		}
	}
	if (flag_2 != 1)
		throw "Misclassification occurs!!!";
	data[8] = scale(class_num_2, 14.446411, 8.697513);
	printf("%2d\t", class_num_2);


	int index_3[9] = {21, 22, 23, 24, 25, 26, 27, 28, 29};
	int m_class_3[44][9] = {{1,1,1,1,1,1,1,1,1},\
							{1,0,1,1,1,1,1,0,1},\
							{1,1,1,0,1,1,1,0,1},\
							{1,1,1,1,1,1,1,0,1},\
							{0,1,1,1,1,1,1,0,0},\
		                    {1,1,1,1,1,1,1,1,0},\
							{1,0,1,1,1,1,1,0,0},\
							{1,1,1,0,1,1,1,0,0},\
							{1,1,0,1,1,0,1,1,0},\
							{1,1,1,1,1,0,0,1,0},\
							{1,0,0,1,0,1,1,1,0},\
							{1,1,1,0,0,1,0,1,0},\
							{1,0,0,1,1,0,1,0,0},\
							{1,0,1,1,1,0,0,0,0},\
							{1,1,1,1,1,1,1,0,0},\
							{1,1,0,0,1,0,1,0,0},\
							{1,1,1,0,1,0,0,0,0},\
							{1,0,0,0,0,1,1,0,0},\
							{1,0,0,1,0,0,0,1,0},\
							{1,0,1,0,0,1,0,0,0},\
							{1,1,0,0,0,0,0,1,0},\
							{1,1,0,1,1,0,1,0,0},\
							{1,1,1,1,1,0,0,0,0},\
							{1,0,0,1,0,1,1,0,0},\
							{1,0,0,0,0,0,0,0,0},\
							{1,0,0,1,0,1,1,1,1},\
							{1,1,1,0,0,1,0,0,0},\
							{1,1,1,0,0,1,0,1,1},\
							{1,0,0,1,0,0,0,0,0},\
							{1,0,0,0,0,1,1,0,1},\
							{1,1,0,0,0,0,0,0,0},\
							{1,0,1,0,0,1,0,0,1},\
							{1,0,0,1,0,1,1,0,1},\
							{1,1,1,0,0,1,0,0,1},\
							{0,0,0,1,0,1,1,0,0},\
							{0,1,1,0,0,1,0,0,0},\
							{0,1,1,1,0,1,1,0,0},\
							{0,1,0,1,0,0,1,0,0},\
							{0,1,1,1,0,0,0,0,0},\
							{0,1,1,1,0,1,1,0,1},\
							{0,1,1,1,0,0,1,1,0},\
							{0,0,1,1,0,0,1,0,0},\
							{0,1,1,0,0,0,1,0,0},\
							{0,1,1,1,0,0,1,0,0},\
	};

	int class_num_3 = -1;
	//class_num_3 = class_num_search(P, index_3, *m_class_3, 39, 9);
	int flag_3 = 0;
	for (int i = 0; i < 44; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (P->new_m[index_3[j]] == m_class_3[i][j])
			{
				flag_3 = 1;
				//printf("%2d\t %2d\t ", n->new_m[index[j]], *(m_class + i * row + j));
			}
			else
			{
				flag_3 = 0;
				break;
			}
		}
		//printf("\n");
		if (flag_3 == 1)
		{
			class_num_3 = i;
			break;
		}
	}
	if (flag_3 != 1)
		throw "Misclassification occurs!!!";
	data[9] = scale(class_num_3, 18.517362, 12.743705);
	printf("%2d\t", class_num_3);

	data[10] = scale(P->new_m_x[1], 0.243740, 1.053276);
	data[11] = scale(P->new_m_x[2], 0.251419, 1.069263);
	data[12] = scale(P->new_m_x[3], 0.027546, 0.370127);
	data[13] = scale(P->new_m_x[4], 0.018364, 0.302486);
	data[14] = scale(P->new_m_x[5], 0.340401, 1.226204);
	data[15] = scale(P->new_m_x[6], 0.345910, 1.236399);
	data[16] = scale(P->new_m_x[7], 0.059265, 0.541169);
	data[17] = scale(P->new_m_x[8], 0.024207, 0.347087);
	data[18] = scale(P->new_m_x[9], 0.299165, 1.128118);
	data[19] = scale(P->new_m_x[10], 0.351753, 1.223951);
	data[20] = scale(P->new_m_g, 42.909015, 17.365928);






	/*char class_label[6];
	P = (*Tr).former;
	data[0] = scale(P->new_m[0], 0.619386, 0.829183);
	data[1] = scale(P->new_m[1], 0.632058, 0.843121);
	data[2] = scale(P->new_m[4], 0.888190, 0.974661);
	data[3] = scale(P->new_m[5], 1.030576, 1.043166);
	data[4] = scale(P->new_m[8], 1.611341, 1.117958);
	data[5] = scale(P->new_m[9], 1.438288, 1.131243);
	if (P->new_m[2] == 0 && P->new_m[3] == 0 && P->new_m[6] == 0 && P->new_m[7] == 0 \
		&& P->new_m[10] == 1 && P->new_m[11] == 1)
		data[6] = scale(0, 4.041101, 2.472919);
	else if (P->new_m[2] == 1 && P->new_m[3] == 0 && P->new_m[6] == 0 && P->new_m[7] == 0 \
		&& P->new_m[10] == 0 && P->new_m[11] == 1)
		data[6] = scale(1, 4.041101, 2.472919);
	else if (P->new_m[2] == 0 && P->new_m[3] == 1 && P->new_m[6] == 0 && P->new_m[7] == 0 \
		&& P->new_m[10] == 0 && P->new_m[11] == 1)
		data[6] = scale(2, 4.041101, 2.472919);
	else if (P->new_m[2] == 0 && P->new_m[3] == 0 && P->new_m[6] == 1 && P->new_m[7] == 0 \
		&& P->new_m[10] == 1 && P->new_m[11] == 0)
		data[6] = scale(3, 4.041101, 2.472919);
	else if (P->new_m[2] == 0 && P->new_m[3] == 0 && P->new_m[6] == 0 && P->new_m[7] == 1 \
		&& P->new_m[10] == 1 && P->new_m[11] == 0)
		data[6] = scale(4, 4.041101, 2.472919);
	else if (P->new_m[2] == 1 && P->new_m[3] == 0 && P->new_m[6] == 1 && P->new_m[7] == 0 \
		&& P->new_m[10] == 0 && P->new_m[11] == 0)
		data[6] = scale(5, 4.041101, 2.472919);
	else if (P->new_m[2] == 0 && P->new_m[3] == 1 && P->new_m[6] == 1 && P->new_m[7] == 0 \
		&& P->new_m[10] == 0 && P->new_m[11] == 0)
		data[6] = scale(6, 4.041101, 2.472919);
	else if (P->new_m[2] == 1 && P->new_m[3] == 0 && P->new_m[6] == 0 && P->new_m[7] == 1 \
		&& P->new_m[10] == 0 && P->new_m[11] == 0)
		data[6] = scale(7, 4.041101, 2.472919);
	else if (P->new_m[2] == 0 && P->new_m[3] == 1 && P->new_m[6] == 0 && P->new_m[7] == 1 \
		&& P->new_m[10] == 0 && P->new_m[11] == 0)
		data[6] = scale(8, 4.041101, 2.472919);
	else
		throw "Misclassification occurs!!!";
	data[7] = scale(P->new_m_x[2], 0.754574, 1.752667);
	data[8] = scale(P->new_m_x[3], 0.864721, 1.893996);
	data[9] = scale(P->new_m_x[6], 0.392772, 1.146061);
	data[10] = scale(P->new_m_x[7], 0.350764, 1.031940);
	data[11] = scale(P->new_m_g, 13.521246, 4.486003);*/
}












float h_eval(AstarTree *Tr)
{
	float data[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	Prepare_data_for_prediction(Tr, data);
	//Astardata_process(Tr); 
	float h;
	//const char *path = "A_data/1.txt";
	//h = testAstar(path);
	h = PredictUsedTFmodel(data);
	std::cout << h * 10.83611879 + 22.06510851 << "\n";
	return h*10.836118 + 22.065108;
	//return h*4.486003+ 13.521246;
}

