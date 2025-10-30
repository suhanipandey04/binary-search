//if the input is 4 than the output will be 2
#include <iostream>
using namespace std;

int binarysearch(int n) {
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;

    int ans = -1;

    while (s <= e) {
        long long int square = mid * mid;

        if (square == n)
            return mid;
        if (square < n) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int mySqrt(int x) {
    return binarysearch(x);
}

int main() {
    int number;
    cout << "Enter a number to find its square root: ";
    cin >> number;

    int result = mySqrt(number);
    cout << "The integer square root of " << number << " is: " << result << endl;

    return 0;
}
