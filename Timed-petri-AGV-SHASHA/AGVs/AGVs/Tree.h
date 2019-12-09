#pragma once
#define MaxRow 200

/*
��������Ϣ
*/
typedef struct Node
{
	int new_m[MaxRow];
	int new_m_num;
	
	int new_t_w[MaxRow];//��Ǩ����ǰ�Ѿ��ȴ���ʱ��
	int t_fire;//�ڵ�ǰ��ʶ�£�����ɼ����ı�Ǩ����
	int new_m_g;

	int new_m_come;//�±�ʶ�ı�ʶ��Դ
	int new_t_come;//�±�ʶ�ı�Ǩ��Դ

	int new_m_h;
	int new_m_h_min;

	int old;   
	int old_m_num;

	int finish;

	struct Node *source;   //�±�ʶ��Դ���
	struct Node *next_open;//��һ��Ҫ��չ�ı�ʶ
	struct Node *next;     //��һ�����ĵ�ַ

	struct Node *same;
	struct Node *same_end;
	struct Node *finish_node;

}Node,*Nodelink;

/*
���Ķ���
*/

typedef struct 
{
	int place_num;
	int transition_num;
	int node_num;
	Node *head_node;
	Node *current_node;
	Node *last_node;
	Node *final_node;      //������ֹ���
	Node *open_end;        //��չβ���
	Node *finish_node_end; // ĩβ������ֹ���
	Node *source_node;
}Tree;