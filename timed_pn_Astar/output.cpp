#include <stdlib.h> 
#include<stdio.h>
#include "tree_node.h"
#include"output.h"

void out_put(Tree *Tr)
{
	int i;
	int flag;
	FILE *fp;
	struct Node *P, *Q;
	P = (*Tr).head_Node;
	fp = fopen("data/out9.txt", "w+");
	printf("%s", "������");
	printf("\n");
	do
	{
		fprintf(fp, "m%2d�ı�ʶ��", P->new_m_num);
		printf("m%2d�ı�ʶ��", P->new_m_num);
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m[i]);
			fprintf(fp, "%2d\t", P->new_m[i]);
		}

		printf("%s", " �ѵȴ�ʱ��x��");
		fprintf(fp, "%s", " �ѵȴ�ʱ��x��");
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
		printf("%s", " �Ѻķ�ʱ��gΪ");
		fprintf(fp, "%s", " �Ѻķ�ʱ��gΪ");
		printf("%2d", P->new_m_g);
		fprintf(fp, "%2d\t", P->new_m_g);
		printf("%s", " ��ʶ��Դ��M");
		fprintf(fp, "%s", " ��ʶ��Դ��M");
		//printf("%2d", P->new_m_come);
		Q = P->source;
		if (Q == NULL)
		{
			//printf("%s", " M");
			printf("%2d", 0);
			fprintf(fp, "%2d\t", 0);
		}
		else
		{
			//printf("%s", " M");
			printf("%2d", Q->new_m_num);
			fprintf(fp, "%2d\t", Q->new_m_num);
		}
		//fprintf(fp, "%2d\t", P->new_m_come);
		printf("%s", " �����ı�Ǩ");
		fprintf(fp, "%s\t", " �����ı�Ǩ");
		printf("%2d", P->new_m_transition);
		fprintf(fp, "%2d\t", P->new_m_transition);

		if (P->finish == 0)
		{
			printf("%s", " ��������ֹ��ʶ NO");
			fprintf(fp, "%s", " ��������ֹ��ʶ NO");
		}
		else
		{
			printf("%s", " ������ֹ��ʶ YES");
			fprintf(fp, "%s", " ������ֹ��ʶ YES");
		}


		if (P->old == 0)
		{
			printf("%s", " �������ظ���ʶ");
			fprintf(fp, "%s", " �������ظ���ʶ");
		}
		else
		{
			printf("%s", " �����ظ���ʶ��");
			fprintf(fp, "%s", " �����ظ���ʶ��");
			printf("%2d", P->old_mark);
			fprintf(fp, "%2d\t", P->old_mark);
		}
		printf("\n");
		fprintf(fp, "\n");
		//printf("\n");
		P = P->next;
	} while (P != NULL);
	fclose(fp);
}

void out_put_viz(Tree *Tr)
{
	int i;
	int flag;
	FILE *fp;
	struct Node *P, *Q;
	P = (*Tr).head_Node;
	fp = fopen("data/out_viz9.txt", "w+");
	do
	{
		fprintf(fp, "%2d\t", P->new_m_num);
		for (i = 0; i < (*Tr).place_num; i++)
		{
			fprintf(fp, "%2d\t", P->new_m[i]);
		}

		for (i = 0; i < (*Tr).place_num; i++)
		{
			fprintf(fp, "%2d\t", P->new_m_x[i]);
		}
		fprintf(fp, "%2d\t", P->new_m_g);
		Q = P->source;
		if (Q == NULL)
		{
			fprintf(fp, "%2d\t", 0);
		}
		else
		{
			fprintf(fp, "%2d\t", Q->new_m_num);
		}

		fprintf(fp, "%2d\t", P->new_m_transition);

		if (P->finish == 0)
		{
			fprintf(fp, "%2d\t", -1);
		}
		else
		{
			fprintf(fp, "%2d\t", 1);
		}


		if (P->old == 0)
		{
			fprintf(fp, "%2d\t",-1);
		}
		else
		{
			//fprintf(fp, "%2d\t", 1);
			fprintf(fp, "%2d\t", P->old_mark);
		}
		fprintf(fp, "\n");
		//printf("\n");
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
	fp = fopen("data/backout9.txt", "w+");
	printf("%s", "������");
	printf("\n");
	do
	{
		fprintf(fp, "m%2d�ı�ʶ��", P->new_m_num);
		printf("m%2d�ı�ʶ��", P->new_m_num);
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m[i]);
			fprintf(fp, "%2d\t", P->new_m[i]);
		}

		printf("%s", " �ѵȴ�ʱ��x��");
		fprintf(fp, "%s", " �ѵȴ�ʱ��x��");
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
		printf("%s", " �Ѻķ�ʱ��gΪ");
		fprintf(fp, "%s", " �Ѻķ�ʱ��gΪ");
		printf("%2d", P->new_m_g);
		fprintf(fp, "%2d\t", P->new_m_g);
		printf("%s", " ���ƺķ�ʱ��hΪ");
		fprintf(fp, "%s", " ���ƺķ�ʱ��hΪ");
		printf("%2d", P->new_m_h);
		fprintf(fp, "%2d\t", P->new_m_h);
		printf("%s", " ������С�ķ�ʱ��hΪ");
		fprintf(fp,"%s", " ������С�ķ�ʱ��hΪ");
		printf("%2d", P->new_m_h_min);
		fprintf(fp, "%2d\t", P->new_m_h_min);
		printf("%s", " ��ʶ��Դ��M");
		fprintf(fp, "%s", " ��ʶ��Դ��M");
		//printf("%2d", P->new_m_come);
		Q = P->source;
		if (Q == NULL)
		{
			//printf("%s", " M");
			printf("%2d", 0);
			fprintf(fp, "%2d\t", 0);
		}
		else
		{
			//printf("%s", " M");
			printf("%2d", Q->new_m_num);
			fprintf(fp, "%2d\t", Q->new_m_num);
		}
		//fprintf(fp, "%2d\t", P->new_m_come);
		printf("%s", " �����ı�Ǩ");
		fprintf(fp, "%s\t", " �����ı�Ǩ");
		printf("%2d", P->new_m_transition);
		fprintf(fp, "%2d\t", P->new_m_transition);

		if (P->finish == 0)
		{
			printf("%s", " ��������ֹ��ʶ NO");
			fprintf(fp, "%s", " ��������ֹ��ʶ NO");
		}
		else
		{
			printf("%s", " ������ֹ��ʶ YES");
			fprintf(fp, "%s", " ������ֹ��ʶ YES");
		}


		if (P->old == 0)
		{
			printf("%s", " �������ظ���ʶ");
			fprintf(fp, "%s", " �������ظ���ʶ");
		}
		else
		{
			printf("%s", " �����ظ���ʶ��");
			fprintf(fp, "%s", " �����ظ���ʶ��");
			printf("%2d", P->old_mark);
			fprintf(fp, "%2d\t", P->old_mark);
		}
		fprintf(fp, "\n");
		printf("\n");
		P = P->next_open;
	} while (P != NULL);
	fclose(fp);
}


void data_process(Tree *Tr)
{
	int i;
	int flag;
	FILE *fp;
	struct Node *P, *Q;
	P = (*Tr).head_Node;
	fp = fopen("data_process/backout9.txt", "w+");
	//fprintf(fp, "%s", "M\t��ʶ\t�ѵȴ�ʱ��X\t�Ѻķ�ʱ��g\t���ƺķ�ʱ��h\t������С�ķ�ʱ��h\t��ʶ��Դ\t�����ı�Ǩ\t��ֹ��ʶ\t�ظ���ʶ");
	//fprintf(fp, "\n");
	do
	{
		fprintf(fp, "%2d\t", P->new_m_num);
		for (i = 0; i < (*Tr).place_num; i++)
		{
			fprintf(fp, "%2d", P->new_m[i]);
		}
		fprintf(fp, "\t");
		for (i = 0; i < (*Tr).place_num; i++)
		{
			fprintf(fp, "%2d", P->new_m_x[i]);
		}
		fprintf(fp, "\t");
		//for(i=0;i<place_num;i++)
		//{
		//	printf("%2d",P->new_m_flag[i]);
		//	fprintf(fp,"%2d\t",P->new_m_flag[i]);
		//}
		//printf("%s", " �Ѻķ�ʱ��gΪ");
		//fprintf(fp, "%s", " �Ѻķ�ʱ��gΪ");
		//printf("%2d", P->new_m_g);
		fprintf(fp, "%2d\t", P->new_m_g);
		//printf("%s", " ���ƺķ�ʱ��hΪ");
		//fprintf(fp, "%s", " ���ƺķ�ʱ��hΪ");
		//printf("%2d", P->new_m_h);
		fprintf(fp, "%2d\t", P->new_m_h);
		//printf("%s", " ������С�ķ�ʱ��hΪ");
		//fprintf(fp, "%s", " ������С�ķ�ʱ��hΪ");
		//printf("%2d", P->new_m_h_min);
		fprintf(fp, "%2d\t", P->new_m_h_min);
		//printf("%s", " ��ʶ��Դ��M");
		//fprintf(fp, "%s", " ��ʶ��Դ��M");
		//printf("%2d", P->new_m_come);
		Q = P->source;
		if (Q == NULL)
		{
			//printf("%s", " M");
			//printf("%2d", 0);
			fprintf(fp, "%2d\t", 0);
		}
		else
		{
			//printf("%s", " M");
			//printf("%2d", Q->new_m_num);
			fprintf(fp, "%2d\t", Q->new_m_num);
		}
		//fprintf(fp, "%2d\t", P->new_m_come);
		//printf("%s", " �����ı�Ǩ");
		//fprintf(fp, "%s\t", " �����ı�Ǩ");
		//printf("%2d", P->new_m_transition);
		fprintf(fp, "%2d\t", P->new_m_transition);

		if (P->finish == 0)
		{
			//printf("%s", " ��������ֹ��ʶ NO");
			fprintf(fp, "%2d\t", -1);
		}
		else
		{
			//printf("%s", " ������ֹ��ʶ YES");
			fprintf(fp, "%2d\t", 1);
		}


		if (P->old == 0)
		{
			//printf("%s", " �������ظ���ʶ");
			fprintf(fp, "%2d\t", -1);
		}
		else
		{
			//printf("%s", " �����ظ���ʶ��");
			fprintf(fp, "%2d\t", 1);
			//printf("%2d", P->old_mark);
			fprintf(fp, "%2d", P->old_mark);
		}
		fprintf(fp, "\n");
		P = P->next_open;
	} while (P != NULL);
	fclose(fp);
}





void Astardata_process(AstarTree *Tr)
{
	int i;
	int flag;
	FILE *fp;
	struct AstarNode *P;
	P = (*Tr).former;
	//remove("users.txt");
	fp = fopen("A_data/1.txt", "w+");
	fprintf(fp, "%2d\t", P->new_m_num);
	for (i = 0; i < (*Tr).place_num; i++)
	{
		fprintf(fp, "%2d", P->new_m[i]);
	}
	fprintf(fp, "\t"); 
	for (i = 0; i < (*Tr).place_num; i++)
	{
		fprintf(fp, "%2d", P->new_m_x[i]);
	}
	fprintf(fp, "\t");
	fprintf(fp, "%2d\t", P->new_m_g);
	fclose(fp);
}

//����������
void Astar_out(AstarTree *Tr, AstarNode *node)
{
	
	printf("m%2d�ı�ʶ��", node->new_m_num);
	for (int i = 0; i < (*Tr).place_num; i++)
	{
		printf("%2d", node->new_m[i]);

	}

	printf("%s", " �ѵȴ�ʱ��x��");

	for (int i = 0; i < (*Tr).place_num; i++)
	{
		printf("%2d", node->new_m_x[i]);
	}
	//for(i=0;i<place_num;i++)
	//{
	//	printf("%2d",P->new_m_flag[i]);
	//	fprintf(fp,"%2d\t",P->new_m_flag[i]);
	//}
	printf("%s", " �Ѻķ�ʱ��gΪ");

	printf("%2d", node->new_m_g);

	printf("%s", " ���ƺķ�ʱ��hΪ");

	printf("%f", node->new_m_h);

	printf("%s", " ��ʶ��Դ��M");

	//printf("%2d", P->new_m_come);
	AstarNode *Q;
	Q = node->source;
	if (Q == NULL)
	{
		//printf("%s", " M");
		printf("%2d", 0);
	}
	else
	{
		//printf("%s", " M");
		printf("%2d", Q->new_m_num);
	}
	//fprintf(fp, "%2d\t", P->new_m_come);
	printf("%s", " �����ı�Ǩ");

	printf("%2d", node->new_m_transition);

	printf("\n");
}

void Astarout(AstarTree *Tr)
{
	int i;
	int flag;
	FILE *fp;
	struct AstarNode *P, *Q;
	P = (*Tr).open_head;
	fp = fopen("A_data/pipeline_out2.txt", "w+");
	printf("%s", "������");
	printf("\n");
	do
	{
		fprintf(fp, "m%2d�ı�ʶ��", P->new_m_num);
		printf("m%2d�ı�ʶ��", P->new_m_num);
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m[i]);
			fprintf(fp, "%2d\t", P->new_m[i]);
		}

		printf("%s", " �ѵȴ�ʱ��x��");
		fprintf(fp, "%s", " �ѵȴ�ʱ��x��");
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
		printf("%s", " �Ѻķ�ʱ��gΪ");
		fprintf(fp, "%s", " �Ѻķ�ʱ��gΪ");
		printf("%2d", P->new_m_g);
		fprintf(fp, "%2d\t", P->new_m_g);
		printf("%s", " ���ƺķ�ʱ��hΪ");
		fprintf(fp, "%s", " ���ƺķ�ʱ��hΪ");
		printf("%f", P->new_m_h);
		fprintf(fp, "%f\t", P->new_m_h);
		printf("%s", " ��ʶ��Դ��M");
		fprintf(fp, "%s", " ��ʶ��Դ��M");
		//printf("%2d", P->new_m_come);
		Q = P->source;
		if (Q == NULL)
		{
			//printf("%s", " M");
			printf("%2d", 0);
			fprintf(fp, "%2d\t", 0);
		}
		else
		{
			//printf("%s", " M");
			printf("%2d", Q->new_m_num);
			fprintf(fp, "%2d\t", Q->new_m_num);
		}
		//fprintf(fp, "%2d\t", P->new_m_come);
		printf("%s", " �����ı�Ǩ");
		fprintf(fp, "%s\t", " �����ı�Ǩ");
		printf("%2d", P->new_m_transition);
		fprintf(fp, "%2d\t", P->new_m_transition);
		fprintf(fp, "\n");
		printf("\n");
		P = P->open_next;
	} while (P != NULL);
	fclose(fp);
}



void Astarout_viz(AstarTree *Tr)
{
	int i;
	int flag;
	FILE *fp;
	struct AstarNode *P, *Q;
	P = (*Tr).open_head;
	fp = fopen("A_data/pipeline_out_viz2.txt", "w+");
	do
	{
		fprintf(fp, "%2d\t", P->new_m_num);
		for (i = 0; i < (*Tr).place_num; i++)
		{
			fprintf(fp, "%2d\t", P->new_m[i]);
		}
		for (i = 0; i < (*Tr).place_num; i++)
		{
			fprintf(fp, "%2d\t", P->new_m_x[i]);
		}
		fprintf(fp, "%2d\t", P->new_m_g);

		fprintf(fp, "%f\t", P->new_m_h);

		Q = P->source;
		if (Q == NULL)
		{
			fprintf(fp, "%2d\t", 0);
		}
		else
		{
			fprintf(fp, "%2d\t", Q->new_m_num);
		}
		
		fprintf(fp, "%2d\t", P->new_m_transition);
		fprintf(fp, "\n");
		P = P->open_next;
	} while (P != NULL);
	fclose(fp);
}
