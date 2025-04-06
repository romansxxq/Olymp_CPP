#include <iostream>
#include <cmath>

using namespace std;

int sumOfDigits(long long num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    cout << "? -1" << endl;
    int response1;
    cin >> response1;
    cout << "? 1" << endl;
    int response2;
    cin >> response2;

    for (int x = 0; x <= 63; ++x) {
        long long powerMinus1 = (1LL << (x - 1));
        long long powerPlus1 = (1LL << (x + 1)); 

        if (sumOfDigits(powerMinus1) == response1 &&
            sumOfDigits(powerPlus1) == response2) {
            cout << "! " << x << endl;
            return 0;
        }
    }
    return -1;
}