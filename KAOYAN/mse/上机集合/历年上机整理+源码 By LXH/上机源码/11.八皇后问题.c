/*
	��̽��"�˻ʺ�����":����һ��8*8�ľ��θ������ŷ�8��
�ʺ�,Ҫ�������������:���������ʺ󶼲�����ͬһ��/��/�Խ�
��(б�ʵ���1/-1).
	Ҫ���̸������е�һ�е�һ���лʺ�Ľ�
(ע����������8�����ֱ�ʾ,�磺������{1,5,8,6,3,7,2,4},��
��'1'��ʾ��һ�е�һ�м�(1,1)���лʺ�, ��ͬ)
*/
#include <stdio.h>

#define N 8

//����
typedef struct c
{
	int i;
	int j;
}Chessman;

//����
typedef struct ca
{
	int			len;
	Chessman	chess[N];
}QueenArr;

//�˻ʺ�����
QueenArr queenArr = {0};
//��
int result[N];

//��ʼ��
void Init()
{
	//�ںõ�һ�Ź̶�������
	queenArr.len = 1;
	queenArr.chess[0].i = 0;
	queenArr.chess[0].j = 0;

	result[0] = 0;
}

//�����
void Output()
{
	int i;

	printf("{");

	for(i=0; i<N; i++)
	{
		printf("%d,", result[i]+1);
	}
	
	printf("%d}\n", result[i]+1);
}

//�����Ƿ���������(��ͬ��/��/�Խ���)
int Check()
{
	int		j;//ѭ������
	float	k;//б��
	int		isOk = 1;//����Ƿ���������
	int		i = queenArr.len - 1;//��������ӵ��±�
	Chessman *arr = queenArr.chess;//����

	for(j=0; j<i; j++)
	{
		//��б��
		k = 1.0f * (arr[i].i - arr[j].i) / 
			(arr[i].j - arr[j].j);

		if( arr[i].i == arr[j].i ||//ͬ��
			arr[i].j == arr[j].j ||//ͬ��
			k == 1 || k == -1 )//ͬ�Խ���
		{
			isOk = 0;
			break;
		}
	}

	return isOk;
}

/*
 *���(�����㷨)
 *@i: ��ǰ�������̵��б�
 */
void Solution(int i)
{
	//�ں����е�����,ֱ�������
	if(i == N)
	{
		Output();
	}
	else
	{
		int j;
		for(j=1; j<N; j++)
		{
			//������
			queenArr.chess[queenArr.len].i = i;
			queenArr.chess[queenArr.len].j = j;
			queenArr.len++;

			//��������
			if(Check())
			{
				result[i] = j;//��¼�����

				Solution(i+1);//��̽��һ��
			}

			//����
			queenArr.len--;
		}
	}
}

int main()
{
	Init();

	Solution(1);

	return 0;
}