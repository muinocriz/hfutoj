#include <cstdio>
#include <iostream>
#include<cstring>
using namespace std;
int a[100005][15];
int f[100005][15];
int main()
{
    int n;
    while( cin >> n)
    {
        memset(a,0,sizeof(a));				//初始化a，f数组并初始化为0
        memset(f,0,sizeof(f));
        int x,t;
        int maxn=0,res=0;
        while(n--)
        {
            cin>>x;							//位置
            cin>>t;							//掉下馅饼时间
            //scanf("%d%d",&x,&t);
            ++a[t][x+1];                    //整体向右便宜1个，避免编辑判断
            maxn=max(maxn,t);
        }

        f[1][5]=a[1][5];
        f[1][6]=a[1][6];                    //初始位置由5移到6
		f[1][7]=a[1][7];
        for(int i=2; i<=maxn; i++)
        {
            for(int j=1; j<12; j++)			//十个位置
            {
                f[i][j]=max(f[i-1][j+1],max(f[i-1][j],f[i-1][j-1]));
                f[i][j]=f[i][j]+a[i][j];	//只是在第i秒捡到馅饼的最大收益，下一秒要重新计算
            }
        }
        for(int j=1; j<12; j++)
            res=max(res,f[maxn][j]);
        cout<<res<<endl;
        //printf("%d\n",res);
    }
    return 0;
}
