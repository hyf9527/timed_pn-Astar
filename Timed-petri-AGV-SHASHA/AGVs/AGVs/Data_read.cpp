#include<stdio.h>
#include "Crolinked_def.h"
#include "Data_read.h"

/*
功能：读取m0.txt、delay.txt；

Return void;
*/

void Data_read(int place_num, int transition_num, int m0[], int delay[])
{
	FILE *fp;
	fp = fopen(M0_path, "r");
	if (fp == NULL)
	{
		printf("cannot open this file!\n");
	}

	printf("初始标识m0: \n");
	for (int i = 0; i < place_num; i++)
	{
		fscanf(fp, "%2d", &m0[i]);
		printf("%2d", m0[i]);
	}
	fclose(fp);
	printf("\n");

	fp = fopen(Delay_path, "r");
	if (fp == NULL)
	{
		printf("cannot open this file!\n");
	}

	printf("赋时时间delay:\n");
	for (int i = 0; i < transition_num; i++)
	{
		fscanf(fp, "%2d", &delay[i]);
		printf("%2d", delay[i]);
	}
	fclose(fp);
	printf("\n");
}