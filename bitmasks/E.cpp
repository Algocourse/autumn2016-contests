#include <iostream>

using namespace std;

const int LIM = (2 << 24) + 10;
const int INF = 1e+9;

int items[25][2];
int dp[LIM][2];
bool used[LIM];
int xs, ys;
int n;

bool bit(int mask, int b) {
    return (mask >> b) & 1;
}

int range[25];
int dist[25][25];

int func_range(int num) {
    return items[num][0] * items[num][0] + items[num][1] * items[num][1];
}

int func_dist(int a, int b) {
    return (items[a][0] - items[b][0]) * (items[a][0] - items[b][0]) + (items[a][1] - items[b][1]) * (items[a][1] - items[b][1]);
}

void print(int mask) {
    cout << 0 << ' ';
    if (mask == 0)
        return;
    for (int i = 0; i < n; ++i)
        if (bit(mask, i) && !bit(dp[mask][1], i))
            cout << i + 1 << ' ';
    print(dp[mask][1]);
}

int main() {
    cin >> xs >> ys >> n;
    for (int i = 0; i < n; ++i) {
        cin >> items[i][0] >> items[i][1];
        items[i][0] -= xs;
        items[i][1] -= ys;
        range[i] = func_range(i);
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = func_dist(i, j);

    for (int i = 0; i < LIM; ++i) {
        dp[i][0] = INF;
        dp[i][1] = -1;
    }

    dp[0][0] = 0;
    used[0] = true;

    for (int mask = 0; mask < ( 1 << n ); ++mask) {
        if (used[mask]) {
            for (int i = 0; i < n; ++i) {
                if (!bit(mask,i)) {
                    for (int j = i; j < n; ++j) {
                        if (!bit(mask,j)) {
                            int new_m = mask | (1 << i) | (1 << j);
                            int new_s = dp[mask][0] + dist[i][j] + range[i] + range[j];
                            if (dp[new_m][0] > new_s) {
                                dp[new_m][0] = new_s;
                                dp[new_m][1] = mask;
                            }
                            used[new_m] = true;
                        }
                    }
                    break;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][0] << endl;
    print((1 << n) - 1);

    return 0;
}
