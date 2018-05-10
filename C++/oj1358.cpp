#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 1002;

bool cam(int a, int b)
{
    return a < b ? true : false;
}
int main()
{
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        
        int a[maxn], b[maxn], c[maxn], d[maxn];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
            d[i] = a[i] - c[i];
        }
        int t;
        cin >> t;
        
        for (int i = 0; i < n; i++)
            t -= c[i];

        if (t < 0)
            cout << "Oh,my god!" << endl;

        else
        {
            int you=0;
            sort(d, d + n,cam);
            for (int i = 0; i < n; i++)
            {
                t -= d[i];
                if (t >= 0)
                    you++;
                else
                    break;
            }
            cout << you << endl;
        }
    }
    return 0;
}