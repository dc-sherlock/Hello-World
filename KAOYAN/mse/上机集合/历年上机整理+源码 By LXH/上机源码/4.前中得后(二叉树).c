/*
	��֪һ�Ŷ�����S��ǰ��������������
����,�������������S�ĺ�����������.
*/
#include <stdio.h>
#include <string.h>

//�������в��Ҹ����±�
int FindRoot(char c, char in[], int s, int e)
{
	int i;
	for(i=s; i<=e; i++)
	{
		if(in[i] == c)
		{
			break;
		}
	}
	return i;
}

/*
 *�ݹ������ú���
 *@pre:��������
 *@pre_s:��ǰ������������������ʼ�±�
 *@pre_e:��ǰ���������������н����±�
 *@in:��������
 *@in_s:��ǰ������������������ʼ�±�
 *@in_e:��ǰ���������������н����±�
 */
void PostOrder(char pre[], int pre_s, int pre_e,
	char in[], int in_s, int in_e)
{
	char c;		//���ڵ����
	int root;	//���ڵ��������е��±�
	int l_len, r_len;//���������ڵ���

	//��ǰ������ֻ��һ���ڵ�(Ҷ�ӽڵ�)
	if(in_s == in_e)
	{
		printf("%c", in[in_s]);
	}
	else
	{
		//��ǰ�������ĸ��ڵ�
		c = pre[pre_s];

		//��ȡ���ڵ��������е��±�
		root = FindRoot(c, in, in_s, in_e);

		//�������������Ľڵ���
		l_len = root - in_s;
		r_len = in_e - root;

		//�ָ�������
		if(l_len > 0)//�������ڵ�����Ϊ0
		{
			PostOrder(pre, pre_s+1, pre_s+l_len,
				in, in_s, root-1);
		}

		//�ָ�������
		if(r_len > 0)//�������ڵ�����Ϊ0
		{
			PostOrder(pre, pre_e-r_len+1, pre_e,
				in, root+1, in_e);
		}

		//���������
		printf("%c", c);
	}
}

int main()
{
	char pre[] = "ABDECFG";
	char in[]  = "DBEACGF";

	PostOrder(pre, 0, strlen(pre)-1,
		in, 0, strlen(in)-1);
	printf("\n");

	return 0;
}