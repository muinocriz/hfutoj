#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int maxn = 1005;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        double n;
        cin >> n;
        double a[maxn];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + (int)n);
        double ans = 0;
        for (double i = 1; i < n; i++)
        {
            double v1,v2;
            double s1=0,s2=0;
            for (int j = 0; j < i; j++) //��һ��ĺ�
                s1 += a[j];
            v1 = s1 / i;                //��һ��ƽ��ֵ
            for (int j = i; j < n; j++) //�ڶ����
                s2 += a[j];
            v2 = s2 / (n - i);          //�ڶ���ƽ��ֵ
            double ans1=0,ans2=0;
            for (int j = 0; j < i; j++)
            {
                ans1 += (a[j] - v2)*(a[j] - v2);    //��һ����
            }
            for (int j = i; j < n; j++)
                ans2 += (a[j] - v1)*(a[j] - v1);    //�ڶ�����
            ans =max( ans1 + ans2,ans);             //��ͣ������ֵ

        }
        cout << fixed<<setprecision(4)<<ans<<endl;
    }
}
