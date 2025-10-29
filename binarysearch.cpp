#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int> &arr, int k) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) {
            return mid;
        } else if (arr[mid] > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {10,20,30,40,50,60};
    int k = 20;
    int index = binarysearch(arr, k);
    cout << "Element " << k << " found at index: " << index << endl;
    return 0;
}