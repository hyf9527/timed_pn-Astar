#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "Tree.h"
#include "Init_Node.h"

/*
初始化：建立树的第一个结点，即m0
*/

void Init_Node(Tree *Tr, int m0[])
{
	(*Tr).head_node = (*Tr).current_node = (*Tr).last_node = (Nodelink)malloc(sizeof(Node)); //建立动态链表的第一个结点
	(*Tr).node_num = 0;

	for (int i = 0; i < (*Tr).place_num; i++)                                               //初始化第一个结点的数据信息（具体标识）
	{
		(*Tr).current_node->new_m[i] = m0[i];
	}

	for (int i = 0; i < (*Tr).transition_num; i++)                                          //初始化第一个结点的具体标识的等待时间（w[k]）
	{		
		(*Tr).current_node->new_t_w[i] = 0;
	}

	(*Tr).current_node->new_m_num = 0;
	(*Tr).current_node->new_m_g = 0;
	(*Tr).current_node->new_m_come = 0;
	(*Tr).current_node->new_t_come = NULL;
	(*Tr).current_node->old = 0;
	(*Tr).current_node->old_m_num = 0;
	(*Tr).current_node->finish = 0;
	
	(*Tr).current_node->source = (*Tr).current_node->next_open = (*Tr).current_node->next = NULL;
	(*Tr).current_node->same = (*Tr).current_node->same_end = NULL;

	(*Tr).open_end = (*Tr).current_node;
}

