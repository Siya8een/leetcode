class Solution {
public:
    int sum(vector<int>& weights) {
        int ans = 0;
        for (int i = 0; i < weights.size(); i++) {
            ans = ans + weights[i];
        }
        return ans;
    }

    bool canShipWithinDays(vector<int>& weights, int capacity, int days) {
        int currentDay = 1;
        int currentWeight = 0;

        for (int weight : weights) {
            if (currentWeight + weight > capacity) {
                currentDay++;
                currentWeight = 0;
            }
            currentWeight += weight;
        }

        return currentDay <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end()); // Minimum capacity starts at the maximum individual weight
        int end = sum(weights);

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (canShipWithinDays(weights, mid, days)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};
