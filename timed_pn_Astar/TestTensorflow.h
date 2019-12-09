#pragma once  //这一句防止重复include头文件

#define COMPILER_MSVC
#define NOMINMAX  //这一句防止max/min函数命名冲突

float PredictUsedTFmodel(float data[]);
