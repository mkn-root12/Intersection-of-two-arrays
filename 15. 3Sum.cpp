class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        set<vector<int>> ansSet;
        
        for(int left = 0; left <= N-3; left++){
            int mid = left+1, right = N-1;
            while(mid < right){
                if(nums[left] + nums[mid] + nums[right] == 0){
                    ansSet.insert({nums[left], nums[mid], nums[right]});
                    mid++; right--;
                }else if(nums[left] + nums[mid] + nums[right] < 0){
                    mid++;
                }else{
                    right--;
                }
            }
        }

        vector<vector<int>> ans(ansSet.begin(), ansSet.end());
        
        return ans;
    }
};
