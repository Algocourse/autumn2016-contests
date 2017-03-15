#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int LIM = 1011;
const int K_LIM = 12;

int dp[LIM][LIM][K_LIM][2];
string a, b;
int n, m, K;
int ans = 0;

int main() {
    for (int i = 0; i < LIM; ++i)
        for (int j = 0; j < LIM; ++j)
            for (int k = 0; k < K_LIM; ++k)
                dp[i][j][k][0] = dp[i][j][k][1] = -1;

    cin >> n >> m >> K;
    cin >> a >> b;

    dp[0][0][0][0] = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k <= K; ++k) {
                if (dp[i][j][k][1] != -1) {
                    if (a[i] == b[j])
                        dp[i + 1][j + 1][k][1] = max(dp[i][j][k][1] + 1, dp[i + 1][j + 1][k][1]);
                    dp[i + 1][j][k][0] = max(dp[i][j][k][1], dp[i + 1][j][k][0]);
                    dp[i][j + 1][k][0] = max(dp[i][j][k][1], dp[i][j + 1][k][0]);

                    dp[i][j][k][0] = max(dp[i][j][k][1], dp[i][j][k][0]);
                }
                if (dp[i][j][k][0] != -1) {
                    dp[i + 1][j][k][0] = max(dp[i][j][k][0], dp[i + 1][j][k][0]);
                    dp[i][j + 1][k][0] = max(dp[i][j][k][0], dp[i][j + 1][k][0]);
                    if (a[i] == b[j]) {
                        dp[i + 1][j + 1][k + 1][1] = max(dp[i + 1][j + 1][k + 1][1], dp[i][j][k][0] + 1);
                    }
                }
            }

    for (int i = 0; i <= n; ++i)
        ans = max(ans, max(dp[i][m][K][0], dp[i][m][K][1]));
    for (int j = 0; j <= m; ++j)
        ans = max(ans, max(dp[n][j][K][0], dp[n][j][K][1]));
    cout << ans << endl;

    return 0;
}
