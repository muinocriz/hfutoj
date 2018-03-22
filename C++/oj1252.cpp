#include <iostream>
using namespace std;
int main()
{
    int i,j,n;
    cin >> n;
    while(n--)
    {
        int n,k;
        cin>> n >> k;
        k>=n?k=k%n:k=k;
        int a[n];
        for(i=0; i<n; i++)
        {
            cin >> a[i];
        }
        if(k !=0)
        {
            for(i=n-k; i<n; i++)
            {
                cout << a[i] << " ";
            }
            for(i=0; i<n-k; i++)
                i==n-k-1?cout<< a[i]:cout << a[i] << " ";
        }
        else
        {
            for(i=0; i<n; i++)
            {
                i==n-1?cout<< a[i]:cout<< a[i] <<" ";
            }
        }
        cout << endl;
    }
    return 0;
}
