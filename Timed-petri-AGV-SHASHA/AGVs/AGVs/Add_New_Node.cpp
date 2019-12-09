#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "Crolinked_def.h"
#include "Tree.h"
#include "Add_New_Node.h"
#include "Is_enabled.h"

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
		if ((*Tr).final_node == NULL)
		{
			(*Tr).final_node = (*Tr).current_node;
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
void Add_New_Node(Tree *Tr, int produce_new)
{
	if (produce_new == 1)//是新标识，则需要将扩展下一个新节点 
	{
		(*Tr).current_node->old = 0;
		(*Tr).current_node->old_m_num = 0;
		finish_node(Tr);
		(*Tr).open_end->next_open = (*Tr).current_node;
		(*Tr).open_end = (*Tr).current_node;
		(*Tr).current_node->same = NULL;
		(*Tr).current_node->same_end = NULL;
	}
}