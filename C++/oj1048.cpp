#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;

//��һ��û������Ԫ�ظ���Ϊ2N�����������顣Ҫ������ָ�ΪԪ�ظ���ΪN���������飬��ʹ����������ĺ���ӽ���
static int arr[110];
static  int N=1;
static int SUM = 3;

// ģ�¶�̬�滮��0-1��������Ĳ���
int solve1()
{
    int i , j , s;
    int dp[2*N+1][N+1][SUM/2+2];

    /*
    ��dp(i,j,c)����ʾ��ǰi��Ԫ����ȡj��������j��Ԫ��֮�Ͳ�����c�����(��)������������i>=j,c<=S
    ״̬ת�Ʒ��̣�
    �޵�i����Ʒ����������������ȡ����
    dp(i,j,c)=max{dp(i-1,j-1,c-a[i])+a[i]��dp(i-1,j,c)}
    dp(2N,N,SUM/2+1)������Ŀ�Ľ⡣
    */
    //��ʼ��
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

    //��Ϊ��Ϊ���մ𰸡�dp[2*N][N][SUM/2+1];
    i=2*N , j=N , s=SUM/2;
    while(i > 0)
    {
        if(dp[i][j][s] == dp[i-1][j-1][s-arr[i]]+arr[i])   //�ж����״̬�����ĸ�״̬�Ƶ�������
        {
            //cout<<arr[i]<<" ";    //ȡ��arr[i]
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
