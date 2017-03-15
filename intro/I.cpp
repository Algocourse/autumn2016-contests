#include <iostream>
#include <algorithm>

using namespace std;

const int LIM = 2e+5;

pair<int, int> segs[LIM];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, w;
        cin >> x >> w;
        segs[i].first = x + w;
        segs[i].second = x - w;
    }
    sort(segs, segs + n);
    int cur = segs[0].first;
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (cur <= segs[i].second) {
            cur = segs[i].first;
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
