/*
		��������һ���ַ�,���±�Ϊ������Сд��ĸת
	��Ϊ��д(��Ŵ�0��ʼ,����λ���ϲ�����ĸ,��
	ת��).����:������abc4Efg,��Ӧ���aBc4EFg(�ַ�������)
*/
#include <stdio.h>
#include <string.h>

#define N 80

int main()
{
	char str[N];
	int  i;

	printf("Input: ");
	scanf("%s", str);

	for(i=0; i<(int)strlen(str); i++)
	{
		if(i%2 &&
			str[i] > 'a' &&
			str[i] < 'z')
		{
			str[i] = (char)(str[i] + 'A' - 'a');
		}
	}

	printf("Output: %s\n", str);

	return 0;
}