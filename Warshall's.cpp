#include<iostream>
using namespace std;
int V;
int graph[20][20];
void warshall()
{
    int i,j,k;
    for(k=0;k<V;k++)
    {
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                graph[i][j]=(graph[i][j] || (graph[i][k] && graph[k][j]));
            }
        }
    }
}
int main()
{
    int i,j;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    cout<<"Enter the adj matrix :\n";
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            cin>>graph[i][j];
        }
    }
    warshall();
    cout<<"\n\nTransitive Closure:\n";
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
}
