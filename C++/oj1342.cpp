#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    int t,n,i,j;
    map<string,string> m;
    m["0000"] = '0';
    m["0001"]='1';
    m["0010"]='2';
    m["0011"]='3';
    m["0100"]='4';
    m["0101"]='5';
    m["0110"]='6';
    m["0111"]='7';
    m["1000"]='8';
    m["1001"]='9';
    m["1010"]='A';
    m["1011"]='B';
    m["1100"]='C';
    m["1101"]='D';
    m["1110"]='E';
    m["1111"]='F';


    cin >> t;
    while(t--)
    {
        string s;
        string ss="";
        cin >> s;
        string c="";
        string ans="";
        for(i=0; i<s.size(); i++)
        {
            switch(s.at(i))
            {
            case '0':
                c+="000";
                break;
            case '1':
                c+="001";
                break;
            case '2':
                c+="010";
                break;
            case '3':
                c+="011";
                break;
            case '4':
                c+="100";
                break;
            case '5':
                c+="101";
                break;
            case '6':
                c+="110";
                break;
            case '7':
                c+="111";
                break;
            }

        }
        switch(c.size()%4)
        {
        case 0:
            break;
        case 1:
            ss="000";
            break;
        case 2:
            ss="00";
            break;
        case 3:
            ss="0";
            break;
        }
        c = ss + c;
        if(c.at(0)=='0' &&c.at(1)=='0'&&c.at(2)=='0'&&c.at(3)=='0')
        {
            c = c.substr(4);
        }
        for(i=0; i<c.size(); )
        {
            ans += m[c.substr(i,4)];
            i+=4;
        }

        cout <<ans<<endl;
    }
    return 0;
}
