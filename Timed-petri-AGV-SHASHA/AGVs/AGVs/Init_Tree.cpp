#include "stdio.h"
#include "stdlib.h"
#include "Tree.h"
#include "Init_Tree.h"

void Init_Tree(Tree *Tr,int place_num,int transition_num )
{
	(*Tr).head_node = (*Tr).final_node = NULL;   //��β��㸳��
	(*Tr).current_node = (*Tr).last_node = (*Tr).open_end = (*Tr).source_node = (*Tr).finish_node_end = NULL;//��ǰ��㡢��һ����㡢��չβ��㡢�����Դ��㡢ĩβ������ֹ��㸳ֵ��
	(*Tr).place_num = place_num;
	(*Tr).transition_num = transition_num;
	(*Tr).node_num = 0;
}