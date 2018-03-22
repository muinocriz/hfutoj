#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    char s;
    int num = 0,word = 0,other = 0;
    while((s=getchar())!= EOF)
    {
        char x = s;
        if(x >= '0' && x <= '9')
            num++;
        else if((x>='a'&&x<='z')||(x>='A'&&x<='Z'))
            word++;
        else
            other++;
    }

    printf("%d %d %d\n", num, word, other);
    return 0;
}
