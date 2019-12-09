#pragma once
#define MaxRow  200        //�������������

typedef int ElemType;
typedef struct OLNode
{
	int i, j;    // �÷���Ԫ���к����±� 
	ElemType e;    // ����Ԫ��ֵ 
	struct OLNode *right, *down; // �÷���Ԫ�����б���б�ĺ������ 
}OLNode, *OLink;


typedef struct// �к�������ͷָ��������ַ,��CreatSMatrix_OL()����
{
	OLink *rhead, *chead;
	int mu, nu, tu;        // ϡ�����������������ͷ���Ԫ���� 
}CrossList;


int InitSMatrix(CrossList *M);    // ��ʼ��M(CrossList���͵ı��������ʼ��,���򴴽������ƾ��󽫳���) 
int DestroySMatrix(CrossList *M);    // ����ϡ�����M
void CreateSMatrix(CrossList *M, const char *path);     // ����ʮ������洢��ʾ
int PrintSMatrix(CrossList M);  // ���л������ϡ�����M
int SubtSMatrix(CrossList M, CrossList N, CrossList *Q); //  ��ϡ�����Ĳ�Q=M-N 
