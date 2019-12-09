#pragma once
#define MaxRow 200

/*
结点具体信息
*/
typedef struct Node
{
	int new_m[MaxRow];
	int new_m_num;
	
	int new_t_w[MaxRow];//变迁激发前已经等待的时间
	int t_fire;//在当前标识下，满足可激发的变迁条件
	int new_m_g;

	int new_m_come;//新标识的标识来源
	int new_t_come;//新标识的变迁来源

	int new_m_h;
	int new_m_h_min;

	int old;   
	int old_m_num;

	int finish;

	struct Node *source;   //新标识来源结点
	struct Node *next_open;//下一个要扩展的标识
	struct Node *next;     //下一个结点的地址

	struct Node *same;
	struct Node *same_end;
	struct Node *finish_node;

}Node,*Nodelink;

/*
树的定义
*/

typedef struct 
{
	int place_num;
	int transition_num;
	int node_num;
	Node *head_node;
	Node *current_node;
	Node *last_node;
	Node *final_node;      //树的终止结点
	Node *open_end;        //扩展尾结点
	Node *finish_node_end; // 末尾连接终止结点
	Node *source_node;
}Tree;