#include<iostream>
#include<math.h>
using namespace std;
int board[100][100],n,x[100];
int feasible(int, int);
int count = 0;
void printsolution()
{count++;
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++)
		{
			cout<<board[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void nqueen(int row)
{
	int i,j;
	if(row<n)
	{	
		for(i=0;i<n;i++)
		{
			if(feasible(row,i)==1)
			{	
				board[row][i]=1;
				x[row]=i;//x[i] represents the column of queen in row i
				//put queen and go to next row
				nqueen(row+1);
				//function will return only if its not valid or if a solution is found so erase that queen
				board[row][i]=0;
				x[row]=999;
			}
		}
	}
	else
	{
		cout<<"\nThe solution :\n";
		printsolution();
	}
}
int abs(int a,int b)
{
	int c;
	c=a-b;
	if(c<0)
		return -c;
	else return c;
}

int feasible(int row,int column)
{
	int crow;
	for(crow=0;crow<row;crow++)
	{
	 	if((x[crow]==column) || abs(x[crow],column) == abs (row,crow) )
	 		return 0;
	}
	return 1;
}



int main()
{
	cout<<"\nEnter the number of queens";
	cin>>n;
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++)
		{
			board[i][j]=0;
			x[i]=999;
		}
	}
	nqueen(0);
	cout<<"\n"<<count;
	return 0;
}
