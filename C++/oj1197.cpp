#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node{
    int v,c;
};
Node g[105][105];

int num[105];
int dp[105][10005];

int main() {
    int d, w;
    while (cin >> d >> w) {
        int r, c, v;
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= d; i++) {
            int task;
            cin >> task;
            for (int j = 1; j <= task; j++) {
                cin >> g[i][num[i]].v >> g[i][num[i]].c;
                num[i]++;
            }
        }
        memset(dp, -1, sizeof(dp));
        memset(dp[0], 0, sizeof(dp[0]));

        for (int i = 1; i <= d; i++) { // 第i天
            for (int j = 0; j < num[i]; j++) { // 第j个任务
                for (int k = w; k >= g[i][j].v; k--) {
                    if (dp[i][k-g[i][j].v] != -1) {
                        dp[i][k] = max(dp[i][k-g[i][j].v]+g[i][j].c, dp[i][k]);
                    }
                    if (dp[i-1][k-g[i][j].v] != -1) {
                        dp[i][k] = max(dp[i][k], dp[i-1][k-g[i][j].v]+g[i][j].c);
                    }
                }
            }
        }

        if (dp[d][w] != -1) {
            cout << dp[d][w] << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}