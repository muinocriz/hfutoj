#include <iostream>
using namespace std;
static int a[10000005] = {0};
static int b[10005] = {0};
int main()
{
    int t,n,i,j,k,l,r;
    cin >>t;
    while(t--)
    {
        for(i=0;i<10000005;i++)
        {
            a[i]=0;
        }
        for(i=0;i<10005;i++)
        {
            b[i]=0;
        }

        cin >>n;
        for(i=1;i<=n;i++)
        {
            cin>>l>>r;
            for(j=l;j<=r;j++)
            {
                a[j]=i;
            }
        }

        for(i=1;i<10000005;i++)
        {
            if(a[i]!=0)
                b[a[i]]=1;
        }
        k=0;
        for(i=0;i<10005;i++)
        {
            if(b[i])
                k++;
        }
        cout << k << endl;
    }
    return 0;
}
