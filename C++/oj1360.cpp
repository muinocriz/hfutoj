#include <iostream>
#include <algorithm>

using namespace std;

const int maxp = 300;
const int INF = 9999;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int dis[maxp][maxp];
        int N, P, C;
        cin >> N >> P >> C;
        int fri[maxp];
        for (int i = 1; i <= P; i++)
            for (int j=1; j <= P; j++)
                dis[i][j] = INF;
        for (int i = 1; i <= N; i++)
            cin >> fri[i];
        for (int i = 0; i < C; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            dis[a][b] = dis[b][a] = c;
        }
        for (int i = 1; i <= P; i++)
            dis[i][i] = 0;
        for (int k = 1; k <= P; k++)
            for (int i = 1; i <= P; i++)
                for (int j = 1; j <= P; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        int ansz = INF;
        for (int i = 1; i <= P; i++)
        {
            int ans = 0;
            for (int j = 1; j <= N; j++)
            {
                ans += dis[i][fri[j]];
            }
            ansz = min(ansz, ans);
        }
        cout << ansz << endl;
    }
}