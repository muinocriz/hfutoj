#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{

    int n,k;
    while(cin >> n >> k)
    {

    int w[15],g[15];
    for(int i=1;i<=k;i++)
    {
        cin >>g[i] >> w[i];
    }
    int f[16000] = {0};
    for(int i =1; i <= k; i++)
    {
        for(int j=1; j <= n; j++)
        {
            if(g[i] <= j)
            {
                f[j] = max(f[j],f[j-g[i]]+w[i]);
            }
        }
    }
    cout << f[n] <<endl;
    }
    return 0;
}
