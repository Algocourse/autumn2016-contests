#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_S = 81;
const int MAX_X = 1e+9;

vector<int> ans;

long long bin_pow(int x, int pw) {
    long long res = 1;
    while (pw > 0) {
        if (pw & 1) {
            res = res * x;
            --pw;
        } else {
            x = 1LL * x * x;
            pw >>= 1;
        }
    }
    return res;
}

int s(long long x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    long long x;
    for (int i = 1; i <= MAX_S; i++) {
        x = bin_pow(i, a) * b + c;
        if (x > 0 && x < MAX_X && s(x) == i)
            ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
