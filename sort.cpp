#include<iostream>

using namespace std;

/*
 * 实现了包括插入排序、冒泡排序、二分归并排序，并在main中对一数组进行试验
 */

double* sort_insert(double* a,int M)//插入排序
{
    double* b = new double[M];
    b = a;
    for(int i = 1 ; i <= M - 1 ; ++i)
    {
        double key = a[i];
        for(int j = i - 1 ; j >= 0 ; j--)
        {
            if(key >= b[j]) b[j + 1] = key;
            else
            {
                b[j + 1] = b[j];
                b[j] = key;
            }
        }
    }
    return b;
}

double* sort_bubble(double* a,int M)//冒泡排序
{
    double* b = new double[M];
    b = a;
    bool flag = 0;
    while(!flag)
    {
        flag = 1;
        for(int i = 1 ; i <= M -1 ; ++i)
        {
            if(b[i - 1] > b[i])
            {
                b[i - 1]  = b[i] + b[i - 1];
                b[i] = b[i - 1] - b[i];
                b[i - 1] = b[i - 1] - b[i];
                flag = 0;
                continue;
            }
        }
    }

    return b;
}

double* merge(double* a1,double* a2,int M1,int M2)//归并排序中的合并函数
{
    int i = 0;
    int j = 0;
    double* b = new double[M1 + M2];
    while(i <= M1 -1 || j <= M2 - 1)
    {
        if(i <= M1 -1 && j <= M2 - 1)
        {
            if(a1[i] >= a2[j])
            {
                b[i + j] = a2[j];
                j++;
                continue;
            }
            else
            {
                b[i + j] = a1[i];
                i++;
                continue;
            }
        }
        else if(i == M1)
        {
            b[i + j] = a2[j];
            j++;
            continue;
        }
        else if(j == M2)
        {
            b[i + j] = a1[i];
            i++;
            continue;
        }

    }
    return b;
}

double* sort_merge(double* a,int M)//归并排序
{
    if(M > 1)
    {
        double* a1 = new double[(int)M/2];
        a1 = a;
        double* a2 = new double[M - (int)M/2];
        a2 = a + (int)M/2;
        return merge(sort_merge(a1,(int)M/2),sort_merge(a2,M - (int)M/2),(int)M/2,M - (int)M/2);//递归
    }
    else
    {
        return a;
    }
}



int main()
{
    double a[20] = {19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    double* b;
    int M = 20;
    b = sort_bubble(a,M);//应用归并排序
    //cout<<"here"<<endl;
    for(int i = 0 ; i <= 19 ; ++i)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}