#include<bits/stdc++.h>
using namespace std;

void mergeArray(vector<int> left,int size1,vector<int> right,int size2,vector<int>&arr){
    int i = 0,j = 0,index = 0;
    while(i < size1 && j <size2){
        if(left[i] <= right[j]){
            arr[index++] = left[i++];
        }
        else{
            arr[index++] = right[j++];
        }
    }
    while(i<size1){
        arr[index++] = left[i++];
    }
    while(j<size2){
       arr[index++] = right[j++];
    }
}

void mergeSort(vector<int> &arr,int size){
    if(size<=1){
        return;
    }
    int size1 = size/2;
    int size2 = size-size1;
    vector<int> left;
    vector<int> right;
    for(int i = 0; i<size1;i++){
        left.push_back(arr[i]);
    }
    for(int i = size1;i<size;i++){
        right.push_back(arr[i]);
    }
    mergeSort(left,size1);
    mergeSort(right,size2);
    mergeArray(left,size1,right,size2,arr);
}

int main(){
    vector<int> arr = {4,7,1,5,3,6,9,0,1};
    int size = arr.size();
    mergeSort(arr,size);
    for(auto it: arr){
        cout<<it<<" ";
    }
}