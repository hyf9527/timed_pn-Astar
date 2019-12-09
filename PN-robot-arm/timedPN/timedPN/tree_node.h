#pragma once
#define Len_node         sizeof(struct Node)


typedef struct Node
{
	int new_m_num;//新标识的下标
	int *new_m;//新具体标识
	int *new_m_x; // 此时刻库所中托肯已经等待时间
	int new_m_g; //已耗费的时间代价
	int new_m_h; //估计值
	int new_m_h_min; // 估计值最小值
	int new_m_come;//新标识的标识来源
	struct Node *source; //新标识的来源节点   
	int new_m_transition;//新标识的变迁来源
	struct Node *next_open;//下一个要扩展的标识
	struct Node *next; //下一个结点地址
	int old; //旧的标识
	struct Node *same; //首次相同的标识 
	struct Node *same_end; //末尾相同的标识 
	int old_mark;//旧的标识的下标
	int finish;  //终止扩展结点 
	struct Node *finish_node; // 首次连接终止结点
} *Nodelink;


typedef struct
{
	Node *head_Node; //指向树的第一个结点
	Node *current_node;  //当前结点
	Node *last_node;  //当前结点的上一个结点
	Node *finish_head_Node; //树的终止结点
	Node *finish_node_end; // 末尾连接终止结点
	Node *open_end;  //扩展的尾结点   
	Node *source_node; //结点的来源结点
	int  place_num;  //库所数量
	int  transition_num; //变迁数量
	int  node_num; // 树的结点个数
}Tree;   //Tree结构体
