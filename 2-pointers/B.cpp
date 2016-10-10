#include <iostream>
#include <map>

using namespace std;

void fill_chars(string& s, int pos, map<char, int>& current) {
    char c = 'A';
    for (int i = pos; i < pos + 26; ++i) {
        if (s[i] == '?') {
            while (current[c] > 0)
                ++c;
            s[i] = c;
            ++c;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    if (s.length() < 26) {
        cout << -1 << endl;
        return 0;
    }

    int l = 0, r = -1;
    map<char, int> current;
    int cnt_q = 0;
    bool ok = false;
    while (r + 1 < 26) {
        ++r;
        if (s[r] == '?')
            ++cnt_q;
        else
            ++current[s[r]];
    }

    if (current.size() + cnt_q == 26) {
        fill_chars(s, l, current);
        ok = true;
    }

    while (!ok && r + 1 < (int) s.length()) {
        if (s[l] == '?') {
            --cnt_q;
        } else {
            --current[s[l]];
            if (current[s[l]] == 0)
                current.erase(s[l]);
        }
        ++l;
        ++r;
        if (s[r] == '?')
            ++cnt_q;
        else
            ++current[s[r]];

        if (current.size() + cnt_q == 26) {
            fill_chars(s, l, current);
            ok = true;
        }
    }

    if (ok) {
        for (int i = 0; i < (int) s.length(); ++i)
            if (s[i] == '?')
                s[i] = 'A';
        cout << s << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
