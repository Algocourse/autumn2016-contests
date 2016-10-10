#include <iostream>
#include <algorithm>

using namespace std;

const int LIM = 5e+5 + 10;

int sz[LIM];

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> sz[i];
    sort(sz, sz + n);

    int pairs = 0;
    int l = 0;
    int lb = n / 2 + (n % 2);
    int r = lb;
    int rb = n;

    while (l < lb && r < rb) {
        if (sz[l] * 2 <= sz[r]) {
            ++pairs;
            ++l;
            ++r;
        } else {
            ++r;
        }
    }

    cout << n - pairs << endl;

    return 0;
}
