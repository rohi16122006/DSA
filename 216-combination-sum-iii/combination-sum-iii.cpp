class Solution {
public:
    void solve(int start, int k, int target, vector<int>& current,
         vector<vector<int>>& ans) {
         if(k == 0) {
            if(target == 0)
                ans.push_back(current);
            return;
        }
        for(int i = start; i <= 9; i++) {
            if(i > target)
                break;
            current.push_back(i);
            solve(i + 1, k - 1, target - i, current, ans);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(1, k, n, current, ans);
        return ans;
    }
};