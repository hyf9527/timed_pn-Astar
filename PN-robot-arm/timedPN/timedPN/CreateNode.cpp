#include<stdio.h>
#include <stdlib.h>
#include "tree_node.h"
#include "Completecrosslinkedlist .h"
#include "CreateNode.h"

/*
在current_m[]下，变迁Transition激发，生成新的结点
Tree *Tr :  树
int Transition :  激发变迁
int new_m[] : 标识
Return void
*/

void CreateNode(Tree *Tr, int Transition, int current_m[],int place_num,int Delay[],int new_m_x[], int new_m_g)
{
	int T_num, i,ans,step=0,g;
	int *m = (int *)malloc(sizeof(int) * place_num);
	int *x = (int *)malloc(sizeof(int) * place_num);
	OLink P,Q;
	P = C.chead[Transition];
	Q = C_pre.chead[Transition];
	for (i = 0; i < (*Tr).place_num; i++)
	{
		x[i] = new_m_x[i];
		m[i] = current_m[i];
	}
	
	while (P != NULL)//更新标识
	{
		/*printf("m[%d]", P->i);*/
		m[P->i] = m[P->i] + (P->e);
		/*printf("%d", m[P->i]);*/
		P = P->down;
	}
	//printf("\n");
	while (Q != NULL) //更新step 
	{
		ans = Delay[Q->i] * (Q->e) - x[Q->i];                //损耗时间=赋时时间*前置值-已等待时间      
		if (ans > step)                //与0做比较
			step = ans;
		Q = Q->down;
	}
	printf("%2d", step);//step表示当前标识到下一标识的损耗时间
	g = new_m_g + step;                                      //已耗费代价+损耗代价
	for (i = 0; i < (*Tr).place_num; i++) //更新结点处的x     更新已等待时间
	{
		if (Delay[i] == 0)
		{
			x[i] = 0;
		}
		else
		{
			if (m[i] == 0)
			{
				x[i] = 0;
			}
			else
			{
				if (current_m[i] == 0)
				{
					x[i] = 0;
				}
				else
				{
					x[i] = x[i] + step;
				}
			}
		}
	}

	T_num = Transition + 1;
	(*Tr).node_num++;//链表的结点数加一 
	(*Tr).current_node = (Nodelink)malloc(Len_node);//建立新的结点，其地址赋给当前结点
	(*Tr).last_node->next = (*Tr).current_node;//将上一个结点的next指向新建的结点 
	(*Tr).last_node = (*Tr).current_node;//使latter也指向新建的结点 	
	(*Tr).current_node->new_m = (int *)malloc(sizeof(int) * place_num);
	(*Tr).current_node->new_m_x = (int *)malloc(sizeof(int) * place_num);
	for (i = 0; i < (*Tr).place_num; i++)//给新建的结点赋值 
	{
		(*Tr).current_node->new_m[i] = m[i]; //产生的新标识放到输出表中 
		(*Tr).current_node->new_m_x[i] = x[i];
	}
	(*Tr).current_node->new_m_g = g;
	(*Tr).current_node->new_m_h_min = 100;
	(*Tr).current_node->new_m_come = ((*Tr).source_node)->new_m_num;//标识的来源下标放到输出表中 
	(*Tr).current_node->source = (*Tr).source_node;
	(*Tr).current_node->new_m_transition = T_num;//标识激发的变迁的下标放到输出表中 
	(*Tr).current_node->new_m_num = (*Tr).node_num;
	(*Tr).current_node->next = NULL;
	(*Tr).current_node->next_open = NULL;
}

