class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int weeks = n / 7;  // Calculate the number of full weeks
        int days_in_last_week = n % 7;  // Calculate the number of days in the last week

        // Calculate the total contribution for full weeks
        total += 28 * weeks + 7 * (weeks * (weeks - 1) / 2);

        // Calculate the contribution for the last week
        total += (days_in_last_week * (days_in_last_week + 1)) / 2 + weeks * days_in_last_week;

        return total;
    }
};