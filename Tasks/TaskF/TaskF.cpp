#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int nt = 0; nt < t; nt++) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        long long count = 0;
        stringstream res;
        int max = 0, prom;
        for (int i = 1; i < n; i++) {
            if (p[i] > max)
                max = p[i];
            if (i == max) {
                count++;
                prom = p[i + 1];
                p[i + 1] = p[i];
                p[i] = prom;
                if (prom > max)
                    max = prom;
                res << i << " ";
            }
        }
        cout << count << endl;
        cout << res.str() << endl;
    }
    return 0;
}
