//(1)����NΪ����ʱ,��ôN,N-1,N-2��Ϊ����,������N*N-1*N-2��1~N��С�����������ֵ��
//(2)����NΪż��ʱ,
//    ���ܱ�3����ʱ,N-1,N-2,N-3����,��ʱN-1*N-2*N-3��1~N��С�����������ֵ;
//    ���ܱ�3����ʱ,N,N-1,N-3����,��ʱN*N-1*N-3��1~N��С�����������ֵ��
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
