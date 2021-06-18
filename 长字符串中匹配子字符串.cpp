class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if(m == 0)
            return 0;

        for(int i = 0; i + m <= n; i++)
        {
            bool status = true;
            for(int j = 0; j < m; j++)
            {
                if(haystack[i+j] != needle[j])
                    status = false;
            }
            if(status)
                return i;                
        }
        return -1;
    }
};