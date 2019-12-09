
#include "Completecrosslinkedlist .h"
#include "Is_enabled.h"

/*
 判断在当前标识下，变迁Transition是否可以激发
 CrossList SMatrix_C_pre :  前置关联矩阵 
 int current_m[] :  标识
 int Transition : 变迁
 Return ：int  0表示在标识current_m[]下变迁Transition不能激发，1则可以
*/
bool Is_enabled(int current_m[], int Transition)
{
	OLink p;
	p = C_pre.chead[Transition]; 
	while (p)
	{
		if (current_m[p->i] > p->e || current_m[p->i] == p->e)
		{
			p = p->down;
		}
		else
		{
			return  0;			
		}
	}
	return 1;

}