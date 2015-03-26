#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
long length = 1000;
const long max_length = 100000;
int list[max_length];
double total_time,start,end;
void mer(int p,int q,int r)
{
    int i=0,j=p,k=q+1,temp[length];
    while(j<=q&&k<=r)
    {
        if(list[j]<list[k])
            temp[i++]=list[j++];
        else
            temp[i++]=list[k++];
    }
    while(j<=q)
        temp[i++]=list[j++];
    while(k<=r)
        temp[i++]=list[k++];
    for(k=p,j=0;k<=r;k++,j++)
        list[k]=temp[j];
}
void mergesort(int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        mergesort(p,q);
        mergesort(q+1,r);
        mer(p,q,r);
    }
}
int main()
{
    int i;
    for (i = 0; i < max_length; i++)
    {
        list[i] = rand();
    }
    cout<<"~~~~~~~~MERGE SORT~~~~~~~~~~";
    for (length = length; length <= max_length;length+=10000 )
    {
        cout << "\n\nLength: " << length;
        start = clock();
        mergesort(0,length-1);
        end = clock();
        total_time = ((double) (end- start))/CLOCKS_PER_SEC;
        cout<<"\nWORST Time:"<<total_time;
        start = clock();
        mergesort(0,length-1);
        end = clock();
        total_time = ((double) (end- start))/CLOCKS_PER_SEC;
        cout<<"\nBEST Time:"<<total_time;
    }
    return 0;
}
