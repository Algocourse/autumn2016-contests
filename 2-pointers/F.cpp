#include <iostream>
#include <queue>

using namespace std;

string s;
int n, k;

int get_ans(char c) {
    int buf = k;
    queue<char> q;
    size_t res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == c) {
            q.push(s[i]);
        } else {
            if (buf > 0) {
                q.push(s[i]);
                --buf;
            } else {
                while (buf == 0 && !q.empty()) {
                    if (q.front() != c)
                        ++buf;
                    q.pop();
                }
                if (buf == 0)
                    continue;
                --buf;
                q.push(s[i]);
            }
        }
        res = max(res, q.size());
    }
    return res;
}

int main() {
    cin >> n >> k;
    cin >> s;

    cout << max(get_ans('a'), get_ans('b')) << endl;

    return 0;
}
