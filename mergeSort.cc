    void merge(int arr[], int s, int mid, int e)
    {
         int i = s,j = mid+1;
         vector<int> a;
         while(i<=mid && j<=e){
             if(arr[i] <= arr[j]){
               a.push_back(arr[i++]);
             }
             else{
                 a.push_back(arr[j++]);
             }
         }
         while(i <= mid){
            a.push_back(arr[i++]);
         }
         while(j<=e){
             a.push_back(arr[j++]);
             
         }
        // copying data from vector a to array arr
        for(int i = s;i<=e;i++){
            arr[i] = a[i-s];
        }
    }
    void mergeSort(int arr[], int s, int e)
    {
        // base case
        if(s == e){
            return;
        }
        int mid = (s+e)/2;
        // left array
        mergeSort(arr,s,mid);
        // right array
        mergeSort(arr,mid+1,e);
        // merge function calling
        merge(arr,s,mid,e);
    }
