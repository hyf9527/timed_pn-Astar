#include <stdlib.h> 
#include<stdio.h>
#include <string.h>
#include "tree_node.h"
#include "OrthogonalList.h"
#include "new_or_old.h"

/*
* Comments: //�ж�����ǰ��㣨formerָ��Ľ�㣩���»��Ǿ�
* Param Tree *Tr :  ��
* @Return void
*/
int new_or_old(Tree *Tr)//�ж����µĻ��Ǿɵ� 
{
	int i, Flag, same;
	same = 1;
	struct Node *P, *S;
	P = (* Tr).head_Node;
	do
	{
		for (i = 0; i < (*Tr).place_num; i++)
		{
			if ((*Tr).former->new_m[i] == P->new_m[i] && (*Tr).former->new_m_x[i] == P->new_m_x[i])//���ɵ��±�ʶ������ĵ�һ�����ı�ʶÿһλ�ж��Ƿ���ͬ����ͬΪ�棩 
			{
				same = 1;
			}
			else
			{
				same = 0;
				break;//��ʶ���i�в�ͬ���˳�ѭ���ж���һ�� 
			}
		}


		if (same == 1 && (*Tr).former->new_m_g == P->new_m_g)
		{
			Flag = 0;
			(*Tr).former->old = 1;
			(*Tr).former->same = NULL;
			(*Tr).former->same_end = NULL;
			(*Tr).former->old_mark = P->new_m_num;
			(*Tr).former->finish = 0;
			if (P->same == NULL)
			{
				P->same = (*Tr).former;
				P->same_end = (*Tr).former;
			}
			else
			{
				S = P->same_end;
				S->same = (*Tr).former;
				P->same_end = (*Tr).former;
			}
			break;//��ͬ�����˳��жϣ��������ӱ�־ 
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
		(*Tr).former->next_open = NULL;
		return 0;
	}
}

