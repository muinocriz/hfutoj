#include <iostream>
using namespace std;
int main()
{
    int t,i,j,k;
    int sum;
    char a,b;
    cin >>t;
    while(t--)
    {
        sum=0;
        cin>>i>>a>>j>>b>>k;
        if(a=='+')
            sum = i+j;
        else
            sum = i-j;
        if(b=='+')
            sum = sum + k;
        else
            sum=sum-k;
        cout <<sum<<endl;
    }
    return 0;
}
