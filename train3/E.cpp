#include <iostream>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int cnt = 0;
    string res = "";
    for (int i = 0; i < (int) s.length(); ++i) {
        if (s[i] == t[i]) {
            res += s[i];
        } else {
            if (cnt == 0)
                res += s[i];
            else
                res += t[i];
            cnt = 1 - cnt;
        }
    }
    if (cnt == 1)
        cout << "impossible\n";
    else
        cout << res << endl;

    return 0;
}
