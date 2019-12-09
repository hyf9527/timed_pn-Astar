#include "Completecrosslinkedlist .h"
#include <stdlib.h> 
#include<stdio.h>
#include <string.h>


/*
初始化M(Crosslist数据类型变量必须进行初始化)
否则创建、复制矩阵有错)
*/
int InitSMatrix(CrossList *M)
{
	(*M).rhead = (*M).chead = NULL;
	(*M).mu = (*M).nu = (*M).tu = 0;
	return 1;
}


/*销毁稀疏矩阵
  Crosslist *M:结构体指针;
  可以指向结构体里面的变量成员：mu/nu/tu/rhead/chead
  (*)M.mu = = M->mu
  释放行列头指针的地址内存空间，使得这块内存重获自由
  释放内存后，进行头列指针以及行列数、非零元个数的的初始化
*/
int DestroySMatrix(CrossList *M)
{
	int i;
	OLNode *p, *q;//指针作用：指向结点(元素)地址

	for (i = 1; i <= (*M).mu; i++) // 按行释放结点 
	{
		p = *((*M).rhead + i);//矩阵第i行头指针地址
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



/*
创建CreateSMatrix函数：建立稀疏矩阵并使用十字链表的方式存储矩阵
  需要用户输入数据,输入正确值之后，需要创建头指针的数组(*M).rhead
  (*M).chead
*/

void CreateSMatrix(CrossList *M, const char *path)
{
	int k,i;
	int NotZeroNum = 0;
	OLNode *p, *q;//指向OLNode类型的指针p、q
	if ((*M).rhead)//判断稀疏矩阵的行列头指针是否为空
		DestroySMatrix(M);
	/*
	创建行、列头指针的数组
	OLink*:指针类型，连续创建MaxRow个，每一个都指向OLink类型的变量
	它里面存放的是一个指向OLNode类型的指针地址
	*/
	(*M).rhead = (OLink*)malloc(sizeof(OLink));
	if (!(*M).rhead)
		exit(0);
	(*M).chead = (OLink*)malloc(sizeof(OLink));
	if (!(*M).chead)
		exit(0);
	/*创建结束，行列链表头必须初始化：
	后面的插入过程的其中一个判断条件就是它们的值为NULL，即该行或是该列没有结点
	*/
	
		(*M).rhead[0] = NULL;
		(*M).chead[0] = NULL;

	/*初始化后，建立一个缓冲矩阵，最大行列数(存储的是所有元素值，包括零元素)，并进行初始化*/
	int **buf=NULL;
	char line[100];
	FILE * pFile;
	int irow = 0;
	int icol = 0;
	int colNum = 0;

	buf = (int **)malloc(sizeof(int*));
	buf[0] = (int *)malloc(sizeof(int));
	//buf[0] = NULL;




	/*如何进行读取数据*/
	pFile = fopen(path, "r");
	if (pFile != NULL)
	{
		while (1)
		{
			if (fgets(line, 300, pFile) == NULL) 
				break;

			/*分割每行*/
			char *pch = strtok(line, "	");//如果不是空，则使用strtok函数按照空格符划分，放在一个字符型指针

			while (pch != NULL)
			{
				int val = atoi(pch);

				/*存储数据,将所有元素都放在缓冲矩阵里*/
				buf[irow][icol] = val;
				if (val != 0)
				{
					p = (OLNode*)malloc(sizeof(OLNode));
					if (!p)
						exit(0);
					/* 生成结点*/
					p->i = irow;
					p->j = icol;
					p->e = val;
					/*printf("i:%d", p->i);
					printf("j:%d", p->j);
					printf("e:%d", p->e);
					printf("\n");*/

					/*生成结点后，要考虑一下行头指针如何与第一个不为0的元素链接起来
					 判断行头指针、列头指针选择插入的情况：
					 情况一：如果这一行中没有结点，选择直接插入
					 情况二：如果这一行中有结点，选择插入到正确的位置
					 如何判断有无结点：之前对（*M）.rhead/(*M).chead进行初始化，所有元素值均为NULL；
					 判断条件：(*M).rhead[i] == NULL;
					*/
					
						if ((*M).rhead[irow] == NULL)
						{
							//p插在该行的第一个结点处
							p->right = (*M).rhead[irow];  //将行有指针的空赋给第一个结点的right
							(*M).rhead[irow] = p;         //将p的地址告诉行头指针，指向右边的第一个结点
				
						}
						else // 寻查在行表中的插入位置 
						{
							//从该行的行链表头开始，直到找到
							q = (*M).rhead[irow];
							p->right = q->right; // 完成行插入 
							q->right = p;
						}

						if ((*M).chead[icol] == NULL )
						{
							// p插在该列的第一个结点处
							p->down = (*M).chead[icol];
							(*M).chead[icol] = p;
						}
						else // 寻查在列表中的插入位置 
						{
							q = (*M).chead[icol];
							p->down = q->down=NULL; // 完成列插入 
							q->down = p;
						}
					
					NotZeroNum++;
				}

				icol++;
				buf[irow] = (int *)realloc(buf[irow], sizeof(int) * (icol + 1));
				if (irow == 0)
				{
					(*M).chead = (OLink*)realloc((*M).chead,(icol + 1) * sizeof(OLink));
					(*M).chead[icol] = NULL;

				}

				// 继续分割
				pch = strtok(NULL, "	");
			}

			irow++;

			(*M).rhead = (OLink*)realloc((*M).rhead, (irow + 1) * sizeof(OLink));
			(*M).rhead[irow] = NULL;
			buf = (int **)realloc(buf, sizeof(int*) * (irow + 1));
			buf[irow]= (int *)malloc(sizeof(int));


			colNum = icol;
			icol = 0;
		}
		fclose(pFile);
	}

	(*M).mu = irow;
	(*M).nu = colNum;
	(*M).tu = NotZeroNum;
	printf("\n");
	/* 输出数据 irow记录实际行数，colNum记录实际列数*/
	for (int i = 0; i < irow; i++)
	{
		for (int j = 0; j < colNum; j++)
		{
			printf("%3d ", buf[i][j]);
		}
		printf("\n");
	}
}


/*按行或按列输出稀疏矩阵M*/
int OutputSMatrix(CrossList M)
{
	int i, j;
	OLink p;
	printf("%d行%d列%d个非零元素\n", M.mu, M.nu, M.tu);
	printf("请输入选择(1.按行输出 2.按列输出): ");
	scanf("%d", &i);
	switch (i)
	{
	case 1://选择按行输出
		for (j = 0; j < M.mu; j++)
		{
			p = M.rhead[j];
			while (p)
			{
				printf("%d行%d列值为%d\n", (p->i), (p->j), p->e);
				p = p->right;
			}
		}
		break;
	case 2://选择按列输出
		for (j = 0; j < M.nu; j++)
		{
			p = M.chead[j];
			while (p)
			{
				printf("%d行%d列值为%d\n", (p->i), (p->j), p->e);
				p = p->down;
			}
		}
	}
	return 1;
}


/*
初始条件：稀疏矩阵M和N的行数列数对应相等
操作结果：求稀疏矩阵的差Q = M - N
*/
int CompuSMatrix(CrossList M, CrossList N, CrossList *Q)
{
	int i, k;
	OLink p, pq, pm, pn; //作为中间结点指针
	OLink *col;//指向列指针

	if (M.mu != N.mu || M.nu != N.nu)
	{
		printf("两个矩阵不是同类型的,不能相加\n");
		exit(0);
	}
	(*Q).mu = M.mu; // 初始化Q矩阵 
	(*Q).nu = M.nu;
	(*Q).tu = 0; 
	(*Q).rhead = (OLink*)malloc(((*Q).mu) * sizeof(OLink));//为Q矩阵分配内存
	if (!(*Q).rhead)
		exit(0);
	(*Q).chead = (OLink*)malloc(((*Q).nu) * sizeof(OLink));
	if (!(*Q).chead)
		exit(0);
	for (k = 0; k < (*Q).mu; k++) // 初始化Q的行头指针向量;各行链表为空链表 
		(*Q).rhead[k] = NULL;
	for (k = 0; k < (*Q).nu; k++) // 初始化Q的列头指针向量;各列链表为空链表 
		(*Q).chead[k] = NULL;
	// 生成指向列的最后结点的数组
	col = (OLink*)malloc(((*Q).nu + 1) * sizeof(OLink));
	if (!col)
		exit(0);
	for (k = 0; k < (*Q).nu; k++) // 赋初值 
		col[k] = NULL;
	for (i = 0; i < (*Q).mu; i++) // 按行的顺序相加 
	{
		pm = M.rhead[i]; // pm指向矩阵M的第i行的第1个结点 
		pn = N.rhead[i]; // pn指向矩阵N的第i行的第1个结点 
		while (pm&&pn) // pm和pn均不空 
		{
			if (pm->j < pn->j) // 矩阵M当前结点的列小于矩阵N当前结点的列 
			{
				p = (OLink)malloc(sizeof(OLNode)); // 生成矩阵Q的结点 
				if (!p)
					exit(0);
				(*Q).tu++; // 非零元素数加1 
				p->i = i; // 给结点赋值 
				p->j = pm->j;
				p->e = pm->e;
				p->right = NULL;
				pm = pm->right; // pm指针向右移 
			}
			// 矩阵M当前结点的列大于矩阵N当前结点的列 
			else if (pm->j > pn->j)
			{
				p = (OLink)malloc(sizeof(OLNode)); // 生成矩阵Q的结点 
				if (!p)
					exit(0);
				(*Q).tu++; // 非零元素数加1 
				p->i = i; // 给结点赋值 
				p->j = pn->j;
				p->e = -pn->e;
				p->right = NULL;
				pn = pn->right; // pn指针向右移 
			}
			else if (pm->e - pn->e)
			{
				// 矩阵M、N当前结点的列相等且两元素之差不为0 
				p = (OLink)malloc(sizeof(OLNode)); // 生成矩阵Q的结点 
				if (!p)
					exit(0);
				(*Q).tu++; // 非零元素数加1 
				p->i = i; // 给结点赋值 
				p->j = pn->j;
				p->e = pm->e - pn->e;
				p->right = NULL;
				pm = pm->right; // pm指针向右移 
				pn = pn->right; // pn指针向右移 
			}
			else // 矩阵M、N当前结点的列相等且两元素之差为0 
			{
				pm = pm->right; // pm指针向右移 
				pn = pn->right; // pn指针向右移 
				continue;
			}
			if ((*Q).rhead[i] == NULL) // p为该行的第1个结点 
				// p插在该行的表头且pq指向p(该行的最后一个结点)
				(*Q).rhead[i] = pq = p;
			else // 插在pq所指结点之后 
			{
				pq->right = p; // 完成行插入 
				pq = pq->right; // pq指向该行的最后一个结点 
			}
			if ((*Q).chead[p->j] == NULL) // p为该列的第1个结点 
				// p插在该列的表头且col[p->j]指向p
				(*Q).chead[p->j] = col[p->j] = p;
			else // 插在col[p->]所指结点之后 
			{
				col[p->j]->down = p; // 完成列插入
				// col[p->j]指向该列的最后一个结点 
				col[p->j] = col[p->j]->down;
			}
		}
		while (pm) // 将矩阵M该行的剩余元素插入矩阵Q 
		{
			p = (OLink)malloc(sizeof(OLNode)); // 生成矩阵Q的结点 
			if (!p)
				exit(0);
			(*Q).tu++; // 非零元素数加1 
			p->i = i; // 给结点赋值 
			p->j = pm->j;
			p->e = pm->e;
			p->right = NULL;
			pm = pm->right; // pm指针向右移 
			if ((*Q).rhead[i] == NULL) // p为该行的第1个结点 
				// p插在该行的表头且pq指向p(该行的最后一个结点)
				(*Q).rhead[i] = pq = p;
			else // 插在pq所指结点之后 
			{
				pq->right = p; // 完成行插入 
				pq = pq->right; // pq指向该行的最后一个结点 
			}
			if ((*Q).chead[p->j] == NULL) // p为该列的第1个结点
				// p插在该列的表头且col[p->j]指向p  
				(*Q).chead[p->j] = col[p->j] = p;
			else // 插在col[p->j]所指结点之后 
			{
				col[p->j]->down = p; // 完成列插入
				// col[p->j]指向该列的最后一个结点 
				col[p->j] = col[p->j]->down;
			}
		}
		while (pn) // 将矩阵N该行的剩余元素插入矩阵Q 
		{
			p = (OLink)malloc(sizeof(OLNode)); // 生成矩阵Q的结点 
			if (!p)
				exit(0);
			(*Q).tu++; // 非零元素数加1 
			p->i = i; // 给结点赋值 
			p->j = pn->j;
			p->e = -pn->e;
			p->right = NULL;
			pn = pn->right; // pm指针向右移 
			if ((*Q).rhead[i] == NULL) // p为该行的第1个结点 
				// p插在该行的表头且pq指向p(该行的最后一个结点)
				(*Q).rhead[i] = pq = p;
			else // 插在pq所指结点之后 
			{
				pq->right = p; // 完成行插入 
				pq = pq->right; // pq指向该行的最后一个结点 
			}
			if ((*Q).chead[p->j] == NULL) // p为该列的第1个结点
				// p插在该列的表头且col[p->j]指向p 
				(*Q).chead[p->j] = col[p->j] = p;
			else // 插在col[p->j]所指结点之后 
			{
				col[p->j]->down = p; // 完成列插入
				// col[p->j]指向该列的最后一个结点  
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