#include<iostream>
using namespace std;

int w[10],p[10],v[10][10];

int max(int i,int j)
{
    return ((i>j)?i:j);
}
int knap(int i,int j)
{
    int value;
    if(v[i][j]<0)
    {
        if(j<w[i])
            value=knap(i-1,j);
        else
            value=max(knap(i-1,j),p[i]+knap(i-1,j-w[i]));
        v[i][j]=value;
    }
    return(v[i][j]);
}
int main()
{
    int i,j,n,x[10]={0},cap;
    int profit,count=0;
    cout<<"\nEnter the number of elements\n";
    cin>>n;
    cout<<"Enter the profit and weights of the elements\n";
    for(i=1;i<=n;i++)
    {
        cout<<"For item no "<<i<<endl;
        cin>>p[i]>>w[i];
    }
    cout<<"\nEnter the capacity \n";
    cin>>cap;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=cap;j++)
        {
            if((i==0)||(j==0))
                v[i][j]=0;
            else
                v[i][j]=-1;
         }
    }
    profit=knap(n,cap);
    i=n;
    j=cap;
    while(j!=0&&i!=0)
    {
        if(v[i][j]!=v[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
        i--;
    }
    cout<<"Items included are\n";
    cout<<"Sl.no\tweight\tprofit\n";
    for(i=1;i<=n;i++)
        if(x[i])
            cout<<++count<<"\t"<<w[i]<<"\t"<<p[i]<<"\n";
    cout<<"Total profit = "<<profit;
    return 0;
}
