class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> need(26, 0);

        for(char ch : licensePlate) {
            if(isalpha(ch)) {
                ch = tolower(ch);
                need[ch - 'a']++;
            }
        }
        string ans = "";
        for(string word : words) {
            vector<int> have(26, 0);
            for(char ch : word)
                have[ch - 'a']++;
            bool possible = true;
            for(int i = 0; i < 26; i++) {
                if(have[i] < need[i]) {
                    possible = false;
                    break;
                }
            }
            if(possible && (ans == "" || word.size() < ans.size()))
                ans = word;
        }
        return ans;
    }
};