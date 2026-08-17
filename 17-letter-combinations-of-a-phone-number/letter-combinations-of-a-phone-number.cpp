class Solution {
public:
    void solve(string& digits, int index, string& current,
               vector<string>& ans, vector<string>& mp) {
        if(index == digits.size()) {
            ans.push_back(current);
            return;
        }
        string letters = mp[digits[index] - '0'];
        for(char ch : letters) {
            current.push_back(ch);
            solve(digits, index + 1, current, ans, mp);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits){
        if(digits.empty())
            return {};
        vector<string> mp = {  "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> ans;
        string current;
        solve(digits, 0, current, ans, mp);
        return ans;
    }
};