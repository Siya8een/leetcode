#include <vector>

class MyHashSet {
private:
    std::vector<std::vector<int>> data;
    int buckets;

    int hash(int key) {
        return key % buckets;
    }

public:
    MyHashSet() : buckets(10000), data(10000) {}

    void add(int key) {
        int index = hash(key);
        for (int value : data[index]) {
            if (value == key) {
                return;  // Key already exists, no need to add
            }
        }
        data[index].push_back(key);
    }

    void remove(int key) {
        int index = hash(key);
        std::vector<int>& bucket = data[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);  // Key found, remove it
                return;
            }
        }
    }

    bool contains(int key) {
        int index = hash(key);
        std::vector<int>& bucket = data[index];
        for (int value : bucket) {
            if (value == key) {
                return true;  // Key found
            }
        }
        return false;  // Key not found
    }
};
