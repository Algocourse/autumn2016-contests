#include <iostream>
#include <algorithm>

using namespace std;

const int LIM = 9;

int pw[LIM];

void init() {
    pw[0] = 1;
    for (int i = 1; i < LIM; ++i)
        pw[i] = pw[i - 1] * 2;
}

bool check(string& a, string& b) {
    for (int i = 0; i < (int) b.length(); ++i)
        if (a[i] != b[i])
            return false;
    return true;
}

void inc(string& s) {
    int pos = 0;
    while (true) {
        if (s[pos] == '7') {
            s[pos] = '4';
        } else if (s[pos] == '4') {
            s[pos] = '7';
            return;
        } else {
            for (int i = 0; i <= pos; ++i)
                s[i] = '4';
            return;
        }
        ++pos;
    }
}

int main() {
    init();
    string n;
    cin >> n;
    int step = 1;
    string ans = "";
    for (int i = 0; i < (int) n.length(); ++i)
        ans += ' ';
    reverse(n.begin(), n.end());
    ans[0] = '4';
    while (!check(ans, n)) {
        inc(ans);
        ++step;
    }
    cout << step << endl;
    return 0;
}
