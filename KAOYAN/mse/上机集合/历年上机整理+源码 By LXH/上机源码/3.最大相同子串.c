/*
	�������������ַ���S1��S2,
����������Ǽ�������ͬ�Ӵ�.
*/
#include <stdio.h>
#include <string.h>

#define N 40

char subStr1[N], subStr2[N];

//ȡ�Ӵ�
void SubString(char *src, char *sub, int s, int e)
{
	int i;

	for(i=s; i<e; i++)
	{
		sub[i-s] = src[i];
	}

	sub[i-s] = '\0';
}

//����󹫹��Ӵ�
char* MaxSubString(char *str1, char *str2)
{
	int len1 = (int)(strlen(str1));
	int len2 = (int)(strlen(str2));
	//�󳤶���С��
	int len = len1 < len2 ? len1 : len2;

	int i, j;

	//���ȴӴ�С����
	while(len)
	{
		for(i=0; i<len1-len+1; i++)
		{
			for(j=0; j<len2-len+1; j++)
			{
				//ȡ�Ӵ�
				SubString(str1, subStr1, i, i+len);
				SubString(str2, subStr2, j, j+len);

				//�Ӵ����(ֱ�ӷ���)
				if(!strcmp(subStr1, subStr2))
				{
					return subStr1;
				}
			}
		}

		len--;
	}
}

int main()
{
	char str1[N], str2[N];

	printf("S1 = ");
	scanf("%s", str1);

	printf("S2 = ");
	scanf("%s", str2);

	//����Ӵ�
	printf("Max sub string is %s\n", 
		MaxSubString(str1, str2));

	return 0;
}