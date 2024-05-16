#include<iostream>

using namespace std;

/**
 * 实现了计数排序
 * 
 */

int main()
{
    int a[10] = {9,9,7,6,5,4,3,2,1,0};
    int c[10] = {0};
    int b[10] = {0};

    for(int i = 0 ; i <= 9 ; i++)
    {
        c[a[i]]++;
    }
    for(int i = 1 ; i <= 9 ; i++)
    {
        c[i] = c[i - 1]+c[i];
    }
    for(int i = 0 ; i <= 9 ; i++)
    {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;//有并列位次，这里往前一位
    }

    for(int i = 0 ; i <= 9 ; i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}