#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int i,j,k;
    string s,t="";
    while(getline(cin,s))
    {
        k=0;
        for(i=0; i<s.size(); i++)
        {
            if(isalpha(s.at(i)))
            {
                t += s.at(i);
            }
            else
            {
                for(j=t.size()-1; j>=0; j--)
                    cout << t.at(j);
                cout << s.at(i);
                t="";
            }
        }
        for(j=t.size()-1; j>=0; j--)
            cout << t.at(j);
        t="";
        cout << endl;
    }


    return 0;
}
