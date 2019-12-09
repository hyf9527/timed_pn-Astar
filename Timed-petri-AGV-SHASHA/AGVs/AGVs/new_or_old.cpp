#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "Crolinked_def.h"
#include "Tree.h"
#include "new_or_old.h"

bool new_or_old(Tree *Tr)
{
	int same = 1;
	int Flag;
	struct Node *P, *Q;
	P = (*Tr).head_node;
	do {
		for (int i = 0; i < (*Tr).place_num; i++)
		{
			if ((*Tr).current_node->new_m[i] == P->new_m[i] && (*Tr).current_node->new_t_w[i] == P->new_t_w[i])
			{
				same = 1;
			}
			else
			{
				same = 0;
				break;
			}
		}
		if (same == 1 && (*Tr).current_node->new_m_g == P->new_m_g)
		{
			Flag = 0;
			(*Tr).current_node->old = 1;
			(*Tr).current_node->same = NULL;
			(*Tr).current_node->same_end = NULL;
			(*Tr).current_node->old_m_num = P->new_m_num;
			(*Tr).current_node->finish = 0;
			if (P->same == NULL)
			{
				P->same = (*Tr).current_node;
				P->same_end = (*Tr).current_node;
			}
			else
			{
				Q = P->same_end;
				Q->same = (*Tr).current_node;
				P->same_end = (*Tr).current_node;
			}
			break;
		}
		else
		{
			Flag = 1;
		}
		P = P->next_open;
	} while (P != NULL);
	if (Flag == 1)
	{
		return 1;
	}
	else
	{
		(*Tr).current_node->next_open = NULL;
		return 0;
	}
}