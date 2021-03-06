class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n-1;
        while(i > 0 && nums[i-1] >= nums[i]) i--;
        
        if(i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int j = n-1;
        while(j >= i && nums[j] <= nums[i-1]) j--;
        swap(nums[j], nums[i-1]);
        reverse(nums.begin() + i, nums.end());
    }
};
