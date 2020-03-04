/*
	��һ����������a�м��и�����������,��дһ���㷨
��a�����и����Ƶ�����֮ǰ,Ҫ����ʱ�临�Ӷ�ΪO(n),n
Ϊ���鳤��,����ֻʹ�ó����������ռ�.
*/
#include <stdio.h>

//���ַ�����������(ʱ�临�Ӷ�O(n), �ռ临�Ӷ�O(1))
void DivideIntegers(int num[], int n)
{
	int l=0, r=n-1;
	int temp;

	while(l<r)
	{
		//�õ���ǰ��ߵ�һ�������±�
		while(num[l] < 0) l++;

		//�õ���ǰ�ұߵ�һ�������±�
		while(num[r] > 0) r--;

		////��������������, ���Կ��Ժ����������
		//if(l==n || r==-1)//ȫ����ȫ��
		//{
		//	break;
		//}

		//����
		temp = num[l];
		num[l] = num[r];
		num[r] = temp;

		l++;
		r--;
	}
}

int main()
{
	int num[] = {1, 2, 3, 4, -1, 1, -2, -1, -4};
	int n=9, i;

	//�������ǰ�Ľ��
	for(i=0; i<n; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");

	//����
	DivideIntegers(num, n);

	//������ֺ�Ľ��
	for(i=0; i<n; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
	return 0;
}