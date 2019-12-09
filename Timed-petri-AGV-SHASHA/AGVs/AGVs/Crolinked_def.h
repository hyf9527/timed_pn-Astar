#pragma once


typedef int Element;
typedef struct OLNode
{
	int i, j;//非零元素对应的行列下标
	Element e;//非零元素值
	struct OLNode *right, *down;//该非零元素所在行列之后的链域
}OLNode, *OLink;

typedef struct
{
	int mu, nu, tu; //稀疏矩阵行数、列数、非零元个数
	OLink *rhead;
	OLink *chead; //rhead、chead的类型：是指向指针OLink的指针，即指向定义的OLNode结点的指针的指针，存放的是：指针的地址
}Crosslist;