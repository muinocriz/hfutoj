#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;
    while(cin >> N )
    {
        int a,top = 0,next = 0,res = 0,in = 0;
        priority_queue <int,vector<int> , greater<int> > star;

        while(N -- )
        {
            cin >> a;
            star.push(a);
        }
        while(star.size() >1)
        {
            top = star.top();
            star.pop();

            next = star.top();
            star.pop();

            in = top + next;
            star.push(in);
            res += in;
        }
        cout<<res<<endl;
    }
    return 0 ;
}

