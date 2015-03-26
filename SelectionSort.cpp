#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
long length = 1000;
const long max_length = 100000;
int list[max_length];
double total_time,start,end,d1;
void selectionSort()
{
    int temp;
    for(long i=0;i<length-1;i++)
    {
        for(long j=i+1;j<length;j++)
        {
            if(list[i]>list[j])
            {
                temp=list[j];
                list[j]=list[i];
                list[i]=temp;
            }
        }
    }
}
int main()
{
    int i;
    for (i = 0; i < max_length; i++)
    {
        list[i]=rand();
    }
    cout<<"***********SELECTION SORT ************";
    for (;length<=max_length;length+=10000)
    {
        cout << "\n\nLength: " << length;
        start = clock();
        selectionSort();
        end = clock();
        total_time = ((double) (end- start))/CLOCKS_PER_SEC;
        cout<<"\nWORST Time: "<<total_time;
        start = clock();
        selectionSort();
        end = clock();
        total_time = ((double) (end- start))/CLOCKS_PER_SEC;
        cout<<"\nBEST Time: "<<total_time;
    }
    return 0;
}
