#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i =0;i<n;i++)
    {
        string s;
        int num = 0;
        cin >> s;
        for(int j=0;j<s.size();j++)
        {
            char c = s.at(j);
            if(c >= '0' && c <= '9')
                num++;
        }
        cout << num <<endl;
    }
    return 0;
}
