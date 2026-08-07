class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int prefixsum=0;
        int ans=0;
        for(auto num:nums)
        {
            prefixsum+=num;
                if(mp.find(prefixsum-k)!=mp.end())
                ans+=mp[prefixsum-k];
            mp[prefixsum]++;
        }
        return ans;
    }
};