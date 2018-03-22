#include <iostream>
using namespace std;

int main()
{
    int count;
    char c[6];
    while(cin>>c)
    {
        count=0;
        int num = (c[0]-48)*10+c[1]-48+(c[3]-48)*10+c[4]-48;
        while(num)
        {
            if(num%2==1)
                count++;
            num/=2;
        }
        if(count%2==1)
            cout <<"Run!"<<endl;
        else
            cout << "Stay~~" << endl;
    }
    return 0;
}
