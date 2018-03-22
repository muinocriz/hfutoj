#include <iostream>
#include <stdio.h>
#include <string.h>
int a[100005][13];
int main()
{
    int i,j,n,x,t,maxt;
    while(scanf("%d",&n),n)
    {
        memset(a,0,sizeof(a));
        maxt = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&x,&t);
            a[t][x]++;
            if(t>maxt)maxt=t;
        }
        for(i=maxt-1; i>=0; i--)
        {
            for(j=1; j<=11; j++)
            {
                a[i][j] += std::max(std::max(a[i+1][j-1],a[i+1][j]),a[i+1][j+1]);
            }
        }
        printf("%d\n",a[0][6]);
    }
    return 0;
}
