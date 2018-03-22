#include <iostream>
using namespace std;
int main()
{
    int n,k,i,j,kk;
    int sum,max=0;
    while(cin>>n>>k)
    {
        max=0;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]>max)
                max=a[i];
        }
        sum = k/max;
        k%max != 0?sum++:sum+sum;
        cout << sum << endl;
    }
    return 0;
}
