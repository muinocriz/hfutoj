#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
int main()
{
    int i,j,count;
    string word;
    string line;
    string begin="$",end="$";
    while(getline(cin, word))
    {
        transform(word.begin(),word.end(),word.begin(), ::tolower);
        getline(cin, line);
        transform(line.begin(),line.end(),line.begin(), ::tolower);
        line = begin+line+end;
        j=word.size();
        count=0;
        i=0;
        while(1)
        {
            i=line.find(word,i);
            if(i!=string::npos )
            {
                //cout << "in1"<<"      i=  "<<i<<endl;
                char c1= line.at(i-1);
                char c2= line.at(i+j);
                if(!isalpha(c1) && !isalpha(c2))
                {
                    count++;
                }
                i++;
            }
            else
                break;
        }
        cout << count <<endl;
    }
    return 0;
}
