/*
	������s(n)=s(n-1)+s(n-2)�ĵ�n���ֵ
����s(1)=s(2)=1.Ҫ���������n,���s(n)
*/
#include <stdio.h>

int Fibonacci(int n)
{
	if(n==1 || n==2)
	{
		return 1;
	}

	return Fibonacci(n-1) + Fibonacci(n-2);
}

int main()
{
	printf("Fibonacci(8) = %d\n",
		Fibonacci(8));

	return 0;
}