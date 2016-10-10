#include <iostream>
#include <set>
#include <map>

using namespace std;

const int LIM = 1e+5 + 10;

char a[LIM];

int main() {
    ios_base::sync_with_stdio(false);

    set<char> total;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total.insert(a[i]);
    }

    size_t m = total.size();

    int ans = n;
    int l = 0, r = 0;
    map<char, int> mp;
    mp[a[0]] = 1;
    while (l < n) {
        while (r + 1 < n && mp.size() < m) {
            ++r;
            ++mp[a[r]];
        }
        if (mp.size() == m)
            ans = min(ans, r - l + 1);
        --mp[a[l]];
        if (mp[a[l]] == 0)
            mp.erase(a[l]);
        ++l;
    }

    cout << ans << endl;

    return 0;
}
