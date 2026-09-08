class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_set<char> used;
        for(int i = 0; i < s.size(); i++) {
            if(mp.find(s[i]) != mp.end()) {
                if(mp[s[i]] != t[i])
                    return false;
            }
            else {
                if(used.find(t[i]) != used.end())
                    return false;
                mp[s[i]] = t[i];
                used.insert(t[i]);
            }
        }
        return true;
    }
};