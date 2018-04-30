#include<iostream>
using namespace std;
int main()
{
    int n,m,a,b;
    while(cin>>n>>m)
    {
        a = 3*n-m/2;
        b = n - a;
        if(4*a+6*b == m && a >= 0 && b >= 0)
        {
            cout<<a<<" Ghouls"<<endl;
            cout<<b<<" Crypt Fiends"<<endl;
            cout<<endl;
            continue;
        }
        else
        {
            cout<<"Impossible."<<endl;
            cout<<endl;
        }
    }
    return 0;
}
