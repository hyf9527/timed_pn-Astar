
#include "Heuristic_methon.h"

void link_delete_num(AstarTree *Tr, AstarNode *Node_min)
{
	struct AstarNode *P, *D;
	P = (*Tr).close_head;
	D = NULL;
	if (P == NULL)//����Ϊ������
	{
		printf("����Ϊ��\n");
		return;
	}
	while (P->new_m_num != Node_min->new_m_num && P->close_next != NULL)//ѭ������Ҫɾ���Ľڵ�   
	{
		D = P;
		P = P->close_next;
	}
	if (P->new_m_num == Node_min->new_m_num)//�ҵ���һ���ڵ��num��num���
	{
		if (P == (*Tr).close_head) //�ҵ��Ľڵ���ͷ�ڵ�  
		{
			(*Tr).close_head = P->close_next;
		}
		else if(P == (*Tr).close_end)//�ҵ��Ľڵ���β�ڵ�   �ѵ����ڶ����ڵ��close_next��ΪNULL   close_end ���ӵ�ǰ������� 
		{
			D->close_next = P->close_next;
			(*Tr).close_end = D;
		}
		else //      ���ϸ�����close_next��ΪNULL
		{
			D->close_next = P->close_next;
		}
		(*Tr).former = (*Tr).latter = (*Tr).close_end;
		/*free(P);*/
	}
	else//û���ҵ�����Ҫɾ���Ľڵ�
	{
		printf("û���ҵ���Ҫɾ���Ľڵ�\n");
	}
}







void select_openNode(AstarTree *Tr) //��close����ѡ��g+h��С����չ���
{
	float min_val, val;
	//int n = 0;
	//int n_min = -1;
	min_val = 10000;
	struct AstarNode *P, *Q;
	P = (*Tr).close_head;
	if (P == NULL)//����Ϊ������
	{
		printf("����Ϊ��\n");
		return;
	}
	Q  =  NULL;
	do
	{
		val = P->new_m_g + P->new_m_h;
		if (val < min_val)
		{
			Q = P;
			min_val = val;
			//n_min = n;
		}
		P = P->close_next;
		//n += 1;
	} while (P != NULL);

	(*Tr).open_end->open_next = Q;
	(*Tr).open_end = Q;
	link_delete_num(Tr, Q);
}