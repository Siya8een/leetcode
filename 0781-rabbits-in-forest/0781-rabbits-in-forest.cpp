class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> countMap;

        for (int answer : answers) {
            if (countMap.count(answer) == 0) {
                countMap[answer] = 1;
            } else {
                countMap[answer]++;
            }
        }

        int minRabbits = 0;
        for (const auto& pair : countMap) {
            int count = pair.first;
            int freq = pair.second;

            int groups = ceil(static_cast<double>(freq) / (count + 1));
            minRabbits += groups * (count + 1);
        }

        return minRabbits;
    }
};
