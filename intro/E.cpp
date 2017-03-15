#include <iostream>

using namespace std;

const int LIM = 100;

int cnt[LIM];

int main() {
    string s;
    int k;

    cin >> k >> s;
    for (int i = 0; i < (int)s.length(); ++i)
        ++cnt[s[i] - 'a'];

    s = "";
    for (int i = 0; i < LIM; i++) {
        if (cnt[i] % k == 0 && cnt[i] != 0 ) {
            for (int j = 0; j < cnt[i] / k; j++)
                s += (char)(i + 'a');
        } else if (cnt[i] % k != 0 && cnt[i] != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < k; i++)
        cout << s;

    return 0;
}
