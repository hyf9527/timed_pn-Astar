#include <stdlib.h> 
#include<stdio.h>
#include "tree_node.h"
#include"output.h"

void output1(Tree *Tr)
{
	int i;
	FILE *fp;
	struct Node *P, *Q;
	P = (*Tr).head_Node;
	fp = fopen("C:\\Users\\A237\\Desktop\\PN\\timed-PN(1)\\timed-PN\\out1.txt", "w+");
	printf("%s", "输出结果");
	printf("\n");
	do
	{
		//fprintf(fp, "%2d\t", P->new_m_num);
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m[i]);
			fprintf(fp, "%2d\t", P->new_m[i]);
		}

		//printf("%s", " 已等待时间x是");
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m_x[i]);
			fprintf(fp, "%2d\t", P->new_m_x[i]);
		}
		fprintf(fp, "%2d\t", P->new_m_come);// 标识来源于M	
		fprintf(fp, "%2d\t", P->new_m_transition);
		if (P->old == 0)
		{
			fprintf(fp, "%2d\n", -1);
		}
		else
		{
			fprintf(fp, "%2d\n", P->old_mark); 
		}
	
		
		

		/*fprintf(fp, "m%2d的标识是 ", P->new_m_num);
		printf("m%2d的标识是", P->new_m_num);
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m[i]);
			fprintf(fp, "%2d\t", P->new_m[i]);
		}

		printf("%s", " 已等待时间x是");
		fprintf(fp, "%s", " 已等待时间x是");
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m_x[i]);
			fprintf(fp, "%2d\t", P->new_m_x[i]);
		}
		printf("%s", " 已耗费时间g为");
		fprintf(fp, "%s", " 已耗费时间g为");
		printf("%2d", P->new_m_g);
		fprintf(fp, "%2d\t", P->new_m_g);
		printf("%s", " 标识来源于M");
		fprintf(fp, "%s", " 标识来源于M");
		printf("%2d", P->new_m_come);
		Q = P->source;
		if (Q == NULL)
		{
			printf("%s", " M");
			printf("%2d", 0);
		}
		else
		{
			printf("%s", " M");
			printf("%2d", Q->new_m_num);
		}
		fprintf(fp, "%2d\t", P->new_m_come);
		printf("%s", " 激发的变迁");
		fprintf(fp, "%s\t", " 激发的变迁");
		printf("%2d", P->new_m_transition);
		fprintf(fp, "%2d\t", P->new_m_transition);

		if (P->finish == 0)
		{
			printf("%s", " 它不是终止标识 NO");
			fprintf(fp, "%s", " 它不是终止标识 NO");
		}
		else
		{
			printf("%s", " 它是终止标识 YES");
			fprintf(fp, "%s", " 它是终止标识 YES");
		}


		if (P->old == 0)
		{
			printf("%s", " 它不是重复标识");
			fprintf(fp, "%s", " 它不是重复标识");
		}
		else
		{
			printf("%s", " 它的重复标识是");
			fprintf(fp, "%s", " 它的重复标识是");
			printf("%2d", P->old_mark);
			fprintf(fp, "%2d\t", P->old_mark);*/
		//}
		//fprintf(fp, "\n");
		printf("\n");
		P = P->next;
	} while (P != NULL);
	fclose(fp);
}

