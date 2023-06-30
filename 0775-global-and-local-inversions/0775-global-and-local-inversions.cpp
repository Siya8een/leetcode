class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        long long global = 0, local = 0; 
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1])
                local++;
        }
        global = mergesort(nums, temp, 0, n - 1);
        return local == global;
    }

    long long mergesort(vector<int>& arr, vector<int>& temp, int l, int r) { 
        int mid = 0;
        long long inv = 0;
        if (r > l) {
            mid = (l + r) / 2;
            inv += mergesort(arr, temp, l, mid);
            inv += mergesort(arr, temp, mid + 1, r);
            inv += merge(arr, temp, l, mid + 1, r);
        }
        return inv;
    }

    long long merge(vector<int>& arr, vector<int>& temp, int l, int mid, int r) { 
        int i = l, j = mid, k = l;
        long long inv = 0; 
        while (i <= mid - 1 && j <= r) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv += mid - i;
            }
        }
        while (i <= mid - 1)
            temp[k++] = arr[i++];
        while (j <= r)
            temp[k++] = arr[j++];
        for (i = l; i <= r; i++)
            arr[i] = temp[i];
        return inv;
    }
};