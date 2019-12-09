#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "Crolinked_def.h"
#include "Tree.h"
#include "Create_a_Node.h"
/*
功能：创建树的结点
产生新标识:m' = m + C(C.chead)


*/
void Create_a_Node(Tree *Tr,int new_m[],int Transition,int delay[],int new_t_w[],int new_m_g)
{
	int i,j;
	int T_num;
	int ans;     //求取步长那个中间量
	int g;       //从初始到当前标识消耗的时间
	int step = 0;//当前标识到下一个标识消耗的时间
	int m[MaxRow];  //当前库所标识
	int w[MaxRow];//定义托肯在当前库所标识下,已等待变迁激发的时间
	int t[MaxRow];

	OLink p;
	OLink q;
	p = C.chead[Transition];
	q = C_pre.chead[Transition];

	for (i = 0; i < (*Tr).place_num; i++)
	{
		m[i] = new_m[i]; //当前标识
		
	}
	for (j = 0; j < (*Tr).transition_num; j++)
	{
		t[j] = delay[j];
		w[j] = new_t_w[j];
	}

	while(p != NULL)   //更新标识（变迁已经激发）
	{
		m[p->i] = m[p->i] + (p->e);
		p = p->down;
	}
	
	while (q != NULL)
	{
		ans = delay[q->j] * (q->e) - w[q->j];
		if (ans > step)
		{
			step = ans;
		}
		q = q->down;
	}

	printf("%2d", step);
	g = step + new_m_g;

	for (j = 0; j < (*Tr).transition_num; j++)
	{
		if (delay[j] == 0)
		{
			w[j] = 0;
		}
		else
		{
			if (m[i]> )
			{
				w[j] = 0;
			}
			else
			{
				if (m[j] < new_m[j] || m[j] == new_m[j])
				{
					w[j] = 0;
				}
				else
				{
					w[j] = step + w[j];
				}
			}
		}
	}

	T_num = Transition + 1;
	(*Tr).node_num++;
	(*Tr).current_node = (Nodelink)malloc(sizeof(Node));//建立新的结点，其地址赋给当前结点
	(*Tr).last_node->next = (*Tr).current_node;         //将上一个结点的next指向新建的结点 
	(*Tr).last_node = (*Tr).current_node;               //使last也指向新建的结点 

	for (i = 0; i < (*Tr).place_num; i++)//给新建的结点赋值 
	{
		(*Tr).current_node->new_m[i] = m[i]; //产生的新标识放到输出表中 
			
	} 
	for (j = 0; j < (*Tr).transition_num; j++)
	{
		(*Tr).current_node->new_t_w[j] = w[j];
	}
	(*Tr).current_node->new_m_g = g;
	(*Tr).current_node->new_m_h_min = 100;

	(*Tr).current_node->new_m_come = ((*Tr).source_node)->new_m_num;//标识的来源下标放到输出表中 
	(*Tr).current_node->source = (*Tr).source_node;
	(*Tr).current_node->new_t_come = T_num;//标识激发的变迁的下标放到输出表中 
	(*Tr).current_node->new_m_num = (*Tr).node_num;
	(*Tr).current_node->next = NULL;
	(*Tr).current_node->next_open = NULL;

}
