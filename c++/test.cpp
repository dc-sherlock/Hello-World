#include <iostream>
#include<cmath>
//#include<vector>
using namespace std;
void Bubblesort(int n,int* p);//冒泡排序
void quickSort(int *p,int n,int r);
int partion(int *p,int s,int e);//快速排序
void randomQuickSort(int *p,int n,int r);
int randomPartion(int *p,int s,int e);//随机快速排序
void coutingsort(int* p,int* q,int n,int k);//使n为最大数,k为数组长度,计数排序
void insertionSort(int* p,int n);//插入排序
void merge_sort(int *data, int start, int end, int *result);
void merge(int *data,int start,int end,int *result);
void sort2(int *p, int n, int loop);
int getLoopTimes(int num);
int findMaxNum(int *p, int n);
void radixSort(int *p, int n);//基数排序,d为最高位数
void buckerSort(int* p,int n);//桶排序

int main()
{
    int a[5]={0,3,5,7,1};
    int b[8]={10,2,4,6,11,0,9,8};//快速排序
    int c[8]={1,103,1,4,5,8,9,6};//随机快速排序
    int d[8]={10,5,2,5,3,5,1,7};//计数排序
    int d1[8]={0};
    int e[8]={11,23,52,34,16,73,45,32};//插入排序
    int f[8]={13,32,53,12,23,64,42,77};//归并排序
    int f1[8]={0};
    int f2[9]={23,13,32,53,12,23,64,42,77};//归并排序
    int f12[9]={0};
    int g[10]={0,3,2,6,5,3,5,8,4,9};//桶排序
    int h[10]={123,23,263,6,324,38,656,45,678,12};//基数排序
    cout<<"hello world"<<endl;

 //   Bubblesort(5,a);
    cout<<endl;
    quickSort(b,0,7);
    randomQuickSort(c,0,7);
    coutingsort(d,d1,10,8);
    insertionSort(e,8);
    merge_sort(f,0,7,f1);
    merge_sort(f2,0,8,f12);
    buckerSort(g,10);
    radixSort(h,10);
     cout<<"quickSort:";
   for(int j=0;j<8;j++)
    {
        cout<<b[j]<<" ";
    }
    cout<<endl;
     cout<<"randomQuickSort:";
    for(int j=0;j<8;j++)
    {
        cout<<c[j]<<" ";
    }
    cout<<endl;
     cout<<"coutingsort:";
    for(int j=0;j<8;j++)
    {
        cout<<d1[j]<<" ";
    }
    cout<<endl;
    cout<<"insertionSort:";
     for(int j=0;j<8;j++)
    {
        cout<<e[j]<<" ";
    }
    cout<<endl;
    cout<<"mergeSort:";
     for(int j=0;j<8;j++)
    {
        cout<<f[j]<<" ";
    }
    cout<<endl;
    cout<<"mergeSort:";
     for(int j=0;j<9;j++)
    {
        cout<<f2[j]<<" ";
    }
    cout<<endl;
    cout<<"buckerSort:";
     for(int j=0;j<10;j++)
    {
        cout<<g[j]<<" ";
    }
    cout<<endl;
    cout<<"radixSort:";
     for(int j=0;j<10;j++)
    {
        cout<<h[j]<<" ";
    }
    system("pause");
    return 0;
}
int partion(int* p,int s,int e)
{
    int x=p[e];
    int i=s-1;
    for(int j=s;j<=e-1;j++)
    {
        if(p[j]<=x)
        {
            i=i+1;
            int temp1=p[i];
            p[i]=p[j];
            p[j]=temp1;
        }
    }
    int temp2=p[i+1];
    p[i+1]=p[e];
    p[e]=temp2;
    return i+1;
}
int randompartion(int *p,int s,int e)
{
    int i=(rand() % (e-s))+ s;
    int temp=p[i];
    p[i]=p[e];
    p[e]=temp;
    return partion(p,s,e);
}
void randomQuickSort(int *p,int n,int r)
{
    if(n<r)
    {
        int q=randompartion(p,n,r);
        randomQuickSort(p,n,q-1);
        randomQuickSort(p,q+1,r);
    }
}
void quickSort(int* p,int s,int e)
{
    if(s<e)
    {
        int q=partion(p,s,e);
        quickSort(p,s,q-1);
        quickSort(p,q+1,e);
    }
}
void coutingsort(int* p,int* q,int n,int k)
{
    int c[n]={0};
    for(int j=0;j<k;j++)
    {
        c[p[j]]=c[p[j]]+1;
    }
    for(int i=1;i<=n;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for(int j=k-1;j>=0;j--)
    {
        q[c[p[j]]]=p[j];
        c[p[j]]=c[p[j]]-1;
    }

}
void Bubblesort(int n,int* p)
{
    int i=0;
    for(int j=0;j<n;j++)
    {
        cout<<p[j];
    }
    cout<<endl;
    for(i=1;i<n;i++){
        for(int j=1;j<5;j++){
            if(p[j]<p[j-1]){
                int temp=p[j];
                p[j]=p[j-1];
                p[j-1]=temp;
            }

        }
    }
    for(int j=0;j<5;j++)
    {
        cout<<p[j]<<endl;
    }
}
void insertionSort(int* p,int n)
{
    for(int j=1;j<n;j++)
    {
        int key=p[j];
        int i=j-1;
        while(i>0&&p[i]>key)
        {
            p[i+1]=p[i];
            i=i-1;
        };
        p[i+1]=key;
    }
}

void merge_sort(int *data, int start, int end, int *result)
{
    if(1 == end - start)//如果区间中只有两个元素，则对这两个元素进行排序
    {
        if(data[start] > data[end])
        {
            int temp  = data[start];
            data[start] = data[end];
            data[end] = temp;
        }
        return;
    }
    else if(0 == end - start)//如果只有一个元素，则不用排序
        return;
    else
    {
        //继续划分子区间，分别对左右子区间进行排序
        merge_sort(data,start,(end-start+1)/2+start,result);
        merge_sort(data,(end-start+1)/2+start+1,end,result);
        //开始归并已经排好序的start到end之间的数据
        merge(data,start,end,result);
        //把排序后的区间数据复制到原始数据中去
        for(int i = start;i <= end;++i)
            data[i] = result[i];
    }
}
void merge(int *data,int start,int end,int *result)
{
    int left_length = (end - start + 1) / 2 + 1;//左部分区间的数据元素的个数
    int left_index = start;
    int right_index = start + left_length;
    int result_index = start;
    while(left_index < start + left_length && right_index < end+1)
    {
        //对分别已经排好序的左区间和右区间进行合并
        if(data[left_index] <= data[right_index])
            result[result_index++] = data[left_index++];
        else
            result[result_index++] = data[right_index++];
    }
    while(left_index < start + left_length)
        result[result_index++] = data[left_index++];
    while(right_index < end+1)
        result[result_index++] = data[right_index++];
}
//基数排序
void radixSort(int *p, int n)
{
	//获取数组中的最大数
	int maxNum = findMaxNum(p, n);
	//获取最大数的位数，次数也是再分配的次数。
	int loopTimes = getLoopTimes(maxNum);
	int i;
	//对每一位进行桶分配
	for (i = 1; i <= loopTimes; i++)
	{
		sort2(p, n, i);
	}
}
//获取数字的位数
int getLoopTimes(int num)
{
	int count = 1;
	int temp = num / 10;
	while (temp != 0)
	{
		count++;
		temp = temp / 10;
	}
	return count;
}
//查询数组中的最大数
int findMaxNum(int *p, int n)
{
	int i;
	int max = 0;
	for (i = 0; i < n; i++)
	{
		if (*(p + i) > max)
			max = *(p + i);
	}
	return max;
}
//将数字分配到各自的桶中，然后按照桶的顺序输出排序结果
void sort2(int *p, int n, int loop)
{
	//建立一组桶此处的20是预设的根据实际数情况修改
	int buckets[10][20] = {};
	//求桶的index的除数
	//如798个位桶index=(798/1)%10=8
	//十位桶index=(798/10)%10=9
	//百位桶index=(798/100)%10=7
	//tempNum为上式中的1、10、100
	int tempNum = (int)pow(10, loop - 1);
	int i, j;
	for (i = 0; i < n; i++)
	{
		int row_index = (*(p + i) / tempNum) % 10;
		for (j = 0; j < 20; j++)
		{
			if (buckets[row_index][j] == NULL)
			{
				buckets[row_index][j] = *(p + i);
				break;
			}
		}
	}
	//将桶中的数，倒回到原有数组中
	int k = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 20; j++)
		{
			if (buckets[i][j] != NULL)
			{
				*(p + k) = buckets[i][j];
				buckets[i][j] = NULL;
				k++;
			}
		}
	}
}

void buckerSort(int* p,int n)
{
    int bucket[n]={0};
    for(int i=0;i<n;i++)
    {
        bucket[p[i]]=bucket[p[i]]+1;
    }
    int j=0;
    for(int i=0;i<n;i++)
    {
        while(bucket[i]!=0)
        {
            p[j]=i;
            bucket[i]=bucket[i]-1;
            j=j+1;
        };
        
    }

}