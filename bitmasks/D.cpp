#include <iostream>
#include <map>
#include <string>

using namespace std;

const int LIM = 1e+5;
bool used[LIM];

bool bit(int mask, int b) {
    return (mask >> b) & 1;
}

map<string, int> mp;
int n;
int g[20][20];

int cnt_b(int mask) {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (bit(mask, i))
            cnt++;
    return cnt;
}

bool correct(int mask) {
    for (int i = 0; i < n; ++i)
        if (bit(mask, i))
            for (int j = 0; j < n; ++j)
                if (bit(mask, j) && g[i][j])
                    return false;
    return true;
}

void solve(int mask) {
    for (int i = 0; i < n; ++i) {
        int new_m = mask | ( 1 << i );
        if (!bit(mask, n) && correct(new_m)) {
            if (!used[new_m]) {
                used[new_m] = true;
                solve(new_m);
            }
        }
    }
}

int main() {
    int m;
    cin >> n >> m;

    string tmp, tmp2;
    for ( int i = 0; i < n; ++i) {
        cin >> tmp;
        mp[tmp] = i;
    }

    for (int i = 0; i < m; ++i) {
        cin >> tmp >> tmp2;
        g[mp[tmp]][mp[tmp2]] = 1;
        g[mp[tmp2]][mp[tmp]] = 1;
    }

    solve(0);

    int ans = 0;
    for (int mask = 0; mask < ( 1 << n ); ++mask) {
        if (used[mask] && cnt_b(mask) > cnt_b(ans))
            ans = mask;
    }

    cout << cnt_b(ans) << endl;

    for (auto i = mp.begin(); i != mp.end(); ++i)
        if (bit(ans, i->second))
            cout << i->first << endl;

    return 0;
}
