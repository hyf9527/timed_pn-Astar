#include <stdlib.h> 
#include<stdio.h>
#include "tree_node.h"
#include "AddNewNode.h"

/*
* Comments: �ж��Ƿ�Ϊ��ֹ��չ���
* Param Tree *Tr :  ��
* @Return void
*/
void finish_node(Tree *Tr)
{
	int have_transition_fire = 0;
	int Transition, can_fire;
	for (Transition = 0; Transition < (*Tr).transition_num; Transition++)
	{
		can_fire = TransFireCondition((*Tr).former->new_m, Transition);
		if (can_fire == 1)
		{
			have_transition_fire = 1;
		}
	}
	if (have_transition_fire == 0)
	{
		(*Tr).former->finish = 1;
		(*Tr).former->finish_node = NULL;
		if ((*Tr).finish_head_Node == NULL)
		{
			(*Tr).finish_head_Node = (*Tr).former;
			(*Tr).finish_node_end = (*Tr).former;
		}
		else
		{
			(*Tr).finish_node_end->finish_node = (*Tr).former;
			(*Tr).finish_node_end = (*Tr).former;
		}

	}
	else
	{
		(*Tr).former->finish = 0;
		(*Tr).former->finish_node = NULL;
	}
}

/*
* Comments: ���½�����ӵ�open����ĩβ
* Param Tree *Tr :  ��
* Param int is_new :  ���ĵ�ǰ���Ϊ��
* @Return void
*/
void AddNewNode(Tree *Tr,int is_new)
{
	int f = 0;
	if (is_new == 1)//���±�ʶ������Ҫ����չ��һ���½ڵ� 
	{
		(*Tr).former->old = 0;
		(*Tr).former->old_mark = 0;
		finish_node(Tr);
		(*Tr).open_end->next_open = (*Tr).former;
		(*Tr).open_end = (*Tr).former;
		(*Tr).former->same = NULL;
		(*Tr).former->same_end = NULL;
	}
}
