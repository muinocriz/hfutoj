#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n;
    while (cin>>n)
    {
          priority_queue<   int,vector<int>,greater<int>   > que;   //greater< >指定是小顶堆 ，即从小到大排列,且自动从小到大排序
          int  ftop, stop, j, m, res = 0;                        //vector自动扩展数组大小
          for (int i = 0; i < n; i++)                                   //priority_queue优先级高的出，由第三个参数决定
          {
              cin>>j;
              que.push(j);
          }
          while (que.size() > 1)             //成为一堆，size因为是vector自动扩展大小
          {
                ftop = que.top();
                que.pop();

                stop = que.top();
                que.pop();

                m =stop + ftop;
                res += stop + ftop;
                que.push(m);
          }
          cout<<res<<endl;
    }
    return 0;
}
