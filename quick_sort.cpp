#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

/**
 * 实现了快速排序
 * 实现了引入随机化的快速排序
 * 
 */

using namespace std;

void swap(double* a,double* b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int partition(double* a,int M,int N)//M,N为下标上下限M-N 寻找划分点
{
    int flag = a[N];
    int p = M-1;
    int i = M;
    for(i = M ; i < N ; i++)
    {
        if(a[i] < flag)
        {
            swap(&a[i],&a[p + 1]);
            p++;
        }
    }
    swap(a[p + 1],a[N]);
    return p + 1;
}

int partition_random(double* a,int M,int N)
{   
    srand((unsigned)time(NULL));
    swap(&a[N],&a[(rand() % (N-M+1)) + M]);
    int flag = a[N];
    int p = M-1;
    int i = M;
    for(i = M ; i < N ; i++)
    {
        if(a[i] < flag)
        {
            swap(&a[i],&a[p + 1]);
            p++;
        }
    }
    swap(a[p + 1],a[N]);
    return p + 1;
}

void quick_sort(double* a,int M,int N,string mode)//主程序，递归求解 mode控制是否是random版快速排序
{
    if(M == N) return;
    else if(M < N)
    {
        int q = 0;
        mode == "random" ? q = partition(a,M,N) : q = partition_random(a,M,N);
        quick_sort(a,M,q-1,mode);
        quick_sort(a,q+1,N,mode);
    }
}

int main()
{
    double a[8] = {2,8,7,1,3,5,6,4};
    quick_sort(a,0,7,"random");
    for(int i = 0 ; i <= 7 ; ++i)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}