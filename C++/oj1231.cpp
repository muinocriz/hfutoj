#include <iostream>
using namespace std;
int main()
{
    int n,m,a,b;
    while(cin >> n >>m>>a>>b)
    {
        int c = min(n/a,m/b);
        if(c == 0)
            cout << "Blind my dog eyes." <<endl;
        else
            cout <<c <<endl;
    }
    return 0;
}
