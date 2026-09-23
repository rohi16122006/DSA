class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0;
        int sumB = 0;

        for(int x : aliceSizes)
            sumA += x;

        for(int x : bobSizes)
            sumB += x;

        int diff = (sumA - sumB) / 2;

        unordered_set<int> bob;

        for(int x : bobSizes)
            bob.insert(x);

        for(int x : aliceSizes) {
            int y = x - diff;

            if(bob.find(y) != bob.end())
                return {x, y};
        }

        return {};
    }
};