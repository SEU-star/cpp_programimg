#include <algorithm> //包含min()函数
 
class Solution {
public:
    string convert(string s, int numRows) {
        if(1 == numRows)
            return s;
        vector<string> rows(min(numRows, int(s.size())));//声明至少numRows个string类型变量
        int curRow = 0;
        bool goingDown = false;//换行标志
        for(char c : s)
        {
            rows[curRow] += c;//rows[i]是一个string类型的变量，每次加上c之后都在里面保存着，相当于不停的增加字符串的长度，往里面添加字符。
            if(0 == curRow || numRows-1 == curRow)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string obj;
        for(string temp : rows)//将进行变换后的string对象返回
            obj += temp;//直接加在后面
        return obj;
    }
};