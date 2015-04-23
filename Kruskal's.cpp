#include<iostream>
using namespace std;
int min_cost=0,graph[20][20],parent[20],V;
void kruskal()
{
    int i,j,mini,a,u,b,v,ver;
    for(ver=0;ver<=V;ver++)
    {
        mini=999;
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                if(graph[i][j]<mini)
                {
                    mini=graph[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        while(parent[u]!=-1)
            u=parent[u];
        while(parent[v]!=-1)
            v=parent[v];
        if(u!=v)
        {
           cout<<"Edge"<<ver<<"\t"<<a<<"->"<<b<<"="<<mini<<"\n";
            min_cost=min_cost+mini;
            parent[v]=u;
        }
        graph[a][b]=graph[b][a]=999;
    }
}

int main()
{
    int i,j;
    cout<<"Enter no. of vertices:";
    cin>>V;
    cout<<"Enter the Adj. matrix:\n";
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
        {
             cin>>graph[i][j];
             if(graph[i][j]==0)
                graph[i][j]=999;
        }

    for(i=0;i<V;i++)
        parent[i]=-1;
    cout<<"\nThe edges of spanning tree are\n";
    kruskal();
    cout<<"\nmin_cost="<<min_cost;
}
