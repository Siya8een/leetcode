#include <vector>
#include <unordered_map>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        int m = tasks.size();
        if (n == 0) {
            return m;
        }

        // Count task type
        std::unordered_map<char, int> task_counts;
        for (char task : tasks) {
            task_counts[task]++;
        }

        int max_freq = 0;
        int num_max_freq = 0;

        // Find the maximum frequency and the number of tasks that have the maximum frequency
        for (const auto& task_count : task_counts) {
            if (task_count.second > max_freq) {
                max_freq = task_count.second;
                num_max_freq = 1;
            } else if (task_count.second == max_freq) {
                num_max_freq++;
            }
        }

        // Calculate the total time needed
        int result = (max_freq - 1) * (n + 1) + num_max_freq;

        // The result cannot be less than the total number of tasks
        return std::max(result, m);
    }
};
