#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "CreateSMatrix.h"
#include "Crolinked_def.h"
#include "DestroySMatrix.h"



void CreateSMatrix(Crosslist *M, const char *path)
{
	int k,Non_zero_num = 0;
	OLNode *p, *q;
	if ((*M).rhead)//如果（*M).rhead非空，则销毁稀疏矩阵
		DestroySMatrix(M);
  
	(*M).rhead = (OLink*)malloc((MaxRow) * sizeof(OLink));   //（结构体指针数组）为行头指针分配内存空间
	if (!(*M).rhead)
		exit (0);
	(*M).chead = (OLink*)malloc((MaxRow) * sizeof(OLink));    //为列头指针分配内存空间
	if (!(*M).chead)
		exit(0);

	for (k = 0; k < MaxRow; k++) //初始化矩阵行链表头
	{
		(*M).rhead[k] = NULL;
	}
	for (k = 0; k < MaxRow; k++)//初始化矩阵列链表头
	{
		(*M).chead[k] = NULL;
	 }

	int buffer[MaxRow][MaxRow];
	char line[100];
	FILE *fp;	
	int irow = 0;
	int icol = 0;
	int icol_num = 0;
	fp = fopen(path, "r");//如何进行读取数据
	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(line, 100, fp) == NULL)//按行分割
				break;

			char *pch = strtok(line, " ");  //如果不为空，则使用strtok函数按照空格符划分，放在一个字符型指针
			while (pch != NULL)
			{
				int val = atoi(pch);//强制类型转换（字符型转换为整型）

				buffer[irow][icol] = val; //数据存储，将所有元素放在缓冲矩阵中

				if (val != 0)
				{
					p = (OLNode*)malloc(sizeof(OLNode));
					if (!p)
						exit(0);
					p->i = irow;//生成结点
					p->j = icol;
					p->e = val;

					/*
					生成结点后，要将每一个非零元素连接起来
					判断行、列头指针选择插入的情况：
					情况一：如果这一行中没有结点，选择直接插入；
					情况二：如果这一行中有结点，选择插入到正确的位置
					*/
					if ((*M).rhead[irow] == NULL || (*M).rhead[irow]->j > icol)
					{
						p->right = (*M).rhead[irow];//p插在该行的第一个结点处
						(*M).rhead[irow] = p;
					}
					else //(从该行的行链表头开始，直至找到)
					{
						for (q = (*M).rhead[irow]; q->right && q->right->j < icol; q = q->right)// q->right && q->right->j < icol; q = q->right保证安全性
							;
						p->right = q->right;
						q->right = p;
					}

					if ((*M).chead[icol] == NULL || (*M).chead[icol]->j > irow)
					{
						p->down = (*M).chead[icol];
						(*M).chead[icol] = p;
					}
					else
					{
						for (q = (*M).chead[icol]; q->down && q->down->i < irow; q = q->down)
							;
						p->down = q->down;
						q->down = p;
					}
					Non_zero_num++;
				}
				icol++;
				pch = strtok(NULL, " ");//继续分割
			}
			irow++;
			icol_num = icol;//用icol_num记录实际的列数，icol作为每行分割的对应的列
			icol = 0;  
		}
		fclose(fp);
	}
	(*M).mu = irow ;
	(*M).nu = icol_num;
	(*M).tu = Non_zero_num;
	printf("\n");
	for (int i = 0; i < irow; i++)
	{
		for (int j = 0; j < icol_num; j++)
		{
			printf("%2d", buffer[i][j]);
		}
		printf("\n");
	}
}
