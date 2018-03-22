#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    int i,j,k,m,n,a,b;
    while(t--)
    {
        cin>> n >> m >>a>>b;
        int flag = a % n;
        int turn = 1;
        int arr[n];
        while(flag%n != m%n)
        {
            if(isprime(b))
            {
                turn = -turn;
                flag += turn;
            }
            else
            {
                flag += turn;
            }
            b++;
        }
        if(isprime(b))
            cout << "duang" << endl;
        else
            cout << b <<endl;
    }
    return 0;
}
