#include <iostream>
#include <string.h>
using namespace std;

void fz(int b[15][15], int n, int m, int x, int y)
{
    if(x <= n && x >= 0 && y <= m && y >= 0)
    {
        b[x][y] = 1;
    }
}
int main()
{
    int i,j,k,n,m;
    int mx,my;
    int a[15][15];
    int b[15][15];
    while(cin >> n >> m >> mx >> my)
    {
        //n,m棋盘大小
        //mx,my马位置
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
//        if(mx >= 0 && mx <=n && my >= 0 && my <= m)
//        {
//            b[mx][my] = 1;
//        }
        fz(b,n,m,mx,my);
        fz(b,n,m,mx+1,my+2);
        fz(b,n,m,mx+1,my-2);
        fz(b,n,m,mx+2,my+1);
        fz(b,n,m,mx+2,my-1);
        fz(b,n,m,mx-1,my+2);
        fz(b,n,m,mx-1,my-2);
        fz(b,n,m,mx-2,my+1);
        fz(b,n,m,mx-2,my-1);
        if(b[0][0] == 1 || b[n][m] == 1)
        {
            cout << 0 << endl;
            continue;
        }
        a[0][0]=1;
        for(i=1; i<=n; i++)
        {
            if(b[i][0] == 1)
            {
                a[i][0] = 0;
            }
            else
            {
                a[i][0] = a[i-1][0];
            }
        }

        for(i=1; i<=m; i++)
        {
            if(b[0][i] == 1)
            {
                a[0][i] = 0;
            }
            else
            {
                a[0][i] = a[0][i-1];
            }
        }

        for(i=1; i<=n; i++)
        {
            for (j=1; j<=m; j++)
            {
                if(b[i][j]==1)
                {
                    a[i][j] =0;
                }
                else
                {
                    a[i][j] = a[i-1][j] + a[i][j-1];
                }
            }
        }


        cout << a[n][m] << endl;
    }
    return 0;
}
