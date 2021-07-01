class Solution {
public:
    
    double quickPow(double x, long long n)
    {
        double ans = 1.0;
        double x_contribute = x;
        while(n > 0)
        {
            if(n % 2 == 1)
                ans = ans * x_contribute;
            x_contribute *= x_contribute;
            n = n / 2; 
        }
        return ans;
    }

    double myPow(double x, int  n) {
        long long N = n;
        if(N > 0)
            return quickPow(x, N);
    return N >= 0 ? quickPow(x, N) : 1.0 / quickPow(x, -N);
    }
};