#include <iostream>
#include "Crolinked_def.h"
#include "InitSMatrix.h"
#include "CreateSMatrix.h"
#include "PrintSMatrix.h"
#include "DestroySMatrix.h"
#include "CompuSMatrix.h"
#include "Data_read.h"
#include "Tree.h"
#include "Init_Tree.h"
#include "Init_Node.h"
#include "Is_enabled.h"
#include "Create_a_Node.h"
#include "output.h"
#include "new_or_old.h"
#include "Add_New_Node.h"
#define MaxRow 200

Crosslist C_pre, C_post;
Crosslist C;

/*
建立: C_pre,C_post;
计算: C;
可达树信息描述：m0\delay\place_num\transition_num \
*/
int main()
{
	InitSMatrix(&C_pre);
	printf("创建前置关联矩阵:\n");
	CreateSMatrix(&C_pre, "F:\\AGVs\\High-level-net\\C_pref.txt");
	PrintSMatrix(C_pre);
	printf("\n");

	InitSMatrix(&C_post);
	printf("创建后置关联矩阵:\n");
	CreateSMatrix(&C_post, "F:\\AGVs\\High-level-net\\C_postf.txt");
	PrintSMatrix(C_post);
	printf("\n");

	printf("输出关联矩阵:\n");
	CompuSMatrix(C_post, C_pre, &C);
	PrintSMatrix(C);
	printf("\n");


	int place_num = C.mu;
	int transition_num = C.nu; 
	int M0[MaxRow];
	int Delay[MaxRow];
	
	int current_mark[MaxRow];
	int current_transition_w[MaxRow];
	int current_mark_g;

	//int Transiton = 0;
	int produce_new;

	Data_read(place_num,transition_num, M0, Delay);

	
	Tree Reachable_Tree;
	Init_Tree(&Reachable_Tree,place_num,transition_num);
	Init_Node(&Reachable_Tree, M0);

	struct Node *q;
	q = Reachable_Tree.head_node;

	do
	{
		for (int i = 0; i < place_num; i++)
		{
			current_mark[i] = q->new_m[i];
			
		}
		for (int j = 0; j < transition_num; j++)
		{
			current_transition_w[j] = q->new_t_w[j];
		}
		
		current_mark_g = q->new_m_g;
		Reachable_Tree.source_node = q;

		for (int Transition = 0; Transition < transition_num; Transition++)
		{
			int is_enabled = 0;

			is_enabled = Is_enabled(current_mark, Transition);
			if (is_enabled)
			{
				Create_a_Node(&Reachable_Tree,current_mark, Transition, Delay, current_transition_w,current_mark_g);
				produce_new = new_or_old(&Reachable_Tree);
				Add_New_Node(&Reachable_Tree, produce_new);
			}
			
		}
		q = q->next_open;
	} while (q != NULL);

	output(&Reachable_Tree);
	system("pause");
	return 0;
}