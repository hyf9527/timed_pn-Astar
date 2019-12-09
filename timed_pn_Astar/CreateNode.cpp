#include<stdio.h>
#include <stdlib.h>
#include "tree_node.h"
#include "OrthogonalList.h"
#include "CreateNode.h"
#include "h_evaluate.h"
/*
* Comments: �ڣ�new_m,new_m_x,new_m_g���£���ǨTransition�����������µĽ��
* Param Tree *Tr :  ��
* Param int Transition :  ������Ǩ
* Param  int Delay[] : ��ʱʱ��
* Param  int new_m[] : ��ʶ
* Param  int new_m_x[] : �ѵȴ�ʱ��
* Param  int new_m_g : �Ѻķѵ�ʱ�����
* @Return void
*/
void CreateNode(Tree *Tr, int Transition, int Delay[], int new_m[], int new_m_x[], int new_m_g)
{
	int T_num, i;
	int m[MaxRow];
	int x[MaxRow];
	int ans, step, g;  //step��ʾ��ǰ��ʶ����һ��ʶ�����ʱ�� 
	step = 0;
	OLink P, Q;
	P = SMatrix_C.chead[Transition];
	Q = SMatrix_C_pre.chead[Transition];
	for (i = 0; i < (*Tr).place_num; i++)
	{
		m[i] = new_m[i];
		x[i] = new_m_x[i];
	}

	while (P != NULL)//����m 
	{
		m[P->i] = m[P->i] + (P->e);
		P = P->down;
	}

	while (Q != NULL) //����step 
	{
		ans = Delay[Q->i] * (Q->e) - x[Q->i];
		if (ans > step)
			step = ans;
		Q = Q->down;
	}
	//printf("%2d", step);
	g = new_m_g + step;
	for (i = 0; i < (*Tr).place_num; i++) //���½�㴦��x 
	{
		if (Delay[i] == 0)
		{
			x[i] = 0;
		}
		else
		{
			if (m[i] == 0)
			{
				x[i] = 0;
			}
			else
			{
				if (new_m[i] == 0)
				{
					x[i] = 0;
				}
				else
				{
					x[i] = x[i] + step;
				}
			}
		}
	}
	T_num = Transition + 1;
	(*Tr).Node_num++;//����Ľڵ�����һ 
	(*Tr).former = (Nodelink)malloc(Len_node);//�����µĽ�㣬���ַ����former 
	(*Tr).latter->next = (*Tr).former;//����һ������nextָ���½��Ľ�� 
	(*Tr).latter = (*Tr).former;//ʹlatterҲָ���½��Ľ�� 
	for (i = 0; i < (*Tr).place_num; i++)//���½��Ľ�㸳ֵ 
	{
		(*Tr).former->new_m[i] = m[i]; //�������±�ʶ�ŵ�������� 
		(*Tr).former->new_m_x[i] = x[i];
	}
	(*Tr).former->new_m_g = g;
	(*Tr).former->new_m_h_min = 200;
	(*Tr).former->new_m_come = ((*Tr).source_come)->new_m_num;//��ʶ����Դ�±�ŵ�������� 
	(*Tr).former->source = (*Tr).source_come;
	(*Tr).former->new_m_transition = T_num;//��ʶ�����ı�Ǩ���±�ŵ�������� 
	(*Tr).former->new_m_num = (*Tr).Node_num;
	(*Tr).former->next = NULL;
	(*Tr).former->next_open = NULL;
	(*Tr).former->bcak_open = NULL;
	(*Tr).former->same = NULL;
	(*Tr).former->same_end = NULL;
}



void CreateAstarNode(AstarTree *Tr, int Transition, int Delay[], int new_m[], int new_m_x[], int new_m_g)
{
	int T_num, i;
	int m[MaxRow];
	int x[MaxRow];
	int ans, step, g;  //step��ʾ��ǰ��ʶ����һ��ʶ�����ʱ�� 
	step = 0;
	OLink P, Q;
	P = SMatrix_C.chead[Transition];
	Q = SMatrix_C_pre.chead[Transition];
	for (i = 0; i < (*Tr).place_num; i++)
	{
		m[i] = new_m[i];
		x[i] = new_m_x[i];
	}

	while (P != NULL)//����m 
	{
		m[P->i] = m[P->i] + (P->e);
		P = P->down;
	}

	while (Q != NULL) //����step 
	{
		ans = Delay[Q->i] * (Q->e) - x[Q->i];
		if (ans > step)
			step = ans;
		Q = Q->down;
	}
	//printf("%2d", step);
	g = new_m_g + step;
	for (i = 0; i < (*Tr).place_num; i++) //���½�㴦��x 
	{
		if (Delay[i] == 0)
		{
			x[i] = 0;
		}
		else
		{
			if (m[i] == 0)
			{
				x[i] = 0;
			}
			else
			{
				if (new_m[i] == 0)
				{
					x[i] = 0;
				}
				else
				{
					x[i] = x[i] + step;
				}
			}
		}
	}

	//�ж����ɵĽ����open���еıȽϣ��Ƿ�Ϊ��
	int flag, same = 1;
	struct AstarNode *P_open = (*Tr).open_head;
	do
	{
		for (int i = 0; i < (*Tr).place_num; i++)
		{
			if (m[i] == P_open->new_m[i] && x[i] == P_open->new_m_x[i])
			{
				same = 1;
			}
			else
			{
				same = 0;
				break;//��ʶ���i�в�ͬ���˳�ѭ���ж���һ�� 
			}
		}

		if (same == 1 && g == P_open->new_m_g)
		{
			flag = 0;
			break;//��ͬ�����˳��жϣ��������ӱ�־ 
		}
		else
		{
			flag = 1;
		}
		P_open = P_open->open_next;
	} while (P_open != NULL);


	if (flag == 1)
	{
		T_num = Transition + 1;
		(*Tr).Node_num++;//����Ľڵ�����һ 
		(*Tr).former = (AstarNodelink)malloc(Len_Astarnode);//�����µĽ�㣬���ַ����former 
		if ((*Tr).close_head == NULL)
		{
			(*Tr).close_head = (*Tr).close_end = (*Tr).latter = (*Tr).former;
		}
		else
		{
			(*Tr).latter->close_next = (*Tr).former;//����һ������nextָ���½��Ľ�� 
			(*Tr).close_end = (*Tr).latter = (*Tr).former;//ʹlatterҲָ���½��Ľ�� 
		}
		for (i = 0; i < (*Tr).place_num; i++)//���½��Ľ�㸳ֵ 
		{
			(*Tr).former->new_m[i] = m[i]; //�������±�ʶ�ŵ�������� 
			(*Tr).former->new_m_x[i] = x[i];
		}
		(*Tr).former->new_m_g = g;
		(*Tr).former->new_m_h = h_eval(Tr);
		(*Tr).former->new_m_come = ((*Tr).source_come)->new_m_num;//��ʶ����Դ�±�ŵ�������� 
		(*Tr).former->source = (*Tr).source_come;
		(*Tr).former->new_m_transition = T_num;//��ʶ�����ı�Ǩ���±�ŵ�������� 
		(*Tr).former->new_m_num = (*Tr).Node_num;
		(*Tr).former->open_next = NULL;
		(*Tr).former->close_next = NULL;
	}

}