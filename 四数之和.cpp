class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        if(len < 4)
            return ans;

        for(int i = 0; i < len; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < len; j++)
            {
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;
                int left = j + 1;
                int right = len - 1;
                while(left < right)
                {
                    int num = nums[i] + nums[j] + nums[left] + nums[right];
                    if(num < target)
                        left++;
                    else if(num > target)
                        right--;
                    else
                    {
                        ans.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left+1])
                            left++;
                        while(left < right && nums[right] == nums[right-1])
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};