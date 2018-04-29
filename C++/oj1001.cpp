#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int a=1;
        int k=2 * n;
        int b=2;
        while(b!=1)
        {
            if(b*2<=k)
            {
                b*=2;
            }
            else
            {
                b=(b-n)*2-1;
            }
            a++;
        }
        cout<<a<<endl;
    }
    return 0;
}
