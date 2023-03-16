#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[],int start,int end){
    // base case
    if(start>=end){
        return;
    }
    
    // swap both value of start and end
    swap(arr[start],arr[end]); 

    // recursion calls
    reverseArray(arr,start+1,end-1);
}


int main(){
    int arr[20] = {4,3,2,1,5,6};
    int size = 6;
    int start = 0;
    int end = size-1;
    reverseArray(arr,start,end);
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
}