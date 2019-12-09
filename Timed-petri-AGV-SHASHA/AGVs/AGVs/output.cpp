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

	printf("%s", "��������");
	printf("\n");

	do
	{
		printf("m%2d�ı�ʶ��", p->new_m_num);
		fprintf(fp, "m%2d�ı�ʶ��", p->new_m_num);

		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", p->new_m[i]);
			fprintf(fp, "%2d\t", p->new_m[i]);
		}

		printf("%s", "�Ѿ��ȴ���ʱ��w��:");
		fprintf(fp, "%s", "�Ѿ��ȴ���ʱ��w��:");
		for (i = 0; i < (*Tr).transition_num; i++)
		{
			printf("%2d", p->new_t_w[i]);
			fprintf(fp, "%2d\t", p->new_t_w[i]);
		}

		printf("%s", "�Ѿ��ķѵ�ʱ��g�ǣ�");
		fprintf(fp, "%s", "�Ѿ��ķѵ�ʱ��g�ǣ�");
		printf("%2d", p->new_m_g);
		fprintf(fp, "%2d\t",p->new_m_g);

		printf("%s", " ��ʶ��Դ��M");
		fprintf(fp, "%s", "��ʶ��Դ��M");
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

		printf("%s", "�����ı�Ǩ��");
		fprintf(fp, "%s\t", "�����ı�Ǩ��");
		printf("%2d", p->new_t_come);
		fprintf(fp, "%2d\t", p->new_t_come);

		if (p->finish == 0)
		{
			printf("%s", " ��������ֹ��ʶ NO");
			fprintf(fp, "%s", "��������ֹ��ʶ YES");
		}
		else
		{
			printf("%s", " ������ֹ��ʶ YES");
			fprintf(fp, "%s", "������ֹ��ʶ YES");
		}

		if (p->old == 0)
		{
			printf("%s", " �������ظ���ʶ");
			fprintf(fp, "%s", "�������ظ���ʶ");
		}
		else
		{
			printf("%s", " �����ظ���ʶ��");
			fprintf(fp, "%s", "�����ظ���ʶ��");
			printf("%2d", p->old_m_num);
			fprintf(fp, "%2d\t", p->old_m_num);
		}
		printf("\n");
		fprintf(fp, "\n");
		p = p->next;
	} while (p != NULL);
	fclose(fp);
}


