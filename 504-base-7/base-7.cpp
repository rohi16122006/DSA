class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        bool negative = num < 0;
        long long n = abs((long long)num);
        string ans = "";
        while(n > 0) {
            ans += char((n % 7) + '0');
            n /= 7;
        }
        if(negative)
            ans += '-';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};