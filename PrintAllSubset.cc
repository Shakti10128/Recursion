#include<bits/stdc++.h>
using namespace std;

void PrintAllSubset(vector<int>arr,int size,int i,vector<int> ans){
    // base case
    if(i == size){
        for(auto val:ans){
            cout<<val<<" ";
        }
        cout<<endl;
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
    vector<int> ans;
    int size = arr.size();
    int i = 0;
    PrintAllSubset(arr,size,i,ans);
}