#include <iostream>
#include <map>
#include <cstring>
using namespace std;

bool isNum(char ch)
{
    return ch <= '9' && ch >= '0';
}

bool isLetter(char ch)
{
    return ch <= 'Z' && ch >= 'A';
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        char a[1000];
        cin >>a;
        map<char, int> m;
        m['C'] = 0;
        m['H'] = 0;
        m['O'] = 0;
        m['N'] = 0;
        int l = strlen(a);
        if (isLetter(a[l-1]))
        {
            a[l]='1';
            l++;
        }
        for(int i=0; i<l; i++)
        {
            if(isLetter(a[i]))
            {
                if(isNum(a[i+1]))
                {
                    m[a[i]]+=a[i+1]-48;
                    i++;
                }
                else
                {
                    m[a[i]]+=1;
                }
            }
        }
        cout << 12*m['C'] + m['H']+16*m['O']+14*m['N'] << endl;
    }
    return 0;
}

