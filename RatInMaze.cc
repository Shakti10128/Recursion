#include <bits/stdc++.h> 
using namespace std;
bool isSafe(vector<vector<int>> &arr,int n,int row,int col,vector<vector<int>>&vis){
    if((row >= 0 && row < n) && (col>=0 && col < n) && arr[row][col] == 1 && vis[row][col]==0){
        return true;
    }
    else{
        return false;
    }
}
void solve(vector<vector<int>> &arr,int n,int row,int col,vector<string>&ans,vector<vector<int>>&vis,string path){
    // base case
    if(row == n-1 && col == n-1){
        ans.push_back(path);
        return;
    }
    // mark cell as visited
    vis[row][col] = 1;

    // check for down
    if(isSafe(arr,n,row+1,col,vis)){
        solve(arr,n,row+1,col,ans,vis,path+'D');
    }
    
    // check for left
    if(isSafe(arr,n,row,col-1,vis)){
        solve(arr,n,row,col-1,ans,vis,path+'L');
    }
    // check for right
    if(isSafe(arr,n,row,col+1,vis)){
        solve(arr,n,row,col+1,ans,vis,path+'R');
    }
    // check for up
    if(isSafe(arr,n,row-1,col,vis)){
        solve(arr,n,row-1,col,ans,vis,path+'U');
    }
    // if path is not possible
    // bactracking
    vis[row][col] = 0;
}
    
vector<string> searchMaze(vector<vector<int>> & arr, int n){
    vector<string> ans;
    vector<vector<int>> visited(n,vector<int>(n,0));
    string path = "";
    if(arr[0][0]==0){
        return ans;
    }
    solve(arr,n,0,0,ans,visited,path);
    return ans;
}
int main(){
    vector<vector<int>> arr={{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};
    int n = 4;
    vector<string> ans = searchMaze(arr,n);
    for(auto it: ans){
        cout<<it<<endl;
    }
}