#include "PrintSMatrix.h"
#include "Crolinked_def.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int PrintSMatrix(Crosslist M)
{
	int i,j;
	OLink p;
	printf("%d��%d��%d������Ԫ��\n",M.mu,M.nu,M.tu );
	printf("ѡ����������ʽ��1.������� 2.�����������");
	scanf_s("%d", &i);
	{
		switch (i)
		{
		case 1:
			for (j = 0; j < M.mu; j++)
			{
				p = M.rhead[j];//ÿһ�е�ͷָ��ĵ�ַ�����ṹ��ָ��p
				while (p)
				{
					printf("��%d�е�%d�з���Ԫ��ֵ��%d\n", (p->i)+1, (p->j)+1, p->e);
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
					printf("��%d�е�%d�з���Ԫ��ֵ��%d\n", (p->i)+1, (p->j)+1, p->e);
					p = p->down;
				}				
			}
		}
	}
	return 1;
}