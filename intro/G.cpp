#include <iostream>

using namespace std;

const int LIM = 3e+5 + 100;

int a[LIM];
int p[LIM];

int main() {
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0)
            p[i] = (a[i] == 0);
        else
            p[i] = p[i - 1] + (a[i] == 0);
    }

    int la = -1, ra = -2;
    int r = -1;

    for (int l = 0; l < n; ++l) {
        r = max(r, l - 1);

        while (r + 1 < n && p[r + 1] - (l == 0 ? 0 : p[l - 1]) <= k)
            ++r;

        if (r - l + 1 > ra - la + 1) {
            la = l;
            ra = r;
        }
    }

    for (int i = la; i <= ra; ++i)
        a[i] = 1;

    cout << ra - la + 1 << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << endl;

    return 0;
}
