/*
	д�������100������1000���ڵ�ƽ��������
����:121, ������ȫƽ����, Ҳ�ǻ�����
*/
#include <stdio.h>
#include <math.h>

//�Ƿ�����ȫƽ����
int IsSquare(int num)
{
	int sqr = (int)(sqrt(num*1.0));

	return (sqr*sqr == num ||
		(sqr+1)*(sqr+1) == num);
}

//�Ƿ��ǻ�����(3λ)
int IsReverse(int num)
{
	return num%10 == 
		num/100;
}

int main()
{
	int i;

	for(i=100; i<1000; i++)
	{
		if(IsSquare(i) &&
			IsReverse(i))
		{
			printf("%d\n", i);
		}
	}
	
	return 0;
}