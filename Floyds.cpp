#include<iostream>
using namespace std;
int V;
int graph[20][20];
int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
void floyds()
{
    int i,j,k;
    for(k=0;k<V;k++)
    {
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                graph[i][j]=min(graph[i][j],(graph[i][k]+graph[k][j]));
            }
        }
    }
}
int main()
{
    int i,j,x;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    cout<<"Enter the adj matrix :\n";
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            cin>>x;
            if(x==0&&i!=j)
                x=999;
            graph[i][j]=x;
        }
    }
    floyds();
    cout<<"\n\nAll Pair Shortest path : \n";
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n\n\n";
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            if(i!=j)
                cout<<"["<<i<<","<<j<<"]="<<graph[i][j]<<"\n";
        }
    }
    return 0;
}
