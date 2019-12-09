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
	OLink *col;//指向列指针

	if (M.mu != N.mu || M.nu != N.nu)
	{
		printf("两个矩阵不是同类型的,不能运算\n");
		exit(0);
	}
	(*Q).mu = M.mu; // 初始化Q矩阵 
	(*Q).nu = M.nu;
	(*Q).tu = 0;

	(*Q).rhead = (OLink*)malloc(((*Q).mu) * sizeof(OLink));//为Q矩阵行头指针分配内存
	if (!(*Q).rhead)
		exit(0);

	(*Q).chead = (OLink*)malloc(((*Q).nu) * sizeof(OLink));
	if (!(*Q).chead)
		exit(0);

	for (k = 0; k < (*Q).mu; k++) // 初始化Q的行、列头指针向量
		(*Q).rhead[k] = NULL;
	for (k = 0; k < (*Q).nu; k++) 
		(*Q).chead[k] = NULL;       

	col = (OLink*)malloc(((*Q).nu + 1) * sizeof(OLink));  //生成指向列的最后结点的数组
	if (!col)
		exit(0);
	for (k = 0; k < (*Q).nu; k++) 
		col[k] = NULL;


	for (i = 0; i < M.mu; i++) // 按行的顺序运算 
	{
		pm = M.rhead[i]; 
		pn = N.rhead[i]; 

		while (pm&&pn) // pm和pn均不空 
		{
			if (pm->j < pn->j) // 矩阵M当前结点的列小于矩阵N当前结点的列 
			{
				p = (OLink)malloc(sizeof(OLNode));
				if (!p)
					exit(0);
				(*Q).tu++; 
				p->i = i; // 生成矩阵Q的结点 
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
			
			if ((*Q).rhead[i] == NULL) // p为该行的第1个结点，pq指向p								
				(*Q).rhead[i] = pq = p;
			else // 插在pq所指结点之后 
			{
				pq->right = p; // 完成行插入 
				pq = pq->right; // pq指向该行的最后一个结点 				
			}

			if ((*Q).chead[p->j] == NULL) 
				(*Q).chead[p->j] = col[p->j] = p;// p插在该列的表头且col[p->j]指向p
			else // 插在col[p->j]所指结点之后 
			{
				col[p->j]->down = p; // 完成列插入
				col[p->j] = col[p->j]->down;
			}
		}
		while (pm) // 将矩阵M该行的剩余元素插入矩阵Q 
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

		while (pn) // 将矩阵N该行的剩余元素插入矩阵Q 
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
		if (col[k]) // k列有结点 
			col[k]->down = NULL; // 令该列最后一个结点的down指针为空 
	free(col);
	return 1;
}