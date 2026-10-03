class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;

        for(int x : deck)
            freq[x]++;

        int g = 0;

        for(auto it : freq) {
            g = gcd(g, it.second);
        }

        return g >= 2;
    }
};