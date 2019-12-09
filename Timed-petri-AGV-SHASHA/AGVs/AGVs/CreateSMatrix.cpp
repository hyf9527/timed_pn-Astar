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
	if ((*M).rhead)//�����*M).rhead�ǿգ�������ϡ�����
		DestroySMatrix(M);
  
	(*M).rhead = (OLink*)malloc((MaxRow) * sizeof(OLink));   //���ṹ��ָ�����飩Ϊ��ͷָ������ڴ�ռ�
	if (!(*M).rhead)
		exit (0);
	(*M).chead = (OLink*)malloc((MaxRow) * sizeof(OLink));    //Ϊ��ͷָ������ڴ�ռ�
	if (!(*M).chead)
		exit(0);

	for (k = 0; k < MaxRow; k++) //��ʼ������������ͷ
	{
		(*M).rhead[k] = NULL;
	}
	for (k = 0; k < MaxRow; k++)//��ʼ������������ͷ
	{
		(*M).chead[k] = NULL;
	 }

	int buffer[MaxRow][MaxRow];
	char line[100];
	FILE *fp;	
	int irow = 0;
	int icol = 0;
	int icol_num = 0;
	fp = fopen(path, "r");//��ν��ж�ȡ����
	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(line, 100, fp) == NULL)//���зָ�
				break;

			char *pch = strtok(line, " ");  //�����Ϊ�գ���ʹ��strtok�������տո�����֣�����һ���ַ���ָ��
			while (pch != NULL)
			{
				int val = atoi(pch);//ǿ������ת�����ַ���ת��Ϊ���ͣ�

				buffer[irow][icol] = val; //���ݴ洢��������Ԫ�ط��ڻ��������

				if (val != 0)
				{
					p = (OLNode*)malloc(sizeof(OLNode));
					if (!p)
						exit(0);
					p->i = irow;//���ɽ��
					p->j = icol;
					p->e = val;

					/*
					���ɽ���Ҫ��ÿһ������Ԫ����������
					�ж��С���ͷָ��ѡ�����������
					���һ�������һ����û�н�㣬ѡ��ֱ�Ӳ��룻
					������������һ�����н�㣬ѡ����뵽��ȷ��λ��
					*/
					if ((*M).rhead[irow] == NULL || (*M).rhead[irow]->j > icol)
					{
						p->right = (*M).rhead[irow];//p���ڸ��еĵ�һ����㴦
						(*M).rhead[irow] = p;
					}
					else //(�Ӹ��е�������ͷ��ʼ��ֱ���ҵ�)
					{
						for (q = (*M).rhead[irow]; q->right && q->right->j < icol; q = q->right)// q->right && q->right->j < icol; q = q->right��֤��ȫ��
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
				pch = strtok(NULL, " ");//�����ָ�
			}
			irow++;
			icol_num = icol;//��icol_num��¼ʵ�ʵ�������icol��Ϊÿ�зָ�Ķ�Ӧ����
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
