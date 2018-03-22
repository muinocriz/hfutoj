#include <iostream>
using namespace std;
int main()
{
    int k,i,j;
    int count=1;
    cin >> k;
    while(k--)
    {
        string s;
        string test="13";
        cin >> s;
        if(s.find(test)==string::npos)
            cout << "Case #" << count<<": Yes, I like it!"<< endl;
        else
            cout << "Case #" << count<<": No, it's terrible!" <<endl;
        count++;
    }
    return 0;
}
