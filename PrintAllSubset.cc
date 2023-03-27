#include<bits/stdc++.h>
using namespace std;

void PrintAllSubset(vector<int>arr,int size,int i,vector<vector<int>>&ans,vector<int> temp){
    // base case
    if(i == size){
        ans.push_back(temp)
        return;
    }
    // exclude
    PrintAllSubset(arr,size,i+1,ans);
    // include
    ans.push_back(arr[i]);
    PrintAllSubset(arr,size,i+1,ans);
}
int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>>ans;
    vector<int> temp;
    int size = arr.size();
    int i = 0;
    PrintAllSubset(arr,size,i,ans,temp);
}