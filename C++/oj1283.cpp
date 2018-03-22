#include <iostream>
using namespace std;
int main()
{
    int k,t;
    int n,count=1;
    cin >>t;
    while(t--)
    {
        cin>>n;
        k=1;
        while(n%2==0)
        {
            k*=2;
            n/=2;
        }
        cout << "Case #" <<count++<<": "<< k<<endl;
    }
    return 0;
}
