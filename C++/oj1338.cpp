#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int i,j,n,m,t,k;
    int b[10000]= {0};
    b[0]=2;
    b[1]=3;
    b[2]=5;
    b[3]=7;
    int count = 4;
    for(j = 11; count<10005; j=j+2)
    {
        for(k=3; k<=j/2; k=k+2)
        {
            if(j %k==0)
                break;
            if(k>=sqrt(j))
            {
                b[count++]=j;
                break;
            }
        }
    }

    cin>>t;
    while(t--)
    {
        cin >> n >> m;
        int a[n][m];
        count = 0;
        for(int i=0; i<m; i++)
        {
            if(i%2==0)
                for( j=0; j<n; j++)
                    a[j][i] =b[count++];
            else
                for( j=n-1; j>=0; j--)
                    a[j][i] =b[count++];
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
                cout << setw(6) << a[i][j];
             cout << endl;
        }
    }
    return 0;
}
