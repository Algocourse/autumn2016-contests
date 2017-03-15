#include <iostream>

using namespace std;

const long long MOD = 1e+9 + 7;
const int LIM = 1e+3 + 10;

long long p[LIM];
long long dp[LIM];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        dp[i + 1] = (2LL * dp[i] - dp[p[i - 1]] + 1LL + 1LL + 2 * MOD) % MOD;
    cout << dp[n + 1] << endl;
    return 0;
}
