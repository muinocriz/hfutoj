#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main()
{

    const double pi = acos(-1.0);
    int T;
    cin >> T;
    while (T--)
    {
        double x1, y1, r,x11, y11,x0, y0,w,t;
        cin >> x11 >> y11 >> r >> x0 >> y0 >> w >> t;
        x1 = x11;
        y1 = y11;
        double l = t * w;
        while (l >= (2 * pi))
        {
            l -= (2 * pi);
        }
        x1 += (r * cos(l));
        y1 += (r * sin(l));
        double a, b;
        double c = -1;
        if (x1 != x0)
        {
            a = (y1 - y0) / (x1 - x0);
            b = y1 - a * x1;
        }
        else
        {
            c = 0;
            b = x1;
            a = 1;
        }
        double r2line = fabs((a * x11 + c * y11 + b) / (sqrt(a * a + 1)));
        double res = 2 * sqrt(r * r - r2line * r2line);
        printf("%.2f\n", res);
    }
    return 0;
}
