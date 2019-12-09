#include <stdlib.h> 
#include<stdio.h>
#include <string.h>
#include "tree_node.h"
#include "Completecrosslinkedlist .h"
#include "new_or_old.h"

/*
判断树当前结点（former指向的结点）是新还是旧
Tree *Tr :  树
Return void
*/ //&& (*Tr).current_node->new_m_x[i] == P->new_m_x[i]    (*Tr).current_node->new_m_g == P->new_m_g 
bool new_or_old(Tree *Tr)//判断是新的还是旧的 
{
	int i, Flag;
	int same = 1,a=1;
	struct Node *P, *S;
	P = (* Tr).head_Node;
	do
	{
		for (i = 0; i < (*Tr).place_num; i++)
		{
			if ((*Tr).current_node->new_m[i] == P->new_m[i])//生成的新标识与链表的第一个结点的标识每一位判断是否相同（相同为真） 
			{
				same = 1;
			}
			else
			{
				same = 0;
				break;//标识与第i行不同则退出循环判断下一行 
			}
		}
		if (same == 1)
		{
			for (i = 0; i < 27; i++)
			{
				if ((*Tr).current_node->new_m_x[i] == P->new_m_x[i] || (*Tr).current_node->new_m_x[i] - P->new_m_x[i] >= 10)
				{
					a = 1;
				}
				else
				{
					a = 0;
					break;
				}
			}
		}
		if (same == 1 &&((*Tr).current_node->new_m_g - P->new_m_g >=10 || (*Tr).current_node->new_m_g == P->new_m_g) &&a==1)
		{
			Flag = 0;
			(*Tr).current_node->old = 1;
			(*Tr).current_node->same = NULL;
			(*Tr).current_node->same_end = NULL;
			(*Tr).current_node->old_mark = P->new_m_num;
			(*Tr).current_node->finish = 0;
			if (P->same == NULL)
			{
				P->same = (*Tr).current_node;
				P->same_end = (*Tr).current_node;
			}
			else
			{
				S = P->same_end;
				S->same = (*Tr).current_node;
				P->same_end = (*Tr).current_node;
			}
			break;//相同，则退出判断，并标记添加标志 
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

