#include<iostream>
using namespace std;

void heapify(int H[],int N)
{
    int i,j,heap,k,v;
    for(i=(N/2);i>=1;i--)
    {
        k=i;
        v=H[k];
        heap=0;
        while (!heap && (2*k)<=N)
        {
            j=2*k;
            if(j<N)
            {
                if(H[j]<H[j+1])
                    j=j+1;
            }
            if(v>=H[j])
                heap=1;
            else
            {
                H[k]=H[j];
                k=j;
            }
        }
        H[k]=v;
    }
}

void heapsort(int H[], int N)
{
    if(N==0)
        return;
    int temp;
    temp=H[1];
    H[1]=H[N];
    H[N]=temp;
    cout<<H[N]<<" , ";
    heapify(H,N-1);
    heapsort(H,N-1);
}

int main()
{
    int i,j,N;
    cout<<"Enter Size of heap :";
    cin>>N;
    int H[N+1];
    cout<<"\nEnter Values into heap: ";
    for(i=1;i<=N;i++)
        cin>>H[i];
    heapify(H,N);
    cout<<"\nHeapified :";
    for(i=1;i<=N;i++)
        cout<<H[i]<<" , ";
    cout<<"\nSorted : ";
    heapsort(H,N);
    return 0;
}
