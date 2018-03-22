#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
const int n = 10009;
char a[n];
char t[n*2];
int cnt[n*2];

void change()
{
    int len = strlen(a);
    t[0]='@';
    for(int i=0; i<len; i++)
    {
        t[i*2+1]='#';
        t[i*2+2]=a[i];
    }
    t[len*2+1]='#';
    t[len*2+2]='\0';
}

int manacher()
{
    memset(cnt,0,sizeof(cnt));
    cnt[0]=cnt[1]=1;
    int id=1;
    int ans=1;
    int len=strlen(t);
    for(int i=2; i<=len; i++)
    {
        int num = min(cnt[id*2-i],cnt[id]+id-i);
        while(t[i-num]==t[i+num])
            num++;
        cnt[i]=num;
        if(id+cnt[id]<i+num)
            id=i;
        if(ans<num)
            ans=num;
    }
    return ans;
}

int main()
{
    memset(t, 0, sizeof(t));
        memset(a, 0, sizeof(a));
    cin>>a;
    while(a[0]!='#')
    {

        change();



        memset(cnt,0,sizeof(cnt));
        cnt[0]=cnt[1]=1;
        int id=1;
        int ans=1;
        int len=strlen(t);
        int num,i,i1=-1;
        for( i=2; i<=len; i++)
        {
             num = min(cnt[id*2-i],cnt[id]+id-i);
            while(t[i-num]==t[i+num])
                num++;
            cnt[i]=num;
            if(id+cnt[id]<i+num)
                id=i;
            if(ans<num)
                {ans=num;i1=i;}
        }
        ans-=1;
        //cout <<"ans:    "<< ans << endl;
        //cout <<"id      "<< id << endl;
        //cout <<"i1:     "<<i1<<endl;
        //cout <<"qishi:  "<<((i1-ans+1)-2)/2<<endl;
        int begin = ((i1-ans+1)-2)/2;
        for(i=begin;i<begin+ans;i++)
            cout << a[i];
        cout << endl;
         memset(t, 0, sizeof(t));
        memset(a, 0, sizeof(a));
        cin>>a;
    }

    return 0;
}

