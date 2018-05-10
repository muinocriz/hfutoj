#include <iostream>
using namespace std;

int main()
{
    int t,i;
    int a,b,c,d;
    int x,y,w,z;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c >> d;
        x=a;
        y=b;
        z=c;
        w=d;
        while(true)
        {
            if(a==0)
                swap(a,b);
            else if(b == 0)
                swap(b,d);
            else if(c == 0)
                swap(a,c);
            else
                swap(d,c);
            if(a==1&&b==2&&c==3&&d==0)
            {
                cout << "YES" <<endl;
                break;
            }
            if(x==a&&y==b&&z==c&&w==d)
            {
                cout << "NO" << endl;
                break;
            }
        }


    }


return 0;

}