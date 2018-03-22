#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;

//有一个没有排序，元素个数为2N的正整数数组。要求把它分割为元素个数为N的两个数组，并使两个子数组的和最接近。
static int arr[110];
static  int N=1;
static int SUM = 3;

// 模仿动态规划解0-1背包问题的策略
int solve1()
{
    int i , j , s;
    int dp[2*N+1][N+1][SUM/2+2];

    /*
    用dp(i,j,c)来表示从前i个元素中取j个、且这j个元素之和不超过c的最佳(大)方案，在这里i>=j,c<=S
    状态转移方程：
    限第i个物品　　　　　　　不取　　
    dp(i,j,c)=max{dp(i-1,j-1,c-a[i])+a[i]，dp(i-1,j,c)}
    dp(2N,N,SUM/2+1)就是题目的解。
    */
    //初始化
    memset(dp,0,sizeof(dp));

    for(i = 1 ; i <= 2*N ; ++i)
    {
        for(j = 1 ; j <= min(i,N) ; ++j)
        {
            for(s = SUM/2+1 ; s >= arr[i] ; --s)
            {
                dp[i][j][s] = max(dp[i-1][j-1][s-arr[i]]+arr[i] , dp[i-1][j][s]);
            }
        }
    }

    //因为这为最终答案　dp[2*N][N][SUM/2+1];
    i=2*N , j=N , s=SUM/2;
    while(i > 0)
    {
        if(dp[i][j][s] == dp[i-1][j-1][s-arr[i]]+arr[i])   //判定这个状态是由哪个状态推导出来的
        {
            //cout<<arr[i]<<" ";    //取中arr[i]
            j--;
            s -= arr[i];
        }
        i--;
    }
    if(abs((SUM-2*(dp[2*N][N][SUM/2+1])))*1.0/N  > abs((SUM-2*(dp[2*N][N][SUM/2])))*1.0/N)
        return dp[2*N][N][SUM/2];
    else
        return dp[2*N][N][SUM/2+1];
}

int main()
{
    cin>>N;
    while(N)
    {
        SUM=0;
        for(int i=1;i<=2*N;i++)
        {
            cin>>arr[i];
            SUM+=arr[i];
        }
         cout <<setprecision(1)<< fixed<<showpoint<<abs((SUM-2*solve1()))*1.0/N << endl;
        cin>>N;
    }




    return 0;
}
