#include <iostream>

using namespace std;

const int LIM = 1e+5 + 10;

int p[LIM];

int main() {
    ios_base::sync_with_stdio(false);

    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    int l = 0, r = 0;
    long long ans = 0;
    while (l < n) {
        while (r + 1 < n && p[l] + d >= p[r + 1])
            ++r;
        long long cnt = (r - l + 1) - 1;
        ans += cnt * (cnt - 1) / 2;
        ++l;
    }

    cout << ans << endl;

    return 0;
}
