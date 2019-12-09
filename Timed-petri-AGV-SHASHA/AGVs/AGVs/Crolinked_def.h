#pragma once


typedef int Element;
typedef struct OLNode
{
	int i, j;//����Ԫ�ض�Ӧ�������±�
	Element e;//����Ԫ��ֵ
	struct OLNode *right, *down;//�÷���Ԫ����������֮�������
}OLNode, *OLink;

typedef struct
{
	int mu, nu, tu; //ϡ���������������������Ԫ����
	OLink *rhead;
	OLink *chead; //rhead��chead�����ͣ���ָ��ָ��OLink��ָ�룬��ָ�����OLNode����ָ���ָ�룬��ŵ��ǣ�ָ��ĵ�ַ
}Crosslist;