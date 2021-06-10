class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if(len < 3)
            return {};
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < len; i++)
        {
            int left = i+1;
            int right = len - 1;
            if (i > 0 && nums[i] == nums[i-1])  continue;
            while(left < right)
            {
                if(nums[left] + nums[right] + nums[i] > 0)
                    right--;
                else if(nums[left] + nums[right] + nums[i] < 0)
                    left++;
                else
                {
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1])
                        left++;
                    while(left < right && nums[right] == nums[right+1])
                        right--;
                }
            }
        }
        return ans;
    }
};