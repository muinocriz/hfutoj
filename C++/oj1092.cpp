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
        memset(a,0,sizeof(a));				//��ʼ��a��f���鲢��ʼ��Ϊ0
        memset(f,0,sizeof(f));
        int x,t;
        int maxn=0,res=0;
        while(n--)
        {
            cin>>x;							//λ��
            cin>>t;							//�����ڱ�ʱ��
            //scanf("%d%d",&x,&t);
            ++a[t][x+1];                    //�������ұ���1��������༭�ж�
            maxn=max(maxn,t);
        }

        f[1][5]=a[1][5];
        f[1][6]=a[1][6];                    //��ʼλ����5�Ƶ�6
		f[1][7]=a[1][7];
        for(int i=2; i<=maxn; i++)
        {
            for(int j=1; j<12; j++)			//ʮ��λ��
            {
                f[i][j]=max(f[i-1][j+1],max(f[i-1][j],f[i-1][j-1]));
                f[i][j]=f[i][j]+a[i][j];	//ֻ���ڵ�i����ڱ���������棬��һ��Ҫ���¼���
            }
        }
        for(int j=1; j<12; j++)
            res=max(res,f[maxn][j]);
        cout<<res<<endl;
        //printf("%d\n",res);
    }
    return 0;
}
