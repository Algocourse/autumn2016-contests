#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    unordered_map <char, int> cur;
    int ans = 0;
    for (int i = 0; i < (int) s.length(); i += 2) {
        char key = s[i], door = s[i + 1] - 'A' + 'a';
        ++cur[key];
        if (cur[door] == 0)
            ++ans;
        else
            --cur[door];
    }
    cout << ans << endl;
    return 0;
}
