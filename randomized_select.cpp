#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void swap(double* a,double* b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int partition(double* a,int M,int N)//类似快速排序，随机寻找划分点
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

double randomized_select(double* a,int M,int N,int i)//从M-N中寻找第i个顺序统计量
{
    if(M == N) return a[M];
    int q = partition(a,M,N);
    if(q - M + 1 > i)
        return randomized_select(a,M,q - 1,i);
    else
    {
        if(q - M + 1 == i) return a[q];
        else return randomized_select(a,q+1,N,i - q - 1);
    }
}

int main()
{
    double a[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<randomized_select(a,0,9,8)<<endl;
    return 0;
}