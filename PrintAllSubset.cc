#include<bits/stdc++.h>
using namespace std;

void PrintAllSubset(vector<int>arr,int size,int i,vector<int> temp){
    // base case
    if(i == size){
        for(int i = 0; i < temp.size(); i++) {
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return;
    }
    // exclude
    PrintAllSubset(arr,size,i+1,temp);
    // include
    temp.push_back(arr[i]);
    PrintAllSubset(arr,size,i+1,temp);
}
int main(){
    vector<int> arr = {1,2,3};
    vector<int> temp;
    int size = arr.size();
    int i = 0;
    PrintAllSubset(arr,size,i,temp);
}