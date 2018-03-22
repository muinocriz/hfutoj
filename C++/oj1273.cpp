#include <iostream>
using namespace std;
int main()
{
    int n,i;
    while(cin>>n)
    {
        int a[10010] = {0};
        int flag=1;
        for(i=2;i<=n;i++)
        {
            while(n % i ==0)
            {
                a[i]++;
                n /= i;
            }
            if(a[i]!=0)
            {
                if(flag)
                {
                     cout << i<<"^"<<a[i];
                     flag=0;
                }
                else
                    cout <<"X"<< i<<"^"<<a[i];
            }
        }


        cout << endl;
    }
    return 0;
}
