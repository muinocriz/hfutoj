#include <iostream>
using namespace std;
int a[1005]={0};
void quicksort(int left, int right)
{
    int i ,j, t, temp;
    if(left > right)
        return;

    temp = a[left];//temp�洢��׼��
    i = left;
    j = right;
    while (i != j)
    {
        //˳�����Ҫ��Ҫ�ȴ���������
        while (a[j] >= temp && i < j)
            j--;

        //�ٴ���������
        while (a[i] <= temp && i < j)
            i++;

        //�����������������е�λ��
        if (i < j)//i j û������
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    //������λ
    a[left] = a[i];
    a[i] = temp;

    quicksort(left, i-1);
    quicksort(i+1, right);
}
int main()
{
 int t,i,j,k;
 cin >>t;
 while(t--)
 {
     int n;
     cin >> n;
     for(i=0;i<n;i++)
        cin >> a[i];
     quicksort(0, n-1);
     int b[1005];

     for(i=0;i<n;i++)
     {
         b[i] = a[n-1-i];
     }
     int count=1;
     cin >>k;
     if(k==1)
        {cout << b[0] << endl;continue;}

     for(i=1;i<n;i++)
     {
         if(b[i]!=b[i-1])
            count++;
         if(k==count)
         {
             cout << b[i] << endl;
             break;
         }
     }
 }
 return 0;
}
