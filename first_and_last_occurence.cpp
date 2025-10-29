#include <iostream>
#include <vector>
using namespace std;

vector<int> find(vector<int>& arr, int x) {
    int first = -1, last = -1;
    int low = 0, high = arr.size() - 1;

    // Find first occurrence
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            first = mid;
            high = mid - 1; // search left half
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Reset bounds for last occurrence
    low = 0;
    high = arr.size() - 1;

    // Find last occurrence
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            last = mid;
            low = mid + 1; // search right half
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return {first, last};
}

int main() {
    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int x = 5;

    vector<int> result = find(arr, x);
    cout << "First occurrence of " << x << " is at index: " << result[0] << endl;
    cout << "Last occurrence of " << x << " is at index: " << result[1] << endl;

    return 0;
}