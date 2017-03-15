#include <iostream>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    if (n > m)
        swap(n, m);

    long long l = 1, r = n * m + 1;
    while (l < r) {
        long long med = (l + r) / 2;
        long long cnt = 0;
        for (int i = 1; i <= n && i <= med; i++)
            cnt += min((med - 1) / i, m);
        if (cnt >= k)
            r = med;
        else
            l = med + 1;
    }

    cout << r - 1 << endl;

    return 0;
}
