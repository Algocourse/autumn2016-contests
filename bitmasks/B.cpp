#include <iostream>

using namespace std;

const int LIM = 18;

int rules[LIM][LIM];
int likeness[LIM];
long long dp[1 << LIM][LIM];

inline bool is_bit(int mask, int bit) {
    return (mask >> bit) & 1;
}

inline int set_bit(int mask, int bit) {
    return mask | (1 << bit);
}

int bit_cnt(int mask) {
    int res = 0;
    for (int i = 0; i < LIM; ++i)
        res += is_bit(mask, i);
    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> likeness[i];
    for (int i = 0; i < k; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u;
        --v;
        rules[u][v] = c;
    }
    long long ans = 0;

    for (int dish = 0; dish < n; ++dish)
        dp[set_bit(0, dish)][dish] = likeness[dish];
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int prev = 0; prev < n; ++prev) {
            if (is_bit(mask, prev)) {
                if (bit_cnt(mask) == m) {
                    ans = max(ans, dp[mask][prev]);
                    continue;
                }
                for (int next = 0; next < n; ++next)
                    if (!is_bit(mask, next))
                        dp[set_bit(mask, next)][next] = max(dp[mask][prev] + rules[prev][next] + likeness[next], dp[set_bit(mask, next)][next]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
