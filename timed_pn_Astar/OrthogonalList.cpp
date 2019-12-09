#include "OrthogonalList.h"
#include <stdlib.h> 
#include<stdio.h>
#include <string.h>

// ��ʼ��M(CrossList���͵ı��������ʼ��,���򴴽������ƾ��󽫳���) 
int InitSMatrix(CrossList *M)
{
	(*M).rhead = (*M).chead = NULL;
	(*M).mu = (*M).nu = (*M).tu = 0;
	return 1;
}


// ����ϡ�����M
int DestroySMatrix(CrossList *M)
{
	int i;
	OLNode *p, *q;

	for (i = 1; i <= (*M).mu; i++) // �����ͷŽ�� 
	{
		p = *((*M).rhead + i);
		while (p)
		{
			q = p;
			p = p->right;
			free(q);
		}
	}
	free((*M).rhead);
	free((*M).chead);
	(*M).rhead = (*M).chead = NULL;
	(*M).mu = (*M).nu = (*M).tu = 0;
	return 1;
}



void CreateSMatrix(CrossList *M, const char *path)
{
	int k;
	int NotZeroNum = 0;
	//ElemType e;
	OLNode *p, *q;
	if ((*M).rhead)
		DestroySMatrix(M);
	//��ʼ��������ͷ
	(*M).rhead = (OLink*)malloc((MaxRow) * sizeof(OLink));
	if (!(*M).rhead)
		exit(0);
	//��ʼ��������ͷ
	(*M).chead = (OLink*)malloc((MaxRow) * sizeof(OLink));
	if (!(*M).chead)
		exit(0);
	for (k = 0; k < MaxRow; k++) // ��ʼ����ͷָ������;��������Ϊ������ 
		(*M).rhead[k] = NULL;
	for (k = 0; k < MaxRow; k++) // ��ʼ����ͷָ������;��������Ϊ������ 
		(*M).chead[k] = NULL;


	int buf[MaxRow][MaxRow];
	char line[100];
	FILE * pFile;
	int irow = 0;
	int icol = 0;
	int colNum = 0;
	pFile = fopen(path, "r");
	if (pFile != NULL)
	{
		while (1)
		{
			if (fgets(line, 100, pFile) == NULL)
				break;

			// �ָ�ÿ��

			char *pch = strtok(line, " ");

			while (pch != NULL)
			{
				int val = atoi(pch);

				// �洢����
				buf[irow][icol] = val;
				if (val != 0)
				{
					p = (OLNode*)malloc(sizeof(OLNode));
					if (!p)
						exit(0);
					p->i = irow; // ���ɽ�� 
					p->j = icol;
					p->e = val;
					if ((*M).rhead[irow] == NULL || (*M).rhead[irow]->j > icol)
					{
						// p���ڸ��еĵ�һ����㴦
						p->right = (*M).rhead[irow];
						(*M).rhead[irow] = p;
					}
					else // Ѱ�����б��еĲ���λ�� 
					{
						//�Ӹ��е�������ͷ��ʼ��ֱ���ҵ�
						for (q = (*M).rhead[irow]; q->right && q->right->j < icol; q = q->right)
							;
						p->right = q->right; // ����в��� 
						q->right = p;
					}
					if ((*M).chead[icol] == NULL || (*M).chead[icol]->i > irow)
					{
						// p���ڸ��еĵ�һ����㴦
						p->down = (*M).chead[icol];
						(*M).chead[icol] = p;
					}
					else // Ѱ�����б��еĲ���λ�� 
					{
						for (q = (*M).chead[icol]; q->down && q->down->i < irow; q = q->down)
							;
						p->down = q->down; // ����в��� 
						q->down = p;
					}
					NotZeroNum++;
				}

				icol++;
				// �����ָ�
				pch = strtok(NULL, " ");
			}

			irow++;
			colNum = icol;
			icol = 0;
		}
		fclose(pFile);
	}

	(*M).mu = irow;
	(*M).nu = colNum;
	(*M).tu = NotZeroNum;
	//printf("%3d ",irow );
	//printf("%3d ",colNum );
	printf("\n");
	// ������� irow��¼ʵ��������colNum��¼ʵ������
	for (int i = 0; i < irow; i++)
	{
		for (int j = 0; j < colNum; j++)
		{
			printf("%3d ", buf[i][j]);
		}

		printf("\n");
	}
}


// ���л������ϡ�����M
int PrintSMatrix(CrossList M)
{
	int i, j;
	OLink p;
	printf("%d��%d��%d������Ԫ��\n", M.mu, M.nu, M.tu);
	printf("������ѡ��(1.������� 2.�������): ");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		for (j = 0; j < M.mu; j++)
		{
			p = M.rhead[j];
			while (p)
			{
				printf("%d��%d��ֵΪ%d\n", (p->i) + 1, (p->j) + 1, p->e);
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
				printf("%d��%d��ֵΪ%d\n", (p->i) + 1, (p->j) + 1, p->e);
				p = p->down;
			}
		}
	}
	return 1;
}


