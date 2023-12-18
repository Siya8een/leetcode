#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::vector<int> result;
        std::stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            // Check for collision when the current asteroid is moving to the left
            while (!st.empty() && asteroids[i] < 0 && asteroids[st.top()] > 0) {
                int leftSize = -asteroids[i];
                int rightSize = asteroids[st.top()];

                if (leftSize < rightSize) {
                    // Current asteroid explodes, stop checking further and break out of the loop
                    goto nextAsteroid;
                } else if (leftSize == rightSize) {
                    // Both asteroids explode, pop the asteroid from the stack
                    st.pop();
                    // Skip the current asteroid, as it will also explode
                    goto nextAsteroid;
                } else {
                    // The asteroid in the stack explodes, pop it
                    st.pop();
                }
            }

            // If there was no collision, or the current asteroid is moving to the right
            st.push(i);
            result.push_back(asteroids[i]);

        nextAsteroid:;
        }
for (int i =0; i < result.size();i++){
    cout << result[i]<< ',';
}
         cout << endl;
        // Copy the remaining asteroids in the stack to the result
        std::vector<int> remaining;
        while (!st.empty()) {
            remaining.push_back(asteroids[st.top()]);
            st.pop();
        }
for (int i =0; i < remaining.size();i++){
    cout << remaining[i]<< ',';
}
        // Reverse the remaining asteroids and append them to the result
       reverse(remaining.begin(), remaining.end());
        return remaining;
    }
};
