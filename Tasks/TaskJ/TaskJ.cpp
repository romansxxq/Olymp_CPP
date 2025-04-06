#include <iostream>
using namespace std;

const long long MOD = 998244353;

long long power(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long dp[4] = { 1, 0, 0, 0 };

    for (int i = 0; i < n; i++) {
        long long next_dp[4] = { 0, 0, 0, 0 };

        next_dp[0] = (dp[0] * 25) % MOD;
        next_dp[1] = (dp[1] * 25 + dp[0]) % MOD;
        next_dp[2] = (dp[2] * 25 + dp[1]) % MOD;
        next_dp[3] = (dp[3] * 26 + dp[2]) % MOD;

        for (int j = 0; j < 4; j++) {
            dp[j] = next_dp[j];
        }
    }

    long long total = power(26, n, MOD);
    long long inv_total = power(total, MOD - 2, MOD);

    long long res = (dp[3] * inv_total) % MOD;

    cout << res << "\n";

    return 0;
}