#include <iostream>
using namespace std;
int pre[1005];

int find(int x)
{
    int r = x;
    while(pre[r] != r)
        r = pre[r];
    return r;
}

void join(int x, int y)
{
    int fx = find(x), fy = find(y);
    if(fx != fy)
        pre[fx] = pre[fy];
}

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
            pre[i] = i;

        char op;
        int x ,y;
        for(int i=1;i<=m;i++)
        {
            cin >> op >> x >> y;
            if(op == 'U')
                join(x,y);
            else if (op == 'Q')
            {
                int f1 = find(x);
                int f2 = find(y);
                if(f1 == f2)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
        }
    }
    return 0;
}
