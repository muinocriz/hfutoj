#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct Coord
{
    int x, y, b;
    Coord(int xx, int yy, int bb) : x(xx), y(yy), b(bb) {}
};

#define INF (1<<20)
#define N 23
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
char g[N][N];
int m, n;
char chs[6] = {'0', '\0', '\0', '\0', '\0', '\0'};

void initG()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (g[i][j] == ',')
            {
                g[i][j] = '.';
            }
        }
    }
}


int min_bs = INF;
int bs = 0;
int has_seen = 0;
int temp_x = 1, temp_y = 1;
int Bzuobiao_xs[5];
int Bzuobiao_ys[5];

void bfs(int start_x, int start_y, char boot)
{
    queue<Coord> q;
    q.push(Coord(start_x, start_y, bs));
    g[start_x][start_y] = ',';

    while (!q.empty())
    {
        Coord cur = q.front();
        q.pop();
        int cur_b = cur.b + 1;
        for (int i = 1; i <= 4; i++)
        {
            int cur_x = cur.x + dx[i];
            int cur_y = cur.y + dy[i];
            if (cur_x >= 1 && cur_x <= m && cur_y >= 1 && cur_y <= n)
            {
                if (g[cur_x][cur_y] != ',' && g[cur_x][cur_y] != '*' && g[cur_x][cur_y] != boot)
                {
                    g[cur_x][cur_y]=',';
                    q.push(Coord(cur_x, cur_y, cur_b));
                }
                else if (g[cur_x][cur_y] == boot)
                {
                    has_seen++;
                    g[cur_x][cur_y]=',';
                    bs = cur_b;
                    temp_x = cur_x;
                    temp_y = cur_y;
                    return;
                }
            }
        }
    }
}






int main()
{
    while(~scanf("%d%d", &m, &n))
    {
        int count_B = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> g[i][j];
                if (g[i][j] == 'B')
                {
                    count_B++;
                    g[i][j] = count_B + '0';
                    Bzuobiao_xs[count_B] = i;
                    Bzuobiao_ys[count_B] = j;
                }
            }
        }

        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                if (j == i)
                {
                    continue;
                }
                for (int k = 1; k <= 4; k++)
                {
                    if (k == i || k == j)
                    {
                        continue;
                    }
                    for (int h = 1; h <= 4; h++)
                    {
                        if (h == i || h == j || h == k)
                        {
                            continue;
                        }
                        chs[1] = '0'+i;
                        chs[2] = '0'+j;
                        chs[3] = '0'+k;
                        chs[4] = '0'+h;


                        for (int mm = 1; mm <= 4; mm++)
                        {
                            bfs(temp_x, temp_y, chs[mm]);

                            for (int mmi = mm+1; mmi <= 4; mmi++)
                            {
                                g[ Bzuobiao_xs[chs[mmi]-'0'] ][ Bzuobiao_ys[chs[mmi]-'0'] ] = chs[mmi];
                            }

                            initG();
                        }

                        if (bs < min_bs)
                        {
                            min_bs = bs;
                        }

                        bs = 0;
                        has_seen = 0;
                        temp_x = 1;
                        temp_y = 1;
                        g[ Bzuobiao_xs[1] ][ Bzuobiao_ys[1] ] = '1';
                        g[ Bzuobiao_xs[2] ][ Bzuobiao_ys[2] ] = '2';
                        g[ Bzuobiao_xs[3] ][ Bzuobiao_ys[3] ] = '3';
                        g[ Bzuobiao_xs[4] ][ Bzuobiao_ys[4] ] = '4';
                    }
                }
            }
        }

        printf("%d\n", min_bs);


        bs = 0;
        has_seen = 0;
        temp_x = 1;
        temp_y = 1;
        min_bs = INF;
    }

    return 0;
}
