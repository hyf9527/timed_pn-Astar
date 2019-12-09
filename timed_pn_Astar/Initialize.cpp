#include "tree_node.h"
#include <stdio.h>
#include <stdlib.h>
#include "Initialize.h"
#include "h_evaluate.h"


/*
* Comments: ��ʼ����
* Param Tree *Tr :  ��
* Param int place_num :  ��������
* Param int trainsition_num :  ��Ǩ����
* @Return void
*/
void InitTree(Tree *Tr, int place_num, int trainsition_num)
{
	(*Tr).head_Node = (*Tr).finish_head_Node = NULL;
	(*Tr).former = (*Tr).latter = (*Tr).open_end = (*Tr).source_come =(*Tr).finish_node_end  = NULL;
	(*Tr).Node_num = 0;
	(*Tr).place_num = place_num;
	(*Tr).transition_num = trainsition_num;
}

void InitAstarTree(AstarTree *Tr, int place_num, int trainsition_num)
{
	(*Tr).open_head = (*Tr).close_head = NULL;
	(*Tr).former = (*Tr).latter = (*Tr).open_end = (*Tr).source_come = (*Tr).close_end = NULL;
	(*Tr).Node_num = 0;
	(*Tr).place_num = place_num;
	(*Tr).transition_num = trainsition_num;
}




/*
* Comments: �������ĵ�һ�����
* Param Tree *Tr :  ��
* Param  int M0[] :  ��ʼ��ʶ
* @Return void
*/
void InitNode(Tree *Tr, int M0[])
{
	//������̬����ĵ�һ����� 
	(*Tr).head_Node = (*Tr).former = (*Tr).latter = (Nodelink)malloc(Len_node);
	(*Tr).Node_num = 0;

	//��ʼ����һ���������� 
	for (int i = 0; i < (*Tr).place_num; i++)//��ʼ����һ�����ľ����ʶ 
	{
		(*Tr).former->new_m[i] = M0[i];
	}
	for (int i = 0; i < (*Tr).place_num; i++)//��ʼ����һ�����ľ����ʶ�ĵȴ�ʱ�� 
	{
		(*Tr).former->new_m_x[i] = 0;
	}
	(*Tr).former->new_m_num = 0;
	(*Tr).former->new_m_g = 0;
	(*Tr).former->new_m_h_min = 200;
	(*Tr).former->new_m_come = 0;
	(*Tr).former->source = NULL;
	(*Tr).former->new_m_transition = 0;
	(*Tr).former->next = NULL;
	(*Tr).former->next_open = NULL;
	(*Tr).former->old = 0;
	(*Tr).former->same = NULL;
	(*Tr).former->same_end = NULL;
	(*Tr).former->old_mark = 0;
	(*Tr).former->finish = 0;
	(*Tr).former->finish_node = NULL;
	(*Tr).former->bcak_open = NULL;
	//(*Tr).former->finish_node_end = NULL;
	(*Tr).open_end = (*Tr).former;
}



void InitAstarNode(AstarTree *Tr, int M0[])
{
	//������̬����ĵ�һ����� 
	(*Tr).open_head  = (*Tr).former = (AstarNodelink)malloc(Len_Astarnode);
	(*Tr).Node_num = 0;

	//��ʼ����һ���������� 
	for (int i = 0; i < (*Tr).place_num; i++)//��ʼ����һ�����ľ����ʶ 
	{
		(*Tr).former->new_m[i] = M0[i];
	}
	for (int i = 0; i < (*Tr).place_num; i++)//��ʼ����һ�����ľ����ʶ�ĵȴ�ʱ�� 
	{
		(*Tr).former->new_m_x[i] = 0;
	}
	(*Tr).former->new_m_num = 0;
	(*Tr).former->new_m_g = 0;
	(*Tr).former->new_m_come = 0;
	(*Tr).former->new_m_h = h_eval(Tr);
	(*Tr).former->source = NULL;
	(*Tr).former->open_next = NULL;
	(*Tr).former->close_next = NULL;
	(*Tr).former->new_m_transition = 0;
	(*Tr).open_end = (*Tr).former;
}