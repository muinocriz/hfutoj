#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int num,i,j;
    while(cin >> num)
    {
        int n = num;
        int sum=0;
        while(num/10!= 0)
        {
            sum = sum + num %10;
            num /= 10;
        }
        sum = sum + num %10;
        if(n%sum==0)
            cout << "yes" << endl;
        else
            cout << "no" <<endl;
    }
    return 0;
}