//  ��ϡ�����Ĳ�Q=M-N 
int SubtSMatrix(CrossList M, CrossList N, CrossList *Q)
{
	int i, k;
	OLink p, pq, pm, pn;
	OLink *col;

	if (M.mu != N.mu || M.nu != N.nu)
	{
		printf("����������ͬ���͵�,�������\n");
		exit(0);
	}
	(*Q).mu = M.mu; // ��ʼ��Q���� 
	(*Q).nu = M.nu;
	(*Q).tu = 0; // Ԫ�ظ����ĳ�ֵ 
	(*Q).rhead = (OLink*)malloc(((*Q).mu) * sizeof(OLink));
	if (!(*Q).rhead)
		exit(0);
	(*Q).chead = (OLink*)malloc(((*Q).nu) * sizeof(OLink));
	if (!(*Q).chead)
		exit(0);
	for (k = 0; k < (*Q).mu; k++) // ��ʼ��Q����ͷָ������;��������Ϊ������ 
		(*Q).rhead[k] = NULL;
	for (k = 0; k < (*Q).nu; k++) // ��ʼ��Q����ͷָ������;��������Ϊ������ 
		(*Q).chead[k] = NULL;
	// ����ָ���е�����������
	col = (OLink*)malloc(((*Q).nu + 1) * sizeof(OLink));
	if (!col)
		exit(0);
	for (k = 0; k < (*Q).nu; k++) // ����ֵ 
		col[k] = NULL;
	for (i = 0; i < M.mu; i++) // ���е�˳����� 
	{
		pm = M.rhead[i]; // pmָ�����M�ĵ�i�еĵ�1����� 
		pn = N.rhead[i]; // pnָ�����N�ĵ�i�еĵ�1����� 
		while (pm&&pn) // pm��pn������ 
		{
			if (pm->j < pn->j) // ����M��ǰ������С�ھ���N��ǰ������ 
			{
				p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ�� 
				if (!p)
					exit(0);
				(*Q).tu++; // ����Ԫ������1 
				p->i = i; // ����㸳ֵ 
				p->j = pm->j;
				p->e = pm->e;
				p->right = NULL;
				pm = pm->right; // pmָ�������� 
			}
			// ����M��ǰ�����д��ھ���N��ǰ������ 
			else if (pm->j > pn->j)
			{
				p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ�� 
				if (!p)
					exit(0);
				(*Q).tu++; // ����Ԫ������1 
				p->i = i; // ����㸳ֵ 
				p->j = pn->j;
				p->e = -pn->e;
				p->right = NULL;
				pn = pn->right; // pnָ�������� 
			}
			else if (pm->e - pn->e)
			{
				// ����M��N��ǰ�������������Ԫ��֮�Ϊ0 
				p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ�� 
				if (!p)
					exit(0);
				(*Q).tu++; // ����Ԫ������1 
				p->i = i; // ����㸳ֵ 
				p->j = pn->j;
				p->e = pm->e - pn->e;
				p->right = NULL;
				pm = pm->right; // pmָ�������� 
				pn = pn->right; // pnָ�������� 
			}
			else // ����M��N��ǰ�������������Ԫ��֮��Ϊ0 
			{
				pm = pm->right; // pmָ�������� 
				pn = pn->right; // pnָ�������� 
				continue;
			}
			if ((*Q).rhead[i] == NULL) // pΪ���еĵ�1����� 
				// p���ڸ��еı�ͷ��pqָ��p(���е����һ�����)
				(*Q).rhead[i] = pq = p;
			else // ����pq��ָ���֮�� 
			{
				pq->right = p; // ����в��� 
				pq = pq->right; // pqָ����е����һ����� 
			}
			if ((*Q).chead[p->j] == NULL) // pΪ���еĵ�1����� 
				// p���ڸ��еı�ͷ��col[p->j]ָ��p
				(*Q).chead[p->j] = col[p->j] = p;
			else // ����col[p->]��ָ���֮�� 
			{
				col[p->j]->down = p; // ����в���
				// col[p->j]ָ����е����һ����� 
				col[p->j] = col[p->j]->down;
			}
		}
		while (pm) // ������M���е�ʣ��Ԫ�ز������Q 
		{
			p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ�� 
			if (!p)
				exit(0);
			(*Q).tu++; // ����Ԫ������1 
			p->i = i; // ����㸳ֵ 
			p->j = pm->j;
			p->e = pm->e;
			p->right = NULL;
			pm = pm->right; // pmָ�������� 
			if ((*Q).rhead[i] == NULL) // pΪ���еĵ�1����� 
				// p���ڸ��еı�ͷ��pqָ��p(���е����һ�����)
				(*Q).rhead[i] = pq = p;
			else // ����pq��ָ���֮�� 
			{
				pq->right = p; // ����в��� 
				pq = pq->right; // pqָ����е����һ����� 
			}
			if ((*Q).chead[p->j] == NULL) // pΪ���еĵ�1�����
				// p���ڸ��еı�ͷ��col[p->j]ָ��p  
				(*Q).chead[p->j] = col[p->j] = p;
			else // ����col[p->j]��ָ���֮�� 
			{
				col[p->j]->down = p; // ����в���
				// col[p->j]ָ����е����һ����� 
				col[p->j] = col[p->j]->down;
			}
		}
		while (pn) // ������N���е�ʣ��Ԫ�ز������Q 
		{
			p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ�� 
			if (!p)
				exit(0);
			(*Q).tu++; // ����Ԫ������1 
			p->i = i; // ����㸳ֵ 
			p->j = pn->j;
			p->e = -pn->e;
			p->right = NULL;
			pn = pn->right; // pmָ�������� 
			if ((*Q).rhead[i] == NULL) // pΪ���еĵ�1����� 
				// p���ڸ��еı�ͷ��pqָ��p(���е����һ�����)
				(*Q).rhead[i] = pq = p;
			else // ����pq��ָ���֮�� 
			{
				pq->right = p; // ����в��� 
				pq = pq->right; // pqָ����е����һ����� 
			}
			if ((*Q).chead[p->j] == NULL) // pΪ���еĵ�1�����
				// p���ڸ��еı�ͷ��col[p->j]ָ��p 
				(*Q).chead[p->j] = col[p->j] = p;
			else // ����col[p->j]��ָ���֮�� 
			{
				col[p->j]->down = p; // ����в���
				// col[p->j]ָ����е����һ�����  
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