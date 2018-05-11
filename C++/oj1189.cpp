#include <iostream>
using namespace std;
struct EDGE {
    int pot, nxt;
};
EDGE edge[10001];
int head[10001], idx, in[10001];
bool vi[10001];
void add(int x, int y) {
    edge[idx].pot = y;
    edge[idx].nxt = head[x];
    head[x] = idx++;
}
int main()
{
    int n, m, i, p, q;
    while (cin>>n>>m) {
        idx = 0;
        for (i = 1; i <= n; i++) head[i] = -1, in[i] = 0;
        memset(vi, 0, n + 1);
        for (i = 0; i < m; i++) {
            cin>>p>>q;
            add(p, q);
            in[q]++;
        }
        for (i = 1; i <= n; i++) {
            if (!in[i] && !vi[i]) {
                cout << i;
                vi[i] = 1;
                for (p = head[i]; p != -1; p = edge[p].nxt)
                    in[edge[p].pot]--;
                break;
            }
        }
        for (i = 1; i <= n; i++) {
            if (!in[i] && !vi[i]) {
                cout << " " << i;
                vi[i] = 1;
                for (p = head[i]; p != -1; p = edge[p].nxt)
                    in[edge[p].pot]--;
                i = 0;
            }
        }
        putchar('\n');
    }
    return 0;
}
