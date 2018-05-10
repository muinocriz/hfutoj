#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main()
{
    struct d
    {
        int du;
        vector<int> next;
        d()
        {
            du = 0;
        }
    };
    int T;
    cin >> T;
    while (T--)
    {
        vector<int> ans;
        
        int n,m;
        cin >> n >> m;
        d *meal=new d[n];
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            meal[a - 1].next.push_back(b - 1);
            meal[b-1].du++;
        }
        priority_queue<int>que;
        for (int i = 0; i < n; i++)
        {
            if (meal[i].du == 0)
            {
                que.push(i);
                
            }
            
        }
        if (que.empty())
        {

            cout << "-1" << endl;
            continue;

        }
        queue<int> que2;
        
        while (!que.empty())
        {
            int x = que.top();
            ans.push_back(x);
            que.pop();
            if(!meal[x].next.empty())
            for (int i = 0; i < meal[x].next.size(); i++)
            {
                meal[meal[x].next[i]].du--;
                if (meal[meal[x].next[i]].du == 0)
                {
                    que.push(meal[x].next[i]);
                }

            }
        }
        
        if (ans.size() < n)
            cout <<"-1" << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                if(i)
                    cout << " ";
                cout << ans[i] + 1;
            }
            cout << endl;
        }
        delete[]meal;
    }
    return 0;
}