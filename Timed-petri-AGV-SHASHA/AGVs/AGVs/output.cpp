#include <stdlib.h> 
#include<stdio.h>
#include "Tree.h"
#include "output.h"

void output(Tree *Tr)
{
	int i;
	FILE *fp;
	struct Node *p,*q;
	p = (*Tr).head_node;
	fp = fopen("out2.txt", "w+");

	printf("%s", "输出结果是");
	printf("\n");

	do
	{
		printf("m%2d的标识是", p->new_m_num);
		fprintf(fp, "m%2d的标识是", p->new_m_num);

		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", p->new_m[i]);
			fprintf(fp, "%2d\t", p->new_m[i]);
		}

		printf("%s", "已经等待的时间w是:");
		fprintf(fp, "%s", "已经等待的时间w是:");
		for (i = 0; i < (*Tr).transition_num; i++)
		{
			printf("%2d", p->new_t_w[i]);
			fprintf(fp, "%2d\t", p->new_t_w[i]);
		}

		printf("%s", "已经耗费的时间g是：");
		fprintf(fp, "%s", "已经耗费的时间g是：");
		printf("%2d", p->new_m_g);
		fprintf(fp, "%2d\t",p->new_m_g);

		printf("%s", " 标识来源于M");
		fprintf(fp, "%s", "标识来源于M");
		printf("%2d", p->new_m_come);
		fprintf(fp, "%2d\t", p->new_m_come);
		q = p->source;

		if (q == NULL)
		{
			printf("%s", "M");
			printf("%2d", 0);
		}
		else
		{
			printf("%s", " M");
			printf("%2d", q->new_m_num);
		}

		printf("%s", "激发的变迁是");
		fprintf(fp, "%s\t", "激发的变迁是");
		printf("%2d", p->new_t_come);
		fprintf(fp, "%2d\t", p->new_t_come);

		if (p->finish == 0)
		{
			printf("%s", " 它不是终止标识 NO");
			fprintf(fp, "%s", "它不是终止标识 YES");
		}
		else
		{
			printf("%s", " 它是终止标识 YES");
			fprintf(fp, "%s", "它是终止标识 YES");
		}

		if (p->old == 0)
		{
			printf("%s", " 它不是重复标识");
			fprintf(fp, "%s", "它不是重复标识");
		}
		else
		{
			printf("%s", " 它的重复标识是");
			fprintf(fp, "%s", "它的重复标识是");
			printf("%2d", p->old_m_num);
			fprintf(fp, "%2d\t", p->old_m_num);
		}
		printf("\n");
		fprintf(fp, "\n");
		p = p->next;
	} while (p != NULL);
	fclose(fp);
}


