#include <iostream>
#include <algorithm>

using namespace std;

const int LIM = 1e+6;

int a[LIM];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += 1LL * (i + 2) * a[i];
    ans -= a[n - 1];
    cout << ans << endl;
    return 0;
}
