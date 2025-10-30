#include <iostream>
#include <vector>
using namespace std;

int findFirst(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, first = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            first = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return first;
}

int findLast(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, last = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            last = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last;
}

int countOccurrences(const vector<int>& arr, int target) {
    int first = findFirst(arr, target);
    if (first == -1) return 0;
    int last = findLast(arr, target);
    return last - first + 1;
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
    int target = 2;
    cout << "Occurrences of " << target << ": " << countOccurrences(arr, target) << endl;

    arr = {1, 1, 2, 2, 2, 2, 3};
    target = 4;
    cout << "Occurrences of " << target << ": " << countOccurrences(arr, target) << endl;

    arr = {8, 9, 10, 12, 12, 12};
    target = 12;
    cout << "Occurrences of " << target << ": " << countOccurrences(arr, target) << endl;

    return 0;
}