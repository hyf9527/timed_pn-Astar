#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "Crolinked_def.h"
#include "DestroySMatrix.h"
#include "CreateSMatrix.h"
/*
初始条件：稀疏矩阵M存在
操作结果：销毁稀疏矩阵
操作方法：选择按行释放结点
释放之后：初始化矩阵M 
*/
int DestroySMatrix(Crosslist *M)
{
	int i;
	OLNode *p,*q;
	for (i = 1; i<=(*M).mu; i++)
	{
		p = (*M).rhead[i];
		while (p)  //地址不为空
		{
			q = p;
			p = p->right;
			free(q);//释放：q指针指向的由malloc所配的内存单元
		}
	}
	free((*M).rhead);
	free((*M).chead);
	(*M).rhead = (*M).chead = NULL;
	(*M).mu = (*M).nu = (*M).tu = 0;
	return 1;
}