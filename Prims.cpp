#include<iostream>
using namespace std;
int graph[20][20];
int V;
int discovered[20],parent[20],key[20];

void print()
{
    int i;
    cout<<"Edge\tWeight\n";
    for(i=1;i<V;i++)
        cout<<parent[i]<<"-"<<i<<"\t"<<key[i]<<endl;
}
int find_min_index()
{
    int i,mini=999,j=0;
    for(i=0;i<V;i++)
    {
        if(discovered[i]!=1 && key[i]<mini)
        {
            mini=key[i];
            j=i;
        }
    }
    return j;
}
void prims()
{
    int i,j,k,mindex;
    for(i=0;i<V;i++)
    {
        discovered[i]=0;
        key[i]=999;
    }
    parent[0]=-1;
    key[0]=0;
    for(i=0;i<V-1;i++)
    {
        mindex=find_min_index();
        discovered[mindex]=1;
        for(j=0;j<V;j++)
        {
            if((key[j]>graph[mindex][j]) && discovered[j]!=1)
            {
                 key[j]=graph[mindex][j];
                 parent[j]=mindex;
            }
        }
    }
}

int main()
{
    int k;
    cout<<"Enter the size of the graph :";
    cin>>V;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin>>k;
            if(k==0)
                k=999;
            graph[i][j]=k;
        }
    }
    prims();
    print();
}
