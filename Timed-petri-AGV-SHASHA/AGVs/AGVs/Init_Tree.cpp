#include "stdio.h"
#include "stdlib.h"
#include "Tree.h"
#include "Init_Tree.h"

void Init_Tree(Tree *Tr,int place_num,int transition_num )
{
	(*Tr).head_node = (*Tr).final_node = NULL;   //首尾结点赋空
	(*Tr).current_node = (*Tr).last_node = (*Tr).open_end = (*Tr).source_node = (*Tr).finish_node_end = NULL;//当前结点、上一个结点、扩展尾结点、结点来源结点、末尾连接终止结点赋值空
	(*Tr).place_num = place_num;
	(*Tr).transition_num = transition_num;
	(*Tr).node_num = 0;
}