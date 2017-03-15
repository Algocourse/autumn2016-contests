#include <iostream>

using namespace std;

const int LIM = 1e+2;
const int INF = 1e+9;

bool bit(int mask, int b) {
    return (mask >> b) & 1;
}

int a[LIM];
int n, l, r, x;
int ans = 0;

int main() {
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int mask = 1; mask < (1 << n); ++mask) {
        int cnt = 0, sum = 0,
            _min = INF, _max = 0;
        for (int bt = 0; bt <n; ++bt) {
            if (bit(mask, bt)) {
                ++cnt;
                sum += a[bt];
                _min = min(_min, a[bt]);
                _max = max(_max, a[bt]);
            }
        }
        if (cnt >= 2 && _max - _min >= x && sum <= r && sum >= l)
            ++ans;
    }
    cout << ans << endl;

    return 0;
}
