#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    int i,j,k,m;
    int w,x,y,z;
    int count;
    int flag;
    string s,c,a;
    while(cin>>s)
    {
        count=100;
        while(true)
        {
            flag=1;
            for(i=0,m=s.size()-1; i<m; i++,m--)
            {
                if(s.at(i)!=s.at(m))
                {
                    flag = 0;
                    break;
                }
            }
            if(flag==1)
            {
                cout<<s<<endl;
                break;
            }
            else
            {
               // cout << s << "--->";

                c="";
                z=0;
                for(j=s.size()-1; j>=0; j--)
                {
                    w=s.at(j)-48;
                    x=s.at(s.size()-1-j)-48;
                    y = (w+x+z)%10;
                    c += (char)(y+48);
                    z = (w+x+z)/10;
                }
                if(z==1)
                    c+=(z+48);
                s=c;
                reverse(s.begin(),s.end());
            }

        }
    }
    return 0;
}
