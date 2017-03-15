#include <iostream>

using namespace std;

const int LIM = 1e+5 + 10;

long long a[LIM];
long long dp[LIM];

int main() {
    int n;
    cin >> n;

    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        ++a[tmp];
    }

    long long ans = 0;
    for (int i = LIM - 1; i >= 0; --i) {
        if (a[i] != 0) {
            if (i == 1) {
                ans = max(dp[i] + i * a[i], ans);
            } else {
                if (dp[i - 2] < dp[i] + i * a[i])
                    dp[i - 2] = dp[i] + i * a[i];
            }
            if (dp[i - 1] < dp[i])
                dp[i - 1] = dp[i];
        } else {
            dp[i - 1] = max(dp[i], dp[i - 1]);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}
