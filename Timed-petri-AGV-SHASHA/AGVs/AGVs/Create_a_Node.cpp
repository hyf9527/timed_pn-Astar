#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "Crolinked_def.h"
#include "Tree.h"
#include "Create_a_Node.h"
/*
���ܣ��������Ľ��
�����±�ʶ:m' = m + C(C.chead)


*/
void Create_a_Node(Tree *Tr,int new_m[],int Transition,int delay[],int new_t_w[],int new_m_g)
{
	int i,j;
	int T_num;
	int ans;     //��ȡ�����Ǹ��м���
	int g;       //�ӳ�ʼ����ǰ��ʶ���ĵ�ʱ��
	int step = 0;//��ǰ��ʶ����һ����ʶ���ĵ�ʱ��
	int m[MaxRow];  //��ǰ������ʶ
	int w[MaxRow];//�����п��ڵ�ǰ������ʶ��,�ѵȴ���Ǩ������ʱ��
	int t[MaxRow];

	OLink p;
	OLink q;
	p = C.chead[Transition];
	q = C_pre.chead[Transition];

	for (i = 0; i < (*Tr).place_num; i++)
	{
		m[i] = new_m[i]; //��ǰ��ʶ
		
	}
	for (j = 0; j < (*Tr).transition_num; j++)
	{
		t[j] = delay[j];
		w[j] = new_t_w[j];
	}

	while(p != NULL)   //���±�ʶ����Ǩ�Ѿ�������
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
	(*Tr).current_node = (Nodelink)malloc(sizeof(Node));//�����µĽ�㣬���ַ������ǰ���
	(*Tr).last_node->next = (*Tr).current_node;         //����һ������nextָ���½��Ľ�� 
	(*Tr).last_node = (*Tr).current_node;               //ʹlastҲָ���½��Ľ�� 

	for (i = 0; i < (*Tr).place_num; i++)//���½��Ľ�㸳ֵ 
	{
		(*Tr).current_node->new_m[i] = m[i]; //�������±�ʶ�ŵ�������� 
			
	} 
	for (j = 0; j < (*Tr).transition_num; j++)
	{
		(*Tr).current_node->new_t_w[j] = w[j];
	}
	(*Tr).current_node->new_m_g = g;
	(*Tr).current_node->new_m_h_min = 100;

	(*Tr).current_node->new_m_come = ((*Tr).source_node)->new_m_num;//��ʶ����Դ�±�ŵ�������� 
	(*Tr).current_node->source = (*Tr).source_node;
	(*Tr).current_node->new_t_come = T_num;//��ʶ�����ı�Ǩ���±�ŵ�������� 
	(*Tr).current_node->new_m_num = (*Tr).node_num;
	(*Tr).current_node->next = NULL;
	(*Tr).current_node->next_open = NULL;

}
