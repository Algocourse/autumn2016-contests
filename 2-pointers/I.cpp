#include <iostream>
#include <algorithm>

using namespace std;

const int LIM = 5e+3 + 100;

int res[LIM];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        res[tmp]++;
    }
    int ans = 10000000;
    tmp = 0;
    for (int i = 0; i < LIM; i++) {
        for (int j = 0; j < LIM; j++)
            if (j < i || j > 2 * i)
                tmp += res[j];
        ans = min(ans, tmp);
        tmp = 0;
    }
    cout << ans;
    return 0;
}
