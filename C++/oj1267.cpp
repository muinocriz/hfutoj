#include <iostream>
using namespace std;
static long long  arr[52][52][52]= {0};
long long value=-10000;
long long f(int a,int b,int c)
{
    if(a<0||b<0||c<0)
        return 2;
    if(a>50||b>50||c>50)
        return 1;
    if(arr[a][b][c]>0)
        return arr[a][b][c];
    else
    {
        value = f(a+1,b+2,c+3)+f(a-3,b-2,c-1);
        arr[a][b][c] = value;
        return value;
    }
}

int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        long long num=f(a,b,c);
        cout << num%10000007<<endl;
    }
    return 0;
}
