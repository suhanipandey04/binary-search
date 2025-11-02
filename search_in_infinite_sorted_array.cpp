#include <iostream>
#include <vector>
using namespace std;

int SearchInInfiniteArray(vector<int> vec, int K)
{
    int start = 0;
    int end = 1;

    // Expand the search window until K is within range
    while (end < vec.size() && vec[end] < K) {
        start = end;
        end *= 2;
        if (end >= vec.size()) end = vec.size() - 1;
    }

    // Binary search within the window
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (vec[mid] == K) return mid;
        else if (vec[mid] < K) start = mid + 1;
        else end = mid - 1;
    }

    return -1; // Not found

}

int main() {
    vector<int> vec = {1, 3, 5, 7, 9, 13, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42};
    int K;
    cin >> K;

    int index = SearchInInfiniteArray(vec, K);
    cout << index << endl;
    return 0;
}