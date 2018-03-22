#include <iostream>
using namespace std;
int main()
{
    int n,i,j,num;
    int count;
    while(cin>>n)
    {
        count=0;
        int a[n];
        for(i=0; i<n; i++)
        {
            cin >> a[i];

        }
        for(i=0; i<n; i++)
        {
            for(j=0;j<n;j++)
                if(a[j] + a[i]==0)
                    count++;
        }
        cout << count/2 << endl;
    }
    return 0;
}
