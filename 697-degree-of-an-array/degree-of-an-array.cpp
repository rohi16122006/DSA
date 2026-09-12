class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> first;
        unordered_map<int, int> last;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            if(first.find(nums[i]) == first.end())
                first[nums[i]] = i;

            last[nums[i]] = i;
        }
        int degree = 0;
        for(auto x : freq)
            degree = max(degree, x.second);
        int ans = nums.size();
        for(auto x : freq) {
            if(x.second == degree) {
                int len = last[x.first] - first[x.first] + 1;
                ans = min(ans, len);
            }
        }
        return ans;
    }
};