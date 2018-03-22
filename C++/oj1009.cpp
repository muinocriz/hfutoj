#include <iostream>
#include <stdio.h>
using namespace std;
int i,j,k,m,n,r;
char a[22][22];
int b[22][22]= {0};
int xp[4],yp[4],bp[4]={0};
int f(int x, int y)
{
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if()
        }
    }
}

int main()
{
    while(cin>> m >> n)
    {
        int count=0;
        r=0;
        for(i=1; i<=m; i++)
            for(j=1; j<=n; j++)
            {
                cin >> a[i][j];
                b[i][j]=0;
                if(a[i][j]='B')
                {
                    xp[count] = i;
                    yp[count] = j;
                    bp[count] = 0;
                    count++;
                }
            }


    }

    return 0;
}
