#include <iostream>

using namespace std;

const int LIM = 1e+5 + 100;

int a[LIM];

int main() {
    ios_base::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int l = 0, r = -1, sum = 0;
    int ans = 0;
    for (;l < n; ++l) {
        r = max(r, l - 1);
        while (r + 1 < n && sum + a[r + 1] <= t) {
            ++r;
            sum += a[r];
        }

        if (r >= l) {
            ans = max(ans, r - l + 1);
            sum -= a[l];
        }
    }

    cout << ans << endl;

    return 0;
}
