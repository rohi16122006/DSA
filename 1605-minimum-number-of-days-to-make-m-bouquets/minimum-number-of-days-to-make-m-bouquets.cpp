class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long need = 1LL * m * k;
        if(need > bloomDay.size())
            return -1;
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int bouquets = 0;
            int flowers = 0;
            for(int day : bloomDay) {
                if(day <= mid) {
                    flowers++;
                    if(flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                }
                else {
                    flowers = 0;
                }
            }
            if(bouquets >= m)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};