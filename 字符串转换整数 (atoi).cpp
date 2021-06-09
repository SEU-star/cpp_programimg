#include <cstdio>
#include <string>
#include <limits.h>

class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        int i = 0;
        int sign = 1;
        int res = 0;

        while(i < len && s.at(i) == ' ')
            i++;
        int start = i;

        for(; i < len; i++)
        {
            char c = s.at(i);

            if((i == start) && (c == '+'))//位于首位且为+号
                sign = 1;
            else if((i == start) && (c == '-'))//位于首位且为-号
                sign = -1;
            else if((isdigit(c)))//判断是否字符为数字
            {
                int num = c - '0';//是数字就将字符隐式转换为数字
                if(res > INT_MAX / 10 || (res == INT_MAX / 10 && num > INT_MAX % 10))//判断是否越界
                    return INT_MAX;
                if(res < INT_MIN / 10 || (res == INT_MIN / 10 && -num < INT_MIN % 10))//判断是否越界
                    return INT_MIN;
                res = res * 10 + sign * num;//每次循环都要加上去，求最终的数字
            }
            else 
                break;
        }
        return res;
    }
};