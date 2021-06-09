class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) { // lambda表达式，并用auto为其起名matches，通过传引用的方式获取变量
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));//声明了一个vector，元素类型为vector<int>；
                                                         //初始化为包含m+1个vector<int>对象；vector<int>(n+1)表示构造一个无名且含n+1个0的vector<int>对象   
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {//如果字符串p前一位为'*'
                    f[i][j] |= f[i][j - 2]; //按位或
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};
