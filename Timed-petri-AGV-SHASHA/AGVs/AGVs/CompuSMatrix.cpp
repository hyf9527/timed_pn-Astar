#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "Crolinked_def.h"
#include "CompuSMatrix.h"
#include "InitSMatrix.h"
int CompuSMatrix(Crosslist M, Crosslist N, Crosslist *Q)
{
	int i, k;
	OLink p,pm, pn;
	OLink pq = NULL;
	OLink *col;//ָ����ָ��

	if (M.mu != N.mu || M.nu != N.nu)
	{
		printf("����������ͬ���͵�,��������\n");
		exit(0);
	}
	(*Q).mu = M.mu; // ��ʼ��Q���� 
	(*Q).nu = M.nu;
	(*Q).tu = 0;

	(*Q).rhead = (OLink*)malloc(((*Q).mu) * sizeof(OLink));//ΪQ������ͷָ������ڴ�
	if (!(*Q).rhead)
		exit(0);

	(*Q).chead = (OLink*)malloc(((*Q).nu) * sizeof(OLink));
	if (!(*Q).chead)
		exit(0);

	for (k = 0; k < (*Q).mu; k++) // ��ʼ��Q���С���ͷָ������
		(*Q).rhead[k] = NULL;
	for (k = 0; k < (*Q).nu; k++) 
		(*Q).chead[k] = NULL;       

	col = (OLink*)malloc(((*Q).nu + 1) * sizeof(OLink));  //����ָ���е�����������
	if (!col)
		exit(0);
	for (k = 0; k < (*Q).nu; k++) 
		col[k] = NULL;


	for (i = 0; i < M.mu; i++) // ���е�˳������ 
	{
		pm = M.rhead[i]; 
		pn = N.rhead[i]; 

		while (pm&&pn) // pm��pn������ 
		{
			if (pm->j < pn->j) // ����M��ǰ������С�ھ���N��ǰ������ 
			{
				p = (OLink)malloc(sizeof(OLNode));
				if (!p)
					exit(0);
				(*Q).tu++; 
				p->i = i; // ���ɾ���Q�Ľ�� 
				p->j = pm->j;
				p->e = pm->e;
				p->right = NULL;
				pm = pm->right; 
			}
			
			else if (pm->j > pn->j)
			{
				p = (OLink)malloc(sizeof(OLNode));
				if (!p)
					exit(0);
				(*Q).tu++; 
				p->i = i; 
				p->j = pn->j;
				p->e = -pn->e;
				p->right = NULL;
				pn = pn->right; 
			}

			else if (pm->e - pn->e)
			{				
				p = (OLink)malloc(sizeof(OLNode)); 
				if (!p)
					exit(0);
				(*Q).tu++; 
				p->i = i; 
				p->j = pn->j;
				p->e = pm->e - pn->e;
				p->right = NULL;
				pm = pm->right; 
				pn = pn->right;
			}
			else  
			{
				pm = pm->right; 
				pn = pn->right;
				continue;
			}
			
			if ((*Q).rhead[i] == NULL) // pΪ���еĵ�1����㣬pqָ��p								
				(*Q).rhead[i] = pq = p;
			else // ����pq��ָ���֮�� 
			{
				pq->right = p; // ����в��� 
				pq = pq->right; // pqָ����е����һ����� 				
			}

			if ((*Q).chead[p->j] == NULL) 
				(*Q).chead[p->j] = col[p->j] = p;// p���ڸ��еı�ͷ��col[p->j]ָ��p
			else // ����col[p->j]��ָ���֮�� 
			{
				col[p->j]->down = p; // ����в���
				col[p->j] = col[p->j]->down;
			}
		}
		while (pm) // ������M���е�ʣ��Ԫ�ز������Q 
		{
			p = (OLink)malloc(sizeof(OLNode)); 
			if (!p)
				exit(0);
			(*Q).tu++; 
			p->i = i; 
			p->j = pm->j;
			p->e = pm->e;
			p->right = NULL;
			pm = pm->right; 

			if ((*Q).rhead[i] == NULL) 
				(*Q).rhead[i] = pq = p;
			else 
			{
				pq->right = p; 
				pq = pq->right; 
			}

			if ((*Q).chead[p->j] == NULL) 				
				(*Q).chead[p->j] = col[p->j] = p;
			else 
			{
				col[p->j]->down = p;
				col[p->j] = col[p->j]->down;
			}
		}

		while (pn) // ������N���е�ʣ��Ԫ�ز������Q 
		{
			p = (OLink)malloc(sizeof(OLNode)); 
			if (!p)
				exit(0);
			(*Q).tu++; 
			p->i = i; 
			p->j = pn->j;
			p->e = -pn->e;
			p->right = NULL;
			pn = pn->right;
			if ((*Q).rhead[i] == NULL)				
				(*Q).rhead[i] = pq = p;
			else 
			{
				pq->right = p;  
				pq = pq->right;  
			}

			if ((*Q).chead[p->j] == NULL) 
				(*Q).chead[p->j] = col[p->j] = p;
			else 
			{
				col[p->j]->down = p; 				 
				col[p->j] = col[p->j]->down;
			}
		}
	}
	for (k = 0; k < (*Q).nu; k++)
		if (col[k]) // k���н�� 
			col[k]->down = NULL; // ��������һ������downָ��Ϊ�� 
	free(col);
	return 1;
}