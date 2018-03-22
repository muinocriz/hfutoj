#include <iostream>
#include<stack>
#include<queue>
using namespace std;

void printAllStack(queue<int> a,stack<int> in, queue<int> out,int n)
{
    if(n <= 0 || (a.empty() && in.empty() && out.empty()))
    {
        return;
    }

    if(out.size() == n)
    {
        while(!out.empty())
        {
            cout << out.front();
            out.pop();
        }
        cout << endl;
    }

    stack<int> inCopy = in;
    queue<int> outCopy = out;

    if(!in.empty())
    {
        out.push(in.top());
        in.pop();
        printAllStack(a,in,out,n);
    }

    if(!a.empty())
    {
        inCopy.push(a.front());
        a.pop();
        printAllStack(a,inCopy,outCopy,n);
    }
    return;
}
int main()
{

    int n;
    while(cin >> n)
    {
        queue<int> a;

        for(int i = 1 ; i <= n; i++)
        {
            a.push(i);
        }
        stack<int> in;
        queue<int> out;

        printAllStack(a,in,out,n);

    }


    return 0;
}
