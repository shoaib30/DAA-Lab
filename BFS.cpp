#include<iostream>
using namespace std;
#include <list>
int graph[20][20];
int discovered[20];
int V,sv;
void BFS()
{
    int i,ver;
    discovered[sv]=1;
    list<int> queue;
    queue.push_back(sv);
    while(!queue.empty())
    {
        ver=queue.front();
        for(i=0;i<V;i++)
        {
            if(graph[ver][i]!=0 && discovered[i]==0)
            {
                queue.push_back(i);
                discovered[i]=1;
            }
        }
        cout <<ver << ",";
        queue.pop_front();
    }
}
int main()
{
    int i,j;
    cout<<"Enter the number of vertices: ";
    cin>>V;
    cout<<"\nEnter the Matrix: \n";
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            cin>>graph[i][j];
        }
    }
    for(i=0;i<V;i++)
        discovered[i]=0;
    cout<<"\nEnter the start vertex";
    cin>>sv;
    cout<<"\n\nBFS starting from: "<<sv<<" is:";
    BFS();
    return 0;
}
