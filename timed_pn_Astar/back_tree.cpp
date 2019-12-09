#include <stdlib.h> 
#include<stdio.h>
#include "tree_node.h"
#include "back_tree.h"

void back_output(Node *node, Tree *Tr)
{
	printf("m%2d的标识是", node->new_m_num);
	for (int i = 0; i < (*Tr).place_num; i++)
	{
		printf("%2d", node->new_m[i]);
	}
	printf("%s", " 已等待时间x是");
	for (int i = 0; i < (*Tr).place_num; i++)
	{
		printf("%2d", node->new_m_x[i]);
	}
	printf("%s", " 已耗费时间g为");
	printf("%2d", node->new_m_g);
	printf("%s", " 估计耗费时间h为");
	printf("%2d", node->new_m_h);
	printf("%s", " 估计最小耗费时间h为");
	printf("%2d", node->new_m_h_min);
	printf("%s", " 标识来源于M");
	printf("%2d", node->new_m_come);
	printf("%s", " 激发的变迁");
	printf("%2d", node->new_m_transition);
	if (node->finish == 0)
	{
		printf("%s", " 它不是终止标识 NO");
	}
	else
	{
		printf("%s", " 它是终止标识 YES");
	}
	if (node->old == 0)
	{
		printf("%s", " 它不是重复标识");
	}
	else
	{
		printf("%s", " 它的重复标识是");
		printf("%2d", node->old_mark);
	}
	printf("\n");
}


void node_back_open(Node *node, Tree *Tr, int time_cost)
{
	if (node !=NULL)
	{ 
		node->new_m_h = time_cost - node->new_m_g;
		if (node->new_m_h < node->new_m_h_min)
		{
			node->new_m_h_min = node->new_m_h;
		}
		//back_output(node, Tr);
		node_back_open(node->source, Tr, time_cost);
		struct Node *same_node, *source_node;
		same_node = node->same;
		while (same_node != NULL)
		{
			source_node = same_node->source;
			node_back_open(source_node,Tr,time_cost);
			same_node = same_node->same;
		}
	}
}


//判断node是否为新
int is_new(Node *node_start, Node *node, Tree *Tr)
{
	int flag, same = 1;
	struct Node *P = node_start;
	//判断是否为新
	if (node == NULL)
		return 0;
	do
	{
		for (int i = 0; i < (*Tr).place_num; i++)
		{
			if (node->new_m[i] == P->new_m[i] && node->new_m_x[i] == P->new_m_x[i])
			{
				same = 1;
			}
			else
			{
				same = 0;
				break;//标识与第i行不同则退出循环判断下一行 
			}
		}

		if (same == 1 && node->new_m_g == P->new_m_g)
		{
			flag = 0;
			break;//相同，则退出判断，并标记添加标志 
		}
		else
		{
			flag = 1;
		}
		P = P->bcak_open;
	} while (P != NULL);

	if (flag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}






void node_back_open_2(Node *node, Tree *Tr, int time_cost)
{
	struct Node *same_node, *source_node;
	struct Node *back_open_node, *back_open_node_end;
	back_open_node = back_open_node_end = node;

	do
	{
		back_open_node->new_m_h = time_cost - back_open_node->new_m_g;
		if (back_open_node->new_m_h < back_open_node->new_m_h_min)
		{
			back_open_node->new_m_h_min = back_open_node->new_m_h;
		}
		//back_output(back_open_node, Tr);
		source_node = back_open_node->source;
		//back_output(source_node, Tr);
		if (is_new(node, source_node, Tr)) //source_node在前面没有出现过
		{
			back_open_node_end->bcak_open = source_node;
			back_open_node_end = source_node;
		}
		same_node = back_open_node->same;
		while (same_node != NULL)
		{
			//back_output(same_node, Tr);
			source_node = same_node->source;
			//back_output(source_node, Tr);
			if (is_new(node, source_node, Tr)) //source_node在前面没有出现过
			{
				back_open_node_end->bcak_open = source_node;
				back_open_node_end = source_node;
			}

			same_node = same_node->same;
		}

		back_open_node = back_open_node->bcak_open;
	} while(back_open_node != NULL);
}

//销毁反向树,为生成下一棵反向树做准备
void Destroy_back_tree(Node *node, Tree *Tr)
{
	struct Node *P, *Q;
	P = node;
	while (P != NULL)
	{
		Q = P;
		P = P->bcak_open;
		Q->bcak_open = NULL;
	}
}



void back_tree(Tree *Tr)
{
	struct Node *finish_node;
	//struct Node *head_backtree;
	finish_node = Tr->finish_head_Node;
	int num = 1;
	while (finish_node != NULL)
	{
		printf("\n");
		printf("第%2d棵反向树输出", num);
		printf("\n");
		//node_back_open(finish_node, Tr, finish_node->new_m_g);
		node_back_open_2(finish_node, Tr, finish_node->new_m_g);
		Destroy_back_tree(finish_node, Tr);
		printf("第%2d棵反向树输出结束", num);
		printf("\n");
		num = num + 1;
		finish_node = finish_node->finish_node;
	}
}