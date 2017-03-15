#include <iostream>

using namespace std;

bool check(string& s, int p, int pos) {
    for (int i = (s[pos] - 'a') + 1; i <= p; ++i) {
        ++s[pos];
        if (pos > 0 && s[pos] == s[pos - 1])
            continue;
        if (pos > 1 && s[pos] == s[pos - 2])
            continue;
        bool f = true;
        for (int j = pos + 1; j < (int)s.length() && f; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (k == 3)
                    f = false;
                if (k <= p)
                    s[j] = 'a' + k;
                if (j > 0 && s[j] == s[j - 1])
                    continue;
                if (j > 1 && s[j] == s[j - 2])
                    continue;
                break;
            }
        }
        if (f)
            return true;
    }
    return false;
}

int main() {
    int p, n;
    cin >> n >> p;
    --p;
    string s;
    cin >> s;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (check(s, p, i)) {
            cout << s << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
