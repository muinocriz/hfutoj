#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int maxn = 105;
const int maxm = 105;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k,dp[maxn][maxm];
        memset(dp, 0, sizeof(dp));
        cin >> n >> m >> k;
        for(int i=1;i<=n;i++)
            for (int j = 1; j <= m; j++)
            {
                int temp;
                cin >> temp;
                dp[i][j] = dp[i - 1][j] + temp;
            }
        int ans=0;
        for(int i=1;i<=n;i++)
            for (int j = i; j <= n; j++)
            {
                int start = 0;
                int temp = 0;
                int span = 0;
                for (int l = 1; l <= m; l++)
                {
                    if (span > m - start)
                        break;
                    temp += dp[j][l] - dp[i - 1][l];
                    if(temp > k)
                    {
                        temp -= dp[j][start+1] - dp[i - 1][start+1];
                        start += 1;
                    }
                    else
                    {
                        int s = (l - start)*(j - i + 1);
                        if (s > ans)
                        {
                            span = l - start;
                            ans = s;
                        }
                    }
                }
            }
        cout << ans << endl;
    }
}