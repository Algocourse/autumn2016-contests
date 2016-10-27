#include <iostream>

using namespace std;

long long a[1000];
long long b[1000];

int main() {
    long long c1, c2, c3, c4, n, m;
    cin >> c1 >> c2 >> c3 >> c4 >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    long long temp = 0;
    for (int i = 0; i < n; i++)
        if (a[i] * c1 > c2)
            temp += c2;
        else
            temp += a[i] * c1;

    long long ans = min(temp, c3);
    temp = 0;

    for (int i = 0; i < m; i++) {
        if (b[i] * c1 > c2)
            temp += c2;
        else
            temp += b[i]*c1;
    }

    ans += min(temp, c3);
    ans = min(c4, ans);
    cout << ans;

    return 0;
}
