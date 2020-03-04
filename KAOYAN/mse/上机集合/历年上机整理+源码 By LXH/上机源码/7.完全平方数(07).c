/*
	��Ҫ�����������λ����(100��999)��Ѱ�ҷ���������
���������δ�С�������������;��������ȫƽ����,������
λ������ͬ,����144,676��
*/
#include <stdio.h>
#include <math.h>

//�Ƿ�����ȫƽ����
int IsSquare(int num)
{
	int sqr = (int)(sqrt(num * 1.0));

	return (sqr*sqr == num ||
		(sqr+1)*(sqr+1) == num );
}

//�Ƿ�����λ����ͬ
int IsTwoSame(int num)
{
	int digit0, digit1, digit2;

	digit0 = num%10;
	digit1 = (num/10)%10;
	digit2 = (num/100)%10;

	return (digit0==digit1 || digit0==digit2 || digit1==digit2);
}

int main()
{
	int i;

	for(i=100; i<1000; i++)
	{
		if(IsSquare(i) && IsTwoSame(i))
		{
			printf("%d\n", i);
		}
	}

	return 0;
}