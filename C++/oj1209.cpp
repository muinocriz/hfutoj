#include <iostream>
using namespace std;
int main()
{
    int p1,q1;
    while(cin >> p1 >> q1)
    {
        if(p1 == 0 && q1 == 0)
            break;

        int a[p1][q1];
        for(int i = 0; i<p1; i++)
            for(int j=0; j<q1; j++)
                cin >> a[i][j];

        int p2,q2;
        cin >> p2>>q2;
        int b[p2][q2];
        for(int i = 0; i<p2; i++)
            for(int j=0; j<q2; j++)
                cin >> b[i][j];

        int p3,q3;
        cin >> p3 >>q3;
        int c[p3][q3];
        for(int i = 0; i<p3; i++)
            for(int j=0; j<q3; j++)
                cin >> c[i][j];

        if(p2!= q1 || p1 != q2)
        {
            cout << "No" << endl;
            continue;
        }
        if(p3 != q3 || p3 != p1 || p3 != q2)
        {
            cout << "No" <<endl;
            continue;
        }
        int test[p3][q3];
        int sum = 0;
        for(int i=0; i<p1; i++)
        {
            for(int j=0; j<p1; j++)
            {
                sum=0;
                for(int k=0; k<q1; k++)
                {
                    sum = sum + a[i][k]*b[k][j];
                }
                test[i][j] = sum;
            }
        }

        int flag = 1;
        for(int i=0; i<p3; i++)
        {
            for(int j=0; j<q3; j++)
            {
                if(test[i][j] != c[i][j])
                {
                    flag = 0;
                    break;
                }
            }
        }

        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
