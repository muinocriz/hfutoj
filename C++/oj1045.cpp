#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n;
    while (cin>>n)
    {
          priority_queue<   int,vector<int>,greater<int>   > que;   //greater< >ָ����С���� ������С��������,���Զ���С��������
          int  ftop, stop, j, m, res = 0;                        //vector�Զ���չ�����С
          for (int i = 0; i < n; i++)                                   //priority_queue���ȼ��ߵĳ����ɵ�������������
          {
              cin>>j;
              que.push(j);
          }
          while (que.size() > 1)             //��Ϊһ�ѣ�size��Ϊ��vector�Զ���չ��С
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
