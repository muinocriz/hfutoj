#include <iostream>
using namespace std;
int main()
{
    int t,i;
    string a,b,c,d;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c >> d;
        s=a+b+c+d;
        string ans[12] = {"1230","1203","0213","2013","2310","2301","0321",
                          "3021","3120","3102","0123","1032"
                         };
        int flag=0;
        for(i=0; i<12; i++)
        {
            if(s == ans[i])
            {
                flag=1;
                break;
            }
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
