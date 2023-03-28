#include <bits/stdc++.h> 
using namespace std;

bool isSafe(int row,int col,int n,vector<string> &board){
    int tempCol = col,tempRow = row;
    // for up diognal
    while(row >=0 && col >=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--,col--;
    }
    // for left horizontal
    row = tempRow,col = tempCol;
    while(col >=0){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;
    }
    // for botton diognal
    row = tempRow,col = tempCol;
    while(row < n && col >=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row++,col--;
    }
    // if no one become false it means this cell is safe for placing queen
    return true;
}


void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
    // base case
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row = 0;row<n;row++){
        if(isSafe(row,col,n,board)){
            board[row][col] = 'Q';
            solve(col+1,board,ans,n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> NQueen(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i = 0; i < n;i++){
        board[i] = s;
    }
    solve(0,board,ans,n);
    return ans;
}

int main(){
    int n = 4;
    vector<vector<string>> ans = NQueen(n);
    for(int i = 0; i<n; i++){
        for(int j = 0;j<ans[0].size();j++){
            string s = ans[i][j];
            for(int k = 0; k<s.length();k++){
                cout<<s[k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}