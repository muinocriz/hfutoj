#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int a[1000005];
int p;
int f(int n, int p)
{
    int left = 0;
    int right = n-1;
    int mid;
    while(left <= right)
    {
        mid = (left + right)/2;
        if(p<a[mid])
            right = mid-1;
        else if (p>a[mid])
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&p);
        printf("%d\n",f(n,p));
    }
    return 0;
}
