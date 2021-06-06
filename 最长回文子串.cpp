#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len < 2)
            return s;
        vector< vector<int> > dp(len, vector<int>(len));
        for(int i = 0; i < len; i++)
            dp[i][i] = 1;
        int maxLen = 1;
        int beginPos = 0;
        //从两个边界出发，如果两个边界不相等，则此边界组成的子串不是回文子串；继续缩小边界进行递归（动态规划）
        for(int L = 2; L <= len; L++)//带等号因为长度可以为len，L是i与j之间的长度
        {
            for(int i = 0; i < len; i++)//左边界
            {
                int j = L + i - 1;//右边界
                if(j >= len)//等号不可省略，因为对于数组来说，下标最大为长度len-1，下标达到len就已经越界了
                    break;
                if(s[i] != s[j])
                    dp[i][j] = 0;
                else
                {
                    if(j - i < 3)
                        dp[i][j] = 1;
                    else
                    {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }

                if(dp[i][j] && (j-i+1) > maxLen) 
                {
                    maxLen = j-i+1;
                    beginPos = i;
                }                   
            }
        }
        return s.substr(beginPos, maxLen);
    }
};