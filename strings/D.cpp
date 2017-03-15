#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

void do_shift(string& s, int l, int r, int k) {
    k %= (r - l + 1);
    string buf = "";

    for (int i = r - k + 1; i <= r; ++i)
        buf += s[i];
    for (int i = l; i < r - k + 1; ++i)
        buf += s[i];

    for (int i = 0; i < r - l + 1; ++i)
        s[l + i] = buf[i];
}

int main() {
    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int m;
    cin >> s >> m;
    for (int i = 0; i < m; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        --l;
        --r;
        do_shift(s, l, r, k);
    }

    cout << s << endl;

    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
