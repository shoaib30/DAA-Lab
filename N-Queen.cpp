#include<iostream>
using namespace std;
#define N 4
void print(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout<<board[i][j]<<" ";
        cout<<"\n";
    }
}
int isSafe(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)//Check this row on left side
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)//Check upper diagonal on left side
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j//Check lower diagonal on left side
        if (board[i][j])
            return false;
    return true;
}
int Nqueen(int board[N][N], int col)
{
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++)
    {
        if ( isSafe(board, i, col) )
        {
            board[i][col] = 1;
            if ( Nqueen(board, col + 1) == true )
                return true;
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}
int main()
{
    int board[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            board[i][j]=0;
    if ( Nqueen(board, 0) == false )
      cout<<"Solution does not exist";
    print(board);
    return 0;
}