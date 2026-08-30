class Solution {
public:
    long long sumMin(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> left(n), right(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            if(st.empty())
                left[i] = i + 1;
            else
                left[i] = i - st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if(st.empty())
                right[i] = n - i;
            else
                right[i] = st.top() - i;
            st.push(i);
        }
        for(int i = 0; i < n; i++) {
            ans += (long long)nums[i] * left[i] * right[i];
        }
        return ans;
    }
    long long sumMax(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> left(n), right(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            if(st.empty())
                left[i] = i + 1;
            else
                left[i] = i - st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if(st.empty())
                right[i] = n - i;
            else
                right[i] = st.top() - i;
            st.push(i);
        }
        for(int i = 0; i < n; i++) {
            ans += (long long)nums[i] * left[i] * right[i];
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
    }
};