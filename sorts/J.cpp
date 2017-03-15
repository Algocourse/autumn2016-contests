#include <iostream>

using namespace std;

const int LIM = 110;
const int INF = 1e+9;

int dp[LIM][3];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < LIM; ++i)
        for (int j = 0; j < 3; ++j)
            dp[i][j] = INF;

    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        if (cur & 1) {
            dp[i + 1][1] = min(dp[i + 1][1], min(dp[i][0], dp[i][2]));
        }
        if ((cur >> 1) & 1) {
            dp[i + 1][2] = min(dp[i + 1][2], min(dp[i][0], dp[i][1]));
        }
        dp[i + 1][0] = min(dp[i + 1][0], min(dp[i][0] + 1, min(dp[i][1] + 1, dp[i][2] + 1)));
    }

    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;

    return 0;
}
