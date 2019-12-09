#pragma once
#ifdef MaxRow
#else
#define MaxRow 200
#endif // MaxRow
#define Len_node         sizeof(struct Node)
#define Len_Astarnode         sizeof(struct AstarNode)



////////// ��ȫ����������ģ����������
typedef struct Node
{
	int new_m_num;//�±�ʶ���±�
	int new_m[MaxRow]; //�±�ʶ�ľ����ʶ
	int new_m_x[MaxRow]; // ��ʱ�̿������п��Ѿ��ȴ�ʱ��
	int new_m_g; //�Ѻķѵ�ʱ�����
	int new_m_h; //����ֵ
	int new_m_h_min; // ����ֵ��Сֵ
	int new_m_come;//�±�ʶ�ı�ʶ��Դ
	struct Node *source; //�±�ʶ����Դ�ڵ� 
	int new_m_transition;//�±�ʶ�ı�Ǩ��Դ
	struct Node *next_open;//��һ��Ҫ��չ�ı�ʶ
	struct Node *next; //��һ������ַ
	int old; //�ɵı�ʶ
	struct Node *same; //�״���ͬ�ı�ʶ 
	struct Node *same_end; //ĩβ��ͬ�ı�ʶ 
	int old_mark;//�ɵı�ʶ���±�
	int finish;  //��ֹ��չ��� 
	struct Node *finish_node; // �״�������ֹ���
	struct Node *bcak_open; //������չ
	//struct Node *finish_node_end; // ĩβ������ֹ���
} *Nodelink;



typedef struct
{
	Node *head_Node; //ָ�����ĵ�һ�����
	Node *former;  //��ǰ���
	Node *latter;  //��ǰ������һ�����
	Node *finish_head_Node; //������ֹ���
	Node *finish_node_end; // ĩβ������ֹ��� 
	Node *open_end;  //��չ��β���
	Node *source_come; //������Դ���
	int  place_num;  //��������
	int  transition_num; //��Ǩ����
	int  Node_num; // ���Ľ�����
}Tree;



/////////A*�㷨�ֲ���������������ʽ����h��ѵ��ģ������
typedef struct AstarNode
{
	int new_m_num;//�±�ʶ���±�
	int new_m[MaxRow]; //�±�ʶ�ľ����ʶ
	int new_m_x[MaxRow]; // ��ʱ�̿������п��Ѿ��ȴ�ʱ��
	int new_m_g; //�Ѻķѵ�ʱ�����
	float new_m_h; //����ֵ
	int new_m_come;//�±�ʶ�ı�ʶ��Դ
	struct AstarNode *source; //�±�ʶ����Դ�ڵ� 
	int new_m_transition;//�±�ʶ�ı�Ǩ��Դ
	struct AstarNode *open_next;// ����open��
	struct AstarNode *close_next; //  ����close��
} *AstarNodelink;



typedef struct
{
	AstarNode *open_head; //ָ��open��ĵ�һ�����
	AstarNode *close_head;  //ָ��close��ĵ�һ�����
	AstarNode *former;  //��ǰ���close
	AstarNode *latter;  //��ǰ������һ�����close
	AstarNode *open_end;  //open���β���
	AstarNode *close_end;  //close���β�ڵ�
	AstarNode *source_come; //������Դ���
	int  place_num;  //��������
	int  transition_num; //��Ǩ����
	int  Node_num; // ���Ľ�����
}AstarTree;
