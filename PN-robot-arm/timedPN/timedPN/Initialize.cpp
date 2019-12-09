#include "tree_node.h"
#include <stdio.h>
#include <stdlib.h>
#include "Initialize.h"



/*
初始化树
Tree *Tr :  树
int place_num :  库所数量
int trainsition_num :  变迁数量
Return void
*/
void InitTree(Tree *Tr, int place_num, int trainsition_num)
{
	(*Tr).head_Node = (*Tr).finish_head_Node = NULL;
	(*Tr).current_node = (*Tr).last_node = (*Tr).open_end = (*Tr).source_node =(*Tr).finish_node_end  = NULL;
	(*Tr).node_num = 0;
	(*Tr).place_num = place_num;
	(*Tr).transition_num = trainsition_num;
}




/*
建立树的第一个结点
Tree *Tr :  树
int M0[] :  初始标识
Return void
*/
void InitNode(Tree *Tr, int M0[],int  place_num)
{
	//建立动态链表的第一个结点 
	(*Tr).head_Node = (*Tr).current_node = (*Tr).last_node = (Nodelink)malloc(Len_node);  //为Nodelink结构体指针分配字节为Len_node(结构体Node)的动态内存
	(*Tr).node_num = 0;

	//初始化第一个结点的数据 
	(*Tr).current_node->new_m= (int *)malloc(sizeof(int) * place_num);

	for (int i = 0; i < (*Tr).place_num; i++)//初始化第一个结点的具体标识 
	{
		(*Tr).current_node->new_m[i] = M0[i]; 
	}

	(*Tr).current_node->new_m_x = (int *)malloc(sizeof(int) * place_num);

	for (int i = 0; i < (*Tr).place_num; i++)//初始化第一个结点的具体标识的等待时间 
	{
		(*Tr).current_node->new_m_x[i] = 0;
	}

	(*Tr).current_node->new_m_num = 0;      //第一个结点的标识下标是0
	(*Tr).current_node->new_m_g = 0;
	(*Tr).current_node->new_m_h_min = 100;
	(*Tr).current_node->new_m_come = 0;     //无标识来源
	(*Tr).current_node->source = NULL;      //无来源结点
	(*Tr).current_node->new_m_transition = 0;//无变迁来源

	(*Tr).current_node->next = NULL;        //将下一个结点赋为空
	(*Tr).current_node->next_open = NULL;
	(*Tr).current_node->old = 0;
	(*Tr).current_node->same = NULL;
	(*Tr).current_node->same_end = NULL;
	(*Tr).current_node->old_mark = 0;
	(*Tr).current_node->finish = 0;
	(*Tr).current_node->finish_node = NULL;
	(*Tr).open_end = (*Tr).current_node;   //当前这个结点也是扩展尾结点
}