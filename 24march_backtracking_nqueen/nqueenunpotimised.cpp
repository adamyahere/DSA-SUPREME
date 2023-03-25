#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col , vector<vector<char>> &board, int n){
    //check if you can place the queen on the current cell 
    int i = row;
    int j = col;
    
    //check row
    while(j>=0){
        if(board[i][j] == 'Q'){
            return false;
        }
        j--;
    }
    //diagonal row
    i = row ;
    j = col ;
    while( i < n && j>= 0 ){
        if(board[i][j] == 'Q'){
            return false;
        }
        i++;
        j--;
    }
    i = row ;
    j = col ;
    while( i >= 0 && j>= 0 ){
        if(board[i][j] == 'Q'){
            return false;
        }
        i--;
        j--;
    }
    //kahin queen nhi mili iska mutlb true return krdo!!!
    return true;
}

void printSolution(vector<vector<char>> &board , int n ){
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<n ; j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
void solve( vector<vector<char>> &board, int col , int n){
    //base case
    if( col >= n ){
        printSolution(board,n);
        return;
        
    }
    
    
    //1 case sove baki recursion
    for(int row = 0; row<n ; row++){
        if(isSafe(row,col,board,n)){
            //rakh do
            board[row][col] = 'Q';
            //recursion le aega soln
            solve(board,col+1,n);
            // backtracking
            board[row][col] = 0;
        }
    }
    
}

int main() {
    int n = 5;
    vector<vector<char>> board (n,vector<char>(n,'`'));
    int col = 0 ;
    solve(board, col , n);
    

    return 0;
}
