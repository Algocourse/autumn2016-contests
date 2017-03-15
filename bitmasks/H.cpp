#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

const int MAX_BIT = 21;

inline bool is_bit(int mask, int bit) {
    return (mask >> bit) & 1;
}

int main() {
    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<vector<int>> next(n, vector<int>(MAX_BIT, -1));
    for (int bit = MAX_BIT - 1; bit >= 0; --bit)
        if (is_bit(a[n - 1], bit))
            next[n - 1][bit] = n - 1;

    for (int pos = n - 2; pos >= 0; --pos) {
        for (int bit = MAX_BIT - 1; bit >= 0; --bit) {
            next[pos][bit] = next[pos + 1][bit];
            if (is_bit(a[pos], bit)) {
                next[pos][bit] = pos;
            }
        }
    }

    vector<bool> used(1 << MAX_BIT, false);

    for (int spos = 0; spos < n; ++spos) {
        int cur = a[spos];
        used[cur] = true;
        int cpos = spos;
        while (true) {
            if (cpos + 1 == n)
                break;

            int lpos = -1;
            for (int bit = 0; bit < MAX_BIT; ++bit) {
                if (!is_bit(cur, bit)) {
                    int to = next[cpos + 1][bit];
                    if (to != -1) {
                        if (lpos == -1)
                            lpos = to;
                        else
                            lpos = min(lpos, to);
                    }
                }
            }
            if (lpos != -1) {
                cur |= a[lpos];
                cpos = lpos;
                used[cur] = true;
            } else {
                break;
            }
        }
    }

    int ans = 0;
    for (bool it : used)
        ans += it;
    cout << ans << endl;

    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
