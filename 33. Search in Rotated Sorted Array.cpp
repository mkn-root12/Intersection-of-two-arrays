class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if (nums.size() == 0)
        {
            return -1;
        }
        
        int start = 0;
        int end = (int)nums.size() - 1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] == target)
            {
                return mid;
            }
            
            if (nums[mid] > nums[end])
            {
                if (target >= nums[start] && target < nums[mid])
                {
                    end = mid;
                }
                else
                {
                    start = mid;
                }
                
            }
            else if(nums[mid] < nums[end])
            {
                if (target > nums[mid] && target <= nums[end])
                {
                    start = mid;
                }
                else
                {
                    end = mid;
                }
            }
            else
            {
                end -= 1;
            }
        }
        
        if (nums[start] == target)
        {
            return start;
        }
        
        if (nums[end] == target)
        {
            return end;
        }
        
        return -1;
    }
};
