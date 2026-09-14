class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int rows = m;
        int cols = n;
        for(auto op : ops) {
            rows = min(rows, op[0]);
            cols = min(cols, op[1]);
        }
        return rows * cols;
    }
};