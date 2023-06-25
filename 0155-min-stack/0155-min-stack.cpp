#include <algorithm> // for min function
#include <vector>

class MinStack {
public:
    std::vector<int> MinStacki;
    int t = -1;

    MinStack() {}

    void push(int val) {
        t++;
        MinStacki.push_back(val);
    }

    void pop() {
        if (t == -1) {
            return;
        } else {
            MinStacki.pop_back();
            t--;
        }
    }

    int top() {
        return MinStacki[t];
    }

    int getMin() {
        int mini = INT_MAX;
        for (int i = 0; i <= t; i++) {
            mini = std::min(mini, MinStacki[i]);
        }
        return mini;
    }
};
