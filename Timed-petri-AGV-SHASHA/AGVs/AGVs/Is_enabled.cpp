
#include "Crolinked_def.h"
#include "Is_enabled.h"

/*
��Ǩ��μ��� m > = C_pre[]
*/
bool Is_enabled(int current_m[], int transition)
{
	OLink p;
	p = C_pre.chead[transition];
	
	while (p)
	{
		if (current_m[p->i] > p->e || current_m[p->i] == p->e)
		{
			p = p->down;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}