class Solution {
public:

    void backtrack(vector<string>& ans, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& res)
    {
        if(index == digits.length())
            ans.push_back(res);
        else
        {
            char c = digits[index];
            const string& letters = phoneMap.at(c);
            for(const char& letter : letters)
            {
                res.push_back(letter);
                backtrack(ans, phoneMap, digits, index+1, res);
                res.pop_back();//弹出临时存放空间，以供下次使用，不弹出会导致res越来越大
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        if(len == 0)
            return {};
        
        std::unordered_map<char, string> phoneMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        string res;
        vector<string> ans;
        backtrack(ans, phoneMap, digits, 0, res);
        return ans;
    }
};