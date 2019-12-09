#include "PrintSMatrix.h"
#include "Crolinked_def.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int PrintSMatrix(Crosslist M)
{
	int i,j;
	OLink p;
	printf("%d行%d列%d个非零元素\n",M.mu,M.nu,M.tu );
	printf("选择矩阵输出方式（1.按行输出 2.按列输出）：");
	scanf_s("%d", &i);
	{
		switch (i)
		{
		case 1:
			for (j = 0; j < M.mu; j++)
			{
				p = M.rhead[j];//每一行的头指针的地址赋给结构体指针p
				while (p)
				{
					printf("第%d行第%d列非零元素值是%d\n", (p->i)+1, (p->j)+1, p->e);
					p = p->right;
				}				
			}
			break;

		case 2:
			for (j = 0; j < M.nu; j++)
			{
				p = M.chead[j];
				while (p)
				{
					printf("第%d行第%d列非零元素值是%d\n", (p->i)+1, (p->j)+1, p->e);
					p = p->down;
				}				
			}
		}
	}
	return 1;
}