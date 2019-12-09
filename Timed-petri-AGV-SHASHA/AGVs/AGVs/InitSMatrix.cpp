#include "InitSMatrix.h"
#include "Crolinked_def.h"
#include <stdlib.h> 
#include<stdio.h>
#include <string.h>
int InitSMatrix(Crosslist *M)
{
	(*M).mu = (*M).nu = (*M).tu = 0;
	(*M).rhead = (*M).chead = NULL;
	return 0;
}
