/*
	��ӡ�����е�"ˮ�ɻ���",��ν"ˮ�ɻ���"
��ָһ��3λ��,���λ���������͵��ڸ�������.
*/
#include <stdio.h>

//�Ƿ���ˮ�ɻ���
int IsPerfectNum(int num)
{
	int sum=0;
	int n = num;
	int digit;

	while(n)
	{
		digit = n%10;
		sum += digit * digit *digit;

		n /= 10;
	}

	return num == sum;
}

int main()
{
	int i;

	for(i=100; i<1000; i++)
	{
		if(IsPerfectNum(i))
		{
			printf("%d\n", i);
		}
	}

	return 0;
}