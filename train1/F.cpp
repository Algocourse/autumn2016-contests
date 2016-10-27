#include <iostream>
#include <cstring>

using namespace std;

int get_dist(const string& s1, const string& s2) {
    int res = 0;
    for (size_t i = 0; i < s1.length(); ++i)
        res += (s1[i] != s2[i]);
    return res;
}

int main() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    if (k == 2) {
        string pretendent_AB = "";
        string pretendent_BA = "";
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                pretendent_AB += 'B';
                pretendent_BA += 'A';
            } else {
                pretendent_AB += 'A';
                pretendent_BA += 'B';
            }
        }

        if (get_dist(pretendent_AB, s) < get_dist(pretendent_BA, s))
            cout << get_dist(pretendent_AB, s) << endl << pretendent_AB << endl;
        else
            cout << get_dist(pretendent_BA, s) << endl << pretendent_BA << endl;
    } else {
        int ans = 0;
        for (size_t i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                for (int q = 'A'; q < 'A' + k; q++) {
                    if ((s[i] != q && i + 1 == s.length()) || (s[i] != q && i + 1 < s.length() && s[i + 1] != q)) {
                        ans++;
                        s[i] = q;
                        break;
                    }
                }
            }
        }
        cout << ans << endl << s;
    }
    return 0;
}
