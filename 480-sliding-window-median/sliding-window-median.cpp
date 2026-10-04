class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> left, right;
        vector<double> ans;

        auto balance = [&]() {
            while(left.size() > right.size() + 1) {
                auto it = prev(left.end());
                right.insert(*it);
                left.erase(it);
            }

            while(left.size() < right.size()) {
                auto it = right.begin();
                left.insert(*it);
                right.erase(it);
            }
        };

        auto add = [&](int x) {
            if(left.empty() || x <= *prev(left.end()))
                left.insert(x);
            else
                right.insert(x);

            balance();
        };

        auto remove = [&](int x) {
            auto it = left.find(x);

            if(it != left.end())
                left.erase(it);
            else {
                it = right.find(x);
                right.erase(it);
            }

            balance();
        };

        for(int i = 0; i < k; i++)
            add(nums[i]);

        for(int i = k; ; i++) {

            if(k % 2 == 1)
                ans.push_back((double)*prev(left.end()));
            else
                ans.push_back(((double)*prev(left.end()) +
                               (double)*right.begin()) / 2.0);

            if(i == nums.size())
                break;

            remove(nums[i - k]);
            add(nums[i]);
        }

        return ans;
    }
};