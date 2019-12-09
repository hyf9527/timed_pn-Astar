#include "OrthogonalList.h"
#include "TransFireCondition.h"

/*
* Comments: �ж��ڱ�ʶm�£���Ǩt�Ƿ���Լ���
* Param CrossList SMatrix_C_pre :  ǰ�ù�������
* Param int new_m[] :  ��ʶ
* Param  int Transition : ��Ǩ
* @Return int  0��ʾ�ڱ�ʶnew_m�±�ǨTransition���ܼ�����1��֮
*/
int TransFireCondition( int new_m[], int Transition)
{
	int flag = 1;
	int a;
	OLink p;
	//	for(j=0;j<SMatrix_C_pre.nu;j++)
	p = SMatrix_C_pre.chead[Transition];
	while (p)
	{
		a = p->e;
		if (new_m[p->i] > a || new_m[p->i] == a)
		{
			p = p->down;
		}
		else
		{
			flag = 0;
			break;
		}
	}

	if (flag == 0)
	{

		return 0;
	}
	else
	{
		return 1;
	}
}