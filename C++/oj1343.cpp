//(1)、当N为奇数时,那么N,N-1,N-2互为质数,很明显N*N-1*N-2是1~N最小公倍数的最大值。
//(2)、当N为偶数时,
//    且能被3整除时,N-1,N-2,N-3互质,此时N-1*N-2*N-3是1~N最小公倍数的最大值;
//    不能被3整除时,N,N-1,N-3互质,此时N*N-1*N-3是1~N最小公倍数的最大值。
#include<iostream>
using namespace std;
int main()
{
    long long n, count;
    cin >> count;
    while(count--)
    {
        cin >> n;
        if (n <= 2)
        {
            cout << n << endl;
        }
        else if (n%2==1)
        {
            cout << n * (n - 1) * (n - 2) << endl;
        }
        else if (n % 3 == 0)
        {
            cout << (n - 1) * (n - 2) * (n - 3) << endl;
        }
        else
        {
            cout << n * (n - 1) * (n - 3) << endl;
        }
    }
    return 0;
}
