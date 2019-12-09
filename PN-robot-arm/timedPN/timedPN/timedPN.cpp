#include "Completecrosslinkedlist .h"
#include <iostream>
#include "tree_node.h"
#include "data_read.h"
#include "Is_enabled.h"
#include "AddNewNode.h"
#include "Initialize.h"
#include "new_or_old.h"
#include "CreateNode.h"
#include"output.h"
#include"back_tree.h"



CrossList C_pre, C_post;
CrossList C;

/*
结构体定义：用户输入稀疏矩阵的行数、列数、非零元的个数;
需要定义一个Crosslist的结构体变量来存储这些值;
初始化
创建前置关联矩阵;输出C_pre的十字链表；
创建后置关联矩阵：输出C_post的十字链表；
计算C = C_post-C_pre:输出C的十字链表；
*/
int main()
{
	InitSMatrix(&C_pre);
	printf("创建前置关联矩阵C_pre: ");
	CreateSMatrix(&C_pre, "E:\\PN-robot-arm\\pre.txt");
	OutputSMatrix(C_pre);
	printf("\n");

	InitSMatrix(&C_post);
	printf("创建后置关联矩阵C_post: ");
	CreateSMatrix(&C_post, "E:\\PN-robot-arm\\post.txt");
	OutputSMatrix(C_post);
	printf("\n");

	CompuSMatrix(C_post, C_pre, &C);
	printf("关联矩阵SMatrix_C: ");
	OutputSMatrix(C);  
	printf("\n");	

	int place_num = C.mu;      //库所数量
	int transition_num = C.nu; //变迁数量
	int *current_mark= (int *)malloc(sizeof(int) * place_num); //当前标识	
	int *current_mark_x = (int *)malloc(sizeof(int) * place_num); //当前标识	,库所中托肯已经等待时间
	int current_mark_g; // 当前标识下已耗费的时间 

	int *M0 = (int *)malloc(sizeof(int) * place_num);           //初始标识
	int *Delay = (int *)malloc(sizeof(int) * place_num);           //赋时时间
	int produce_new;          //产生新标识
	int new_mark_g; // 当前标识下已耗费的时间 

	data_read(place_num, M0, Delay);
	int count = 0;

	Tree ReachableTree;
	InitTree(&ReachableTree, place_num, transition_num);
	InitNode(&ReachableTree, M0, place_num);
	struct Node *s;
	s = ReachableTree.head_Node;  //指向树的第一个结点的地址赋给指针s
	do
	{
		//printf("current_mark:");
		for (int j = 0; j < place_num; j++)
		{
			current_mark[j] = s->new_m[j];    //将新表中第j行的标识赋值给当前的标识
//			printf("%d", current_mark[j]);
			current_mark_x[j] = s->new_m_x[j];
			

		}
		//printf("\n");

		current_mark_g = s->new_m_g;				//已耗费时间更新
		ReachableTree.source_node = s;   //当前标识的信息成为了下一个结点的来源结点
		for (int Transition = 0; Transition < transition_num; Transition++)
		{
			int is_enabled = 0;
			is_enabled = Is_enabled(current_mark, Transition);
			if (is_enabled)
			{
				CreateNode(&ReachableTree, Transition, current_mark, place_num, Delay, current_mark_x, current_mark_g); 
				produce_new = new_or_old(&ReachableTree);
				AddNewNode(&ReachableTree, produce_new);
			
			}
		}
		s = s->next_open;
	} while (s != NULL);
	output1(&ReachableTree);
	//output2(&ReachableTree);
	/*back_tree(&ReachableTree);
	out(&ReachableTree);*/


}