#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int a,b,c,d;
        cin >>a>>b>>c>>d;
        int ans = a*b-c*d;
        ans<0 ? ans = -ans:ans=ans;
        cout << ans << endl;
    }
    return 0;
}
