#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> t(n + 1), x(n + 1, 0LL);

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    for (int i = 1; i <= n; i++) {
        x[i] = t[i];
        long long val = x[i];
        for (long long k = 1LL * i * 2; k <= n; k += i) {
            t[k] -= val;
        }
    }

    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        answer += llabs(x[i]);
    }

    cout << answer << "\n";
    return 0;
}
