class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            int x = abs(nums[i]);

            nums[x - 1] = -abs(nums[x - 1]);
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }
};