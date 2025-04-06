#include <iostream>

using namespace std;

int main() {
    int z, y;
    cin >> z >> y;

    bool containsZero = z <= 0 && 0 <= y;
    bool containsOne = z <= 1 && 1 <= y;

    cout << (containsZero && containsOne ? 1 : 0);
}
