/*
	һȺ��(������Ŵ�1��N,N���趨)Χ��һȦ,
��һ���������,ʣ�������ȻΧ��һȦ.���й���
��˳��1��N�ķ����Ȧ�ڵ��˴�1��C����(C���趨),
Ȧ�ڼ���ΪC���˳���,ʣ��������¼���,��������
��,��Ȧ�����е��˳���.����˳��������б�ŵ�
����
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//Լɪ��
void Josephus(int n, int c)
{
	int *flag;//�������
	int out, report, index;//��������, ����, ��ǰ�������±�

	//��ʼ��
	flag = (int*)malloc(sizeof(int)*n);
	memset(flag, 0, sizeof(int)*n);

	out = 0;
	index = -1;

	//ѭ��
	while(out<n)
	{
		//��һ�ֱ�����ʼ��0
		report=0;

		//����
		while(report < c)
		{
			index = (index+1)%n;

			if(!flag[index])
			{
				report++;
			}
		}

		//����
		flag[index] = 1;
		out++;
		printf("%d\n", index+1);
	}

	free(flag);
}

int main()
{
	int N, C;

	printf("N = ");
	scanf("%d", &N);

	printf("C = ");
	scanf("%d", &C);

	Josephus(N, C);

	return 0;
}