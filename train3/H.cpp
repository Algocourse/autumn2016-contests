#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

const int LIM = 1e+5 + 100;

string s[LIM];
string r[LIM];
int c[LIM];
int dp[LIM][2];

int32_t main() {
    for (int i = 0; i < LIM; ++i)
        dp[i][0] = dp[i][1] = -1;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        r[i] = s[i];
        reverse(r[i].begin(), r[i].end());
    }
    dp[0][0] = 0;
    dp[0][1] = c[0];
    for (int i = 1; i < n; ++i) {
        if (dp[i - 1][0] != -1) {
            if (s[i] >= s[i - 1])
                dp[i][0] = dp[i - 1][0];
            if (r[i] >= s[i - 1])
                dp[i][1] = dp[i - 1][0] + c[i];
        }
        if (dp[i - 1][1] != -1) {
            if (s[i] >= r[i - 1]) {
                if (dp[i][0] == -1)
                    dp[i][0] = dp[i - 1][1];
                else
                    dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            }
            if (r[i] >= r[i - 1]) {
                if (dp[i][1] == -1)
                    dp[i][1] = dp[i - 1][1] + c[i];
                else
                    dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
            }
        }
    }

    if (dp[n - 1][0] != -1 && dp[n - 1][1] != -1)
        cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    else if (dp[n - 1][0] == -1 && dp[n - 1][1] == -1)
        cout << -1 << endl;
    else if (dp[n - 1][0] == -1)
        cout << dp[n - 1][1] << endl;
    else
        cout << dp[n - 1][0] << endl;

    return 0;
}