void output2(Tree *Tr)
{
	int i;
	FILE *fp;
	struct Node *P, *Q;
	P = (*Tr).head_Node;
	fp = fopen("C:\\Users\\A237\\Desktop\\PN\\timed-PN(1)\\timed-PN\\out2.txt", "w+");
	printf("%s", "输出结果");
	printf("\n");
	do
	{
		////fprintf(fp, "%2d\t", P->new_m_num);
		//for (i = 0; i < (*Tr).place_num; i++)
		//{
		//	printf("%2d", P->new_m[i]);
		//	fprintf(fp, "%2d\t", P->new_m[i]);
		//}

		////printf("%s", " 已等待时间x是");
		//for (i = 0; i < (*Tr).place_num; i++)
		//{
		//	printf("%2d", P->new_m_x[i]);
		//	fprintf(fp, "%2d\t", P->new_m_x[i]);
		//}
		//fprintf(fp, "%2d\t", P->new_m_come);// 标识来源于M	
		//fprintf(fp, "%2d\t", P->new_m_transition);
		//if (P->old == 0)
		//{
		//	fprintf(fp, "%2d\n", -1);
		//}
		//else
		//{
		//	fprintf(fp, "%2d\n", P->old_mark); 
		//}

		//


		fprintf(fp, "m%2d的标识是 ", P->new_m_num);
		printf("m%2d的标识是", P->new_m_num);
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m[i]);
			fprintf(fp, "%2d\t", P->new_m[i]);
		}

		printf("%s", " 已等待时间x是");
		fprintf(fp, "%s", " 已等待时间x是");
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m_x[i]);
			fprintf(fp, "%2d\t", P->new_m_x[i]);
		}
		printf("%s", " 已耗费时间g为");
		fprintf(fp, "%s", " 已耗费时间g为");
		printf("%2d", P->new_m_g);
		fprintf(fp, "%2d\t", P->new_m_g);
		printf("%s", " 标识来源于M");
		fprintf(fp, "%s", " 标识来源于M");
		printf("%2d", P->new_m_come);
		Q = P->source;
		if (Q == NULL)
		{
			printf("%s", " M");
			printf("%2d", 0);
		}
		else
		{
			printf("%s", " M");
			printf("%2d", Q->new_m_num);
		}
		fprintf(fp, "%2d\t", P->new_m_come);
		printf("%s", " 激发的变迁");
		fprintf(fp, "%s\t", " 激发的变迁");
		printf("%2d", P->new_m_transition);
		fprintf(fp, "%2d\t", P->new_m_transition);

		if (P->finish == 0)
		{
			printf("%s", " 它不是终止标识 NO");
			fprintf(fp, "%s", " 它不是终止标识 NO");
		}
		else
		{
			printf("%s", " 它是终止标识 YES");
			fprintf(fp, "%s", " 它是终止标识 YES");
		}


		if (P->old == 0)
		{
			printf("%s", " 它不是重复标识");
			fprintf(fp, "%s", " 它不是重复标识");
		}
		else
		{
			printf("%s", " 它的重复标识是");
			fprintf(fp, "%s", " 它的重复标识是");
			printf("%2d", P->old_mark);
			fprintf(fp, "%2d\t", P->old_mark);
		}
		fprintf(fp, "\n");
		printf("\n");
		P = P->next;
	} while (P != NULL);
	fclose(fp);
}

void out(Tree *Tr)
{
	int i;
	int flag;
	FILE *fp;
	struct Node *P, *Q;
	P = (*Tr).head_Node;
	fp = fopen("C:\\Users\\A237\\Desktop\\PN\\timed-PN(1)\\timed-PN\\backout1.txt", "w+");
	printf("%s", "输出结果");
	printf("\n");
	do
	{
		fprintf(fp, "m%2d的标识是", P->new_m_num);
		printf("m%2d的标识是", P->new_m_num);
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m[i]);
			fprintf(fp, "%2d\t", P->new_m[i]);
		}

		printf("%s", " 已等待时间x是");
		fprintf(fp, "%s", " 已等待时间x是");
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m_x[i]);
			fprintf(fp, "%2d\t", P->new_m_x[i]);
		}
		//for(i=0;i<place_num;i++)
		//{
		//	printf("%2d",P->new_m_flag[i]);
		//	fprintf(fp,"%2d\t",P->new_m_flag[i]);
		//}
		printf("%s", " 已耗费时间g为");
		fprintf(fp, "%s", " 已耗费时间g为");
		printf("%2d", P->new_m_g);
		fprintf(fp, "%2d\t", P->new_m_g);
		printf("%s", " 估计耗费时间h为");
		printf("%2d", P->new_m_h);
		printf("%s", " 估计最小耗费时间h为");
		printf("%2d", P->new_m_h_min);
		printf("%s", " 标识来源于M");
		fprintf(fp, "%s", " 标识来源于M");
		printf("%2d", P->new_m_come);
		Q = P->source;
		if (Q == NULL)
		{
			printf("%s", " M");
			printf("%2d", 0);
		}
		else
		{
			printf("%s", " M");
			printf("%2d", Q->new_m_num);
		}
		fprintf(fp, "%2d\t", P->new_m_come);
		printf("%s", " 激发的变迁");
		fprintf(fp, "%s\t", " 激发的变迁");
		printf("%2d", P->new_m_transition);
		fprintf(fp, "%2d\t", P->new_m_transition);

		if (P->finish == 0)
		{
			printf("%s", " 它不是终止标识 NO");
			fprintf(fp, "%s", " 它不是终止标识 NO");
		}
		else
		{
			printf("%s", " 它是终止标识 YES");
			fprintf(fp, "%s", " 它是终止标识 YES");
		}


		if (P->old == 0)
		{
			printf("%s", " 它不是重复标识");
			fprintf(fp, "%s", " 它不是重复标识");
		}
		else
		{
			printf("%s", " 它的重复标识是");
			fprintf(fp, "%s", " 它的重复标识是");
			printf("%2d", P->old_mark);
			fprintf(fp, "%2d\t", P->old_mark);
		}
		fprintf(fp, "\n");
		printf("\n");
		P = P->next_open;
	} while (P != NULL);
	fclose(fp);
}
