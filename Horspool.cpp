#include<iostream>
#include<cstring>
#include <ctime>
#define MAX 5000
using namespace std;
int t[MAX];
double total_time,start,end;
void shifttable(char p[])
{
    int i,j,m;
    m=strlen(p);
    for(i=0;i<MAX;i++)
        t[i]=m;
    for(j=0;j<m-1;j++)
        t[p[j]]=m-1-j;
}
int horspool(char src[],char p[])
{
    int i,j,k,m,n;
    n=strlen(src);
    m=strlen(p);
    cout<<"\nLength of text="<<n;
    cout<<"\n Length of pattern="<<m;
    i=m-1;
    while(i<n)
    {
        k=0;
        while((k<m)&&(p[m-1-k]==src[i-k]))
             k++;
        if(k==m)
            return(i-m+1);
        else
            i+=t[src[i]];
    }
    return -1;
}
int main()
{
    char src[100],p[100];
    int pos;
    cout<<"Enter the text in which pattern is to be searched:\n";
    cin>>src;
    cout<<"Enter the pattern to be searched:\n";
    cin>>p;
    shifttable(p);
    start = clock();
    pos=horspool(src,p);
    end = clock();
    total_time = ((double) (end- start))/CLOCKS_PER_SEC;
    cout<<"\nTime taken: "<<total_time<<"\n";
    if(pos>=0)
        cout<<"\n The desired pattern was found starting from position "<<pos+1;
    else
        cout<<"\n The pattern was not found in the given text\n";
    return 0;
}

