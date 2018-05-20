#include<iostream>
#include<algorithm>
using namespace std;

int n,top;
struct Node
{
    int x;
    int y;
}node[60000],Stack[60000];

int dist(Node p1,Node p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

int mult(Node p1,Node p2,Node p0)
{
    return ((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}

int cmp(Node a,Node b)
{
    if(mult(a,b,node[0])>0)
        return 1;
    else if(mult(a,b,node[0])==0&&dist(a,node[0])<dist(b,node[0]))
        return 1;
    return 0;
}

void Gramham()
{
    int i,k =0 ;
    for(i=1;i<n;i++)
    {
    if(node[k].y>node[i].y||((node[k].y==node[i].y)&&node[k].x>node[i].x))
        k=i;
    }
    Node tmp;
    tmp = node[0];
    node[0] = node[k];
    node[k] = tmp;
    sort(node+1,node+n,cmp);
    top=2;
    Stack[0] = node[0];
    Stack[1] = node[1];
    Stack[2] = node[2];
    for(i=3;i<n;i++)
    {
    while(top>1 && mult(node[i],Stack[top],Stack[top-1])>=0)
    top--;
    Stack[++top]=node[i];
    }
}

int main()
{
    int i,j;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            cin>>node[i].x>>node[i].y;
        Gramham();
        int ans=-1;
        for(i=0;i<=top;i++)
        {
            for(j=i+1;j<=top;j++)
            {
            if(ans<dist(Stack[i],Stack[j]))
            ans=dist(Stack[i],Stack[j]);
            }
       }
       cout<<ans<<endl;
    }
    return 0;
}
