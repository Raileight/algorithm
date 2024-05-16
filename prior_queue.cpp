#include<iostream>

using namespace std;

/**
 * 在堆的最大化函数基础上
 * 实现了最大优先队列中的
 * 查找最大值maximum
 * 弹出最大值extract_maximum
 * 插入元素insert
 * 增加优先级increase
 */

void max_heapify(double* a,int i,int M)//M是堆大小，i是当前根节点，将一个子树最大化的过程
{
    if(i >= (int)M/2) return;
    int max_label = i;
    if(2 * i + 2 <= M && a[2 * i + 1] > a[max_label]) max_label = 2 * i + 1;
    if(2 * i + 3 <= M && a[2 * i + 2] > a[max_label]) max_label = 2 * i + 2;//attention! 当序号带0时，各个对应关系有变化
    if(max_label != i)//不是最大堆，交换并对子树进行最大化
    {
        a[max_label] = a[i] + a[max_label];
        a[i] = a[max_label] - a[i];
        a[max_label] = a[max_label] - a[i];
        max_heapify(a,max_label,M);
    }
    if(max_label == i) return;//确实为最大堆
}

void build_max_heap(double* a,int M)//M是堆大小，a是数组指针,将整个堆最大化的过程
{
    for(int i = (int)M/2 - 1; i >= 0 ; i--)
    {
        max_heapify(a,i,M);
    }
    return;
}

void min_heapify(double* a,int i,int M)//M是堆大小，i是当前根节点，将一个子树最小化的过程
{
    if(i >= (int)M/2) return;
    int min_label = i;
    if(2 * i + 2 <= M && a[2 * i + 1] < a[min_label]) min_label = 2 * i + 1;
    if(2 * i + 3 <= M && a[2 * i + 2] < a[min_label]) min_label = 2 * i + 2;//attention! 当序号带0时，各个对应关系有变化
    if(min_label != i)//不是最大堆，交换并对子树进行最小化
    {
        a[min_label] = a[i] + a[min_label];
        a[i] = a[min_label] - a[i];
        a[min_label] = a[min_label] - a[i];
        min_heapify(a,min_label,M);
    }
    if(min_label == i) return;//确实为最大堆
}

//查找最大值
double maximum(double* a,int M)
{
    build_max_heap(a,M);
    return a[0];
}

//查找并弹出最大值
double extract_maximum(double* a,int M)
{
    build_max_heap(a,M);
    double max = a[0];
    a[0] = a[M-1];
    a[M-1] = max;
    max_heapify(a,0,M-1);
    return max;
}

//插入元素
//...

//提高优先级
void increase(double* a,int M,int i,double k)
{
    build_max_heap(a,M);
    a[i] = k;
    while(i > 0)
    {
        if(a[(int)(i - 1)/2] < a[i])
        {
            double tmp = a[i];
            a[i] = a[(int)(i-1)/2];
            a[(int)(i-1)/2] = tmp;
        }
        i = (int)(i - 1)/2;
    }
    return;
}

int main()
{
    double a[10] = {4,1,3,2,16,9,10,14,8,7};
    int M = 10;
    build_max_heap(a,M);

    increase(a,M,3,17);
    cout<<maximum(a,M)<<endl;
    extract_maximum(a,M);

    for(int i = 0 ; i <= 8 ; ++i)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}