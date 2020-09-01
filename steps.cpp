#include<bits/stdc++.h>
using namespace std;
#include <stdio.h>

int board[20],count;
void print(int n)
{
 int i,j;
 printf("\n");
 
 
  
 
 for(i=1;i<=n;++i)
 {
  
  for(j=1;j<=n;++j) //for nxn board
  {
   if(board[i]==j)
    printf("1"); //queen at i,j position
   else
    printf("0"); //empty slot
  }
 }
}
 
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  //checking column and digonal conflicts
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
 }
 
 return 1; //no conflicts
}
 
//function to check for proper positioning of queen
void placeNQueens(int n,int row=1)
{
 int column;
 for(column=1;column<=n;++column)
 {
  if(place(row,column))
  {
   board[row]=column; //no conflicts so place queen
   if(row==n) //dead end
    print(n); //printing the board configuration
   else //try queen with next position
    queen(row+1,n);
  }
 }
}

int main(){
    
}