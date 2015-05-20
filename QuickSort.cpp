#include<time.h>
#include<iostream>
#include <cstdlib>
using namespace std;
long int partition(int list[],long int low,long int hi)
{
    int key=list[low];
    long int i=low,j=hi+1;
    int temp;
    int flag=1;
    while(flag)
    {
        while(list[i]<key)
            i++;
        do{
            j--;
        }while(list[j]>key);
        if(i<j)
        {
            temp=list[i];
            list[i]=list[j];
            list[j]=temp;
        }
        else
            flag=0;
    }
    temp=list[low];
    list[low]=list[j];
    list[j]=temp;
    return j;
}
void qs(int list[],long int low ,long int hi)
{
    if(low>hi)
        return;
    long int key=partition(list,low,hi);
    qs(list,low,key-1);
    qs(list,key+1,hi);
}
int main()
{
    clock_t start,end;
    long int i;
    double time;
    const long int max_length=100000;
    int list[max_length];
    for(i=0;i<max_length;i++)
    {
            list[i]=rand();
    }
    cout<<"********QUICK SORT*********";
    for(i=1000;i<max_length;i+=10000)
    {
        cout<<"\nSize:"<<i;
        start=clock();
        qs(list,0,i);
        end=clock();
        time=(double)(end-start)/CLOCKS_PER_SEC;
        cout<<"\nBEST time:"<<time;
        start=clock();
        qs(list,0,i);
        end=clock();
        time=(double)(end-start)/CLOCKS_PER_SEC;
        cout<<"\nWORST time:"<<time<<endl;
    }
    return 0;
}
