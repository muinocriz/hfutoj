#include<iostream>
#include<cstring>
using namespace std;
/*
1：未被污染
2：可污染或正在污染
3：已被完全污染
*/
int m,n,x,y,t[12][12],b[12][12]= {0};
int func(int k)
{
    int count=0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(t[i][j]==0)
            {
                b[i][j]=3;
                count++;
            }
        }
    }
    if (count==m*n)
        return k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (b[i][j] == 1)
            {
                if (b[i+1][j] == 3 || b[i-1][j] == 3 || b[i][j+1] == 3|| b[i][j-1] == 3)
                {
                    b[i][j] = 2;
                    t[i][j] -= 1;
                }
            }
            else if (b[i][j]==2)
                    t[i][j]-=1;
        }
    func(k + 1);
}
int main()
{
    while (cin>>m>>n>>x>>y)
    {
        memset(b,0,sizeof(b));
        for (int i=1; i<=m; i++)
        {
            for (int j=1; j<=n; j++)
            {
                cin >> t[i][j];
                b[i][j] = 1;
            }
        }
        b[x+1][y+1] = 2;
        int k = func(0);
        cout << k << endl;
    }
    return 0;
}
