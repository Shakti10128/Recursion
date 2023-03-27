class Solution {
public:

void solve1(vector<int> &nums,vector<vector<int>>&ans,vector<int> &temp,vector<bool>vis){
    if(temp.size() == nums.size()){
        ans.push_back(temp);
        return;
    }
    for(int i = 0;i<nums.size();i++){
        if(!vis[i]){
            vis[i] = true;
            temp.push_back(nums[i]);
            solve1(nums,ans,temp,vis);
            temp.pop_back();
            vis[i] = false;
        }
    }
}

void solve2(vector<int> &nums,vector<vector<int>>&ans,int ind){
    if(ind==nums.size()){
        ans.push_back(nums);
    }
    for(int i = ind; i < nums.size();i++){
        swap(nums[ind],nums[i]);
        solve2(nums,ans,ind+1);
        swap(nums[ind],nums[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    // vector<int> temp;
    // int size = nums.size();
    // solution 1
    // vector<bool> vis(nums.size(),0);
    // solve1(nums,ans,temp,vis);

    // solution 2 without using visited extra space
    solve2(nums,ans,0);
    return ans;
}
};
