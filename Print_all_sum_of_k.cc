#include<bits/stdc++.h>
using namespace std;

void Print_all_sum_of_k(vector<int> arr,vector<int>&ans,int size,int i,int k,int sum){
    // base case
    if(i >= size){
        if(sum == k){
            for(auto it: ans){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    // include
    sum+=arr[i];
    ans.push_back(arr[i]);
    Print_all_sum_of_k(arr,ans,size,i+1,k,sum);
    // exclude
    ans.pop_back();
    sum-=arr[i];
    Print_all_sum_of_k(arr,ans,size,i+1,k,sum);
}

/*counting the numbers of sum k in presenting array*/

// int Print_all_sum_of_k(vector<int> arr,int size,int i,int k,int sum){
//     // base case
//     if(i >= size){
//         if(sum == k){
//             return 1;
//         }
//         return 0;
//     }
//     // include
//     sum+=arr[i];
//     int ans1 = Print_all_sum_of_k(arr,size,i+1,k,sum);
//     // exclude
//     sum-=arr[i];
//     int ans2 = Print_all_sum_of_k(arr,size,i+1,k,sum);
//     return ans1+ans2;
// }

int main(){
    vector<int> arr = {1,2,1};
    int size = arr.size();
    int i = 0;
    int k = 2;
    vector<int> ans;
    int sum = 0;
    Print_all_sum_of_k(arr,ans,size,i,k,sum);

    /*counting the numbers of sum k in presenting array*/
    // cout<<Print_all_sum_of_k(arr,size,i,k,sum);
}