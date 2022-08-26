869. Reordered Power of 2
You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

 

Example 1:

Input: n = 1
Output: true
Example 2:

Input: n = 10
Output: false
 

Constraints:

1 <= n <= 109
  
  //solution
  class Solution {
public:
    vector<int> count(int N){
        vector<int> ans(10);
        while(N){
            ans[N%10]++;
            N /= 10;
        }
        return ans;
    };
    
    bool reorderedPowerOf2(int N) {
        vector<int> arr = count(N);
        //pow(2,30) is 1073741824
        //and N's upper bound is pow(10,9)
        for(int i = 0; i < 31; i++){
            if(arr == count(1 << i)){
                return true;
            }
        }
        return false;
    }
};
