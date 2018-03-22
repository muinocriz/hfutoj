#include <iostream>
#include <stdio.h>
using namespace std;
    int a[1005];
    void quicksort(int left, int right)
{
    int i ,j, t, temp;
    if(left > right)
        return;

    temp = a[left];//temp存储基准数
    i = left;
    j = right;
    while (i != j)
    {
        //顺序很重要，要先从右往左找
        while (a[j] >= temp && i < j)
            j--;

        //再从左往右找
        while (a[i] <= temp && i < j)
            i++;

        //交换两个数在数组中的位置
        if (i < j)//i j 没有相遇
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    //基数归位
    a[left] = a[i];
    a[i] = temp;

    quicksort(left, i-1);
    quicksort(i+1, right);
}
int main()
{
    int n,i;
    while(cin >> n)
    {

    for(i=0;i<n;i++)
        cin>>a[i];
    quicksort(0, n-1);
    if(n%2==0)
        {
            printf("%.2f\n",(a[n/2] + a[n/2-1])/2.0);
        }
    else
        printf("%.2f\n",a[(n-1)/2]*1.0);
    }

    return 0;
}
