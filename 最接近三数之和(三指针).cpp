class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int best = INT_MAX;
        std::sort(nums.begin(), nums.end());

        auto update = [&](int val)
        {
            if(fabs(val - target) <= fabs(best - target))
                best = val;
        };

        for(int i = 0; i < len; i++)
        {
            int left = i + 1;
            int right = len - 1;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            while(left < right)
            {
                int temp = nums[i] + nums[left] + nums[right];
                if(temp == target)
                    return temp;
                update(temp);
                if(temp > target)
                    right--;
                else
                    left++;
                
                left++;
                right--;
                while(left < right && nums[left] == nums[left-1])
                    left++;
                while(left < right && nums[right] == nums[right+1])
                    right--;
            }
        }
        return best;
    }
};