class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;

        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-'))
            i++;

        bool digit = false;
        bool dot = false;
        bool exp = false;
        bool expDigit = true;

        while (i < n) {
            if (isdigit(s[i])) {
                digit = true;
                if (exp)
                    expDigit = true;
            }
            else if (s[i] == '.') {
                if (dot || exp)
                    return false;
                dot = true;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                if (exp || !digit)
                    return false;

                exp = true;
                expDigit = false;

                if (i + 1 < n && (s[i + 1] == '+' || s[i + 1] == '-'))
                    i++;
            }
            else {
                return false;
            }

            i++;
        }

        return digit && expDigit;
    }
};