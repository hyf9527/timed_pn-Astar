#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "Crolinked_def.h"
#include "DestroySMatrix.h"
#include "CreateSMatrix.h"
/*
��ʼ������ϡ�����M����
�������������ϡ�����
����������ѡ�����ͷŽ��
�ͷ�֮�󣺳�ʼ������M 
*/
int DestroySMatrix(Crosslist *M)
{
	int i;
	OLNode *p,*q;
	for (i = 1; i<=(*M).mu; i++)
	{
		p = (*M).rhead[i];
		while (p)  //��ַ��Ϊ��
		{
			q = p;
			p = p->right;
			free(q);//�ͷţ�qָ��ָ�����malloc������ڴ浥Ԫ
		}
	}
	free((*M).rhead);
	free((*M).chead);
	(*M).rhead = (*M).chead = NULL;
	(*M).mu = (*M).nu = (*M).tu = 0;
	return 1;
}