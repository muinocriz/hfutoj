#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,h[40005],q,H;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&q);
        for(int i=0; i<n*m; i++)
            scanf("%d",&h[i]);
        sort(h,h+n*m);
        while(q--)
        {
            scanf("%d",&H);
            int ans=upper_bound(h,h+n*m,H)-h;
            cout << n*m-ans << endl;
        }
    }
}
