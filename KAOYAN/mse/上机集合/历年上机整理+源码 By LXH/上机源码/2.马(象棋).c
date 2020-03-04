/*
	�ڰ���й�����������,�������½�(1��1)��,��������...
����ֻ��������...��������...���Ͽ���...�����㵽(m, n)
���м��ֲ�ͬ���߷�
*/
#include <stdio.h>

//���̵Ŀ�Ⱥ͸߶�(���)
#define W 9
#define H 5

#define LOW -1//�½�

//����(��ǵ�ǰ���Ƿ񱻷��ʹ�)
static int chess[H][W];

//���·��������
static int count;

//����
void ClearState()
{
	int i, j;

	for(i=0; i<H; ++i)
	{
		for(j=0; j<W; ++j)
		{
			chess[i][j] = 0;
		}
	}

	count = 0;
}

//�Ƿ����ͨ��
int IsPass(int i, int j)
{
	return (
		(i>LOW && i<H) &&
		(j>LOW && j<W) &&
		!chess[i][j]);
}

//����·��(�����㷨)
void Path(int i, int j, int m, int n)
{
	//��֤����δ������δ������
	if(IsPass(i, j))
	{
		//����Ŀ���
		if(i == m-1 && j == n-1)
		{
			count++;
			return;
		}

		//δ�ﵽĿ���, ��������

		//��ǵ�ǰ���ѱ�����
		chess[i][j] = 1;

		Path(i-1, j+2, m, n);//ˮƽ����
		Path(i+1, j+2, m, n);//ˮƽ����
		Path(i-2, j+1, m, n);//��ֱ����
		Path(i+2, j+1, m, n);//��ֱ����

		//��ǵ�ǰ��δ������(���������Ҳ��Ҫ����)
		chess[i][j] = 0;
	}
}

int main()
{
	int m, n;

	while(1){
		printf("m n : ");
		scanf("%d %d", &m, &n);
		Path(0, 0, m, n);
		printf("����%d���߷�\n\n", count);

		ClearState();
	}
	
	return 0;
}