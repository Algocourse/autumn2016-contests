#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int LIM = 1e+5 + 100;

int z[LIM];
string s;
int n;

bool used[LIM];
long long p[LIM];

void cmp_z() {
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while ( i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] -1;
        }
        p[z[i]]++;
    }
}

int main() {
    cin >> s;
    n = s.length();
    cmp_z();

    z[0] = n;

    int symb = 1;
    int cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (z[i] == symb) {
            used[symb] = true;
            ++cnt;
        }
        ++symb;
    }
    ++p[n];

    for (int i = LIM - 2; i >= 0; --i)
        p[i] += p[i + 1];

    cout << cnt << endl;
    for (int i = 1; i <= n; ++i)
        if (used[i])
            cout << i << " " << p[i] << '\n';

    return 0;
}
