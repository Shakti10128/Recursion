#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &arr,int start,int end){
    int pivot = arr[start];
    int i = start;
    int j = end;
    while(i<j){
        while(arr[i] <= pivot && i <=end-1){
            i++;
        }
        while(arr[j] > pivot && j >=start+1){
            j--;
        }
        if(arr[i] > pivot && arr[j] <pivot){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[start]);
    return j;
}

void QuickSort(vector<int> &arr,int start,int end){
    if(start<end){
        int pivot = findPivot(arr,start,end);
        QuickSort(arr,start,pivot-1);
        QuickSort(arr,pivot+1,end);
    }
}

int main(){
    vector<int> arr = {4,9,1,6,3,0,3,1,0};
    int end = arr.size()-1;
    int start = 0;
    QuickSort(arr,start,end);
    for(auto it: arr){
        cout<<it<<" ";
    }
}