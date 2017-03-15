#include <iostream>

using namespace std;

const int LIM = 2e+3 + 10;
const int MOD = 1e+9 + 7;

long long dp[LIM][LIM];

int main() {
    int n, k;
    cin >> n >> k;
    ++n;
    ++k;

    dp[0][1] = 1;

    for (int pos = 0; pos < k; ++pos)
        for (int last = 1; last < n; ++last)
            for (int koef = 1; koef < LIM; koef++)
                if (last * koef < n) {
                    dp[pos + 1][koef * last] += dp[pos][last];
                    dp[pos + 1][koef * last] %= MOD;
                } else {
                    break;
                }

    long long ans = 0;
    for (int last = 1; last < n; ++last) {
        ans += dp[k - 1][last];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
