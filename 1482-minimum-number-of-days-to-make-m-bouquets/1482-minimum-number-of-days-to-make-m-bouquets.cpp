class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            vector<int> check(bloomDay.size(), 0);
            
            for (int i = 0; i < bloomDay.size(); i++) {
                if (bloomDay[i] <= mid) {
                    check[i] = 1;
                }
            }
            
            int bouquets = 0;
            int consecutiveFlowers = 0;

            for (int i = 0; i < check.size(); i++) {
                if (check[i] == 1) {
                    consecutiveFlowers++;
                    if (consecutiveFlowers == k) {
                        bouquets++;
                        consecutiveFlowers = 0;
                    }
                } else {
                    consecutiveFlowers = 0;
                }
            }
            
            if (bouquets >= m) {
                result = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return result;
    }
};
