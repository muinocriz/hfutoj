#include <iostream>
#include <stdio.h>
using namespace std;

int find(int x,int *father)
{
    if(x == father[x])
        return x;
    father[x] = find(father[x],father);
    return father[x];
}

void unionByHeight(int *father,int *height,int i,int j)
{
    int fi = find(i,father);
    int fj = find(j,father);
    if(fi == fj)
        return;
    if(height[fi] > height[fj])
    {
        father[fj] = fi;
        height[fi] += height[fj];
    }
    else
    {
        father[fi] = fj;
        height[fj] += height[fi];
    }
}

int main()
{
    int n,a=0,b=0,i=0;
    scanf("%d",&n);
    int father[n+1];
    int height[n+1];
    for(i; i<=n; i++)
    {
        father[i] = i;
        height[i] = 1;
    }

    for(i=1; i<=n; i++)
    {
        cin>>a>>b;
        unionByHeight(father,height,a,b);
    }

    int result = 0;
    for(i=1; i<=n; i++)
    {
        if(father[i] == i)
        {
            result++;
        }
    }
    cout<<result<<endl;
    return 0;
}
