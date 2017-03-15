#include <iostream>

using namespace std;

const int LIM = 4e+5 + 100;
const long long INF = 1e+18;

long long ar[LIM];
int p[LIM];

int solve(int w, int n) {
    int ans = 0;
    p[0] = 0;
    for (int pos = 1; pos < w + n - 1; ++pos) {
        int val = p[pos - 1];
        while (val > 0 && ar[pos] != ar[val])
            val = p[val - 1];
        if (ar[pos] == ar[val])
            ++val;
        p[pos] = val;
        if (p[pos] == w - 1)
            ++ans;
    }
    return ans;
}

int main() {
    int n, w;
    cin >> n >> w;
    if (w == 1) {
        cout << n;
        return 0;
    }
    if (w > n) {
        cout << 0;
        return 0;
    }
    int last;
    cin >> last;
    for (int i = 1; i < n; ++i) {
        int tmp;
        cin >> tmp;
        ar[w + i - 1] = tmp - last;
        last = tmp;
    }
    cin >> last;
    for (int i = 1; i < w; ++i) {
        int tmp;
        cin >> tmp;
        ar[i - 1] = tmp - last;
        last = tmp;
    }
    ar[w - 1] = INF;

    cout << solve(w, n) << endl;

    return 0;
}
