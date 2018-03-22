#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        char a[200][200] = {' '};
        int c = (n+1)/2;
        a[1][c] = '*';
        a[n][c] = '*';
        a[c][1] = '*';
        a[c][n] = '*';
        for(int i = 2;i<=c;i++)
        {
            a[c+(i-1)][i] = '*';
            a[c-(i-1)][i] = '*';
            a[c+(i-1)][2*c-i] = '*';
            a[c-(i-1)][2*c-i] = '*';
        }

        for(int i = 1;i < c;i++)
            cout << ' ';
        cout << '*' <<endl;

        int flag = 2;
        for(int i =2;i<=n-1;i++)
        {
            flag = 2;
            for(int j = 1;j <=n; j++)
            {
                if(a[i][j] == '*')
                {
                    cout << '*';
                    flag--;
                    if(flag == 0)
                        cout <<endl;

                }
                else if (flag != 0)
                    cout << ' ';
            }
        }
        for(int i = 1;i < c;i++)
            cout << ' ';
        cout << '*' <<endl;
        cout <<endl;
    }
    return 0;
}
