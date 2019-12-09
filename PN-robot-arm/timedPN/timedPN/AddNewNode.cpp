#include <stdlib.h> 
#include<stdio.h>
#include "tree_node.h"
#include "AddNewNode.h"

/*
判断是否为终止扩展结点
Tree *Tr :  树
Return void
*/
//extern int place_num;

void finish_node(Tree *Tr)
{
	int have_enabled = 0;
	int Transition, is_enabled;
	for (Transition = 0; Transition < (*Tr).transition_num; Transition++)
	{
		
		is_enabled = Is_enabled((*Tr).current_node->new_m, Transition);
		if (is_enabled == 1)
		{
			have_enabled = 1;
		}
	}
	if (have_enabled == 0)
	{
		(*Tr).current_node->finish = 1;
		(*Tr).current_node->finish_node = NULL;
		if ((*Tr).finish_head_Node == NULL)
		{
			(*Tr).finish_head_Node = (*Tr).current_node;
			(*Tr).finish_node_end = (*Tr).current_node;
		}
		else
		{
			(*Tr).finish_node_end->finish_node = (*Tr).current_node;
			(*Tr).finish_node_end = (*Tr).current_node;
		}
	}
	else
	{
		(*Tr).current_node->finish = 0;
		(*Tr).current_node->finish_node = NULL;
	}
}

/*
将新结点连接到open链的末尾
Tree *Tr :  树
int produce_new :  树的当前结点为新
Return void
*/
void AddNewNode(Tree *Tr,int produce_new)
{
	if (produce_new == 1)//是新标识，则需要将扩展下一个新节点 
	{
		(*Tr).current_node->old = 0;
		(*Tr).current_node->old_mark = 0;
		finish_node(Tr);
		(*Tr).open_end->next_open = (*Tr).current_node;
		(*Tr).open_end = (*Tr).current_node;
		(*Tr).current_node->same = NULL;
		(*Tr).current_node->same_end = NULL;
	}
}
