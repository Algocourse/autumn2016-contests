#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int s, n;
    cin >> s >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    int i;
    for (i = 0; i < n && s > a[i].first; ++i)
        s += a[i].second;

    cout << (i == n ? "YES" : "NO") << endl;
    return 0;
}
