//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

        
        
 class Solution {
public:
    long long merge(long long arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        long long invCount = 0;

        vector<long long> a(n1);
        vector<long long> b(n2);

        for (int i = 0; i < n1; i++)
            a[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
           b[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (a[i] <= b[j]) {
                arr[k] = a[i];
                i++;
            } else {
                arr[k] = b[j];
                j++;
                invCount += n1 - i; //inversion count
            }
            k++;
        }

        while (i < n1) {
            arr[k] = a[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = b[j];
            j++;
            k++;
        }

        return invCount;
    }

    long long mergeSort(long long arr[], int left, int right) {
        long long invCount = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            invCount += mergeSort(arr, left, mid);
            invCount += mergeSort(arr, mid + 1, right);
            invCount += merge(arr, left, mid, right);
        }
        return invCount;
    }

    long long int inversionCount(long long arr[], long long n) {
        return mergeSort(arr, 0, n - 1);
    }
};
    

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends