class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);
        while(ss >> word) {
            words.push_back(word);
        }
        if(pattern.size() != words.size())
            return false;
        unordered_map<char, string> mp;
        unordered_set<string> used;
        for(int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            if(mp.find(ch) != mp.end()) {
                if(mp[ch] != words[i])
                    return false;
            }
            else {
                if(used.find(words[i]) != used.end())
                    return false;
                mp[ch] = words[i];
                used.insert(words[i]);
            }
        }
        return true;
    }
};