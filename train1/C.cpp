#include <iostream>

using namespace std;

const int LIM = 1e+3 + 10;

int a[LIM][LIM];

int main() {
    long long n, d, k;
    cin >> n >> k >> d;
    long long tmp = 1;
    for (int i = 0; i < d; i++) {
        tmp *= k;
        if (tmp >= n) {
            break;
        } else if (i == d - 1) {
            cout << -1;
            return 0;
        }
    }

    for (int j = 1; j < n; j++) {
        a[d - 1][j] += 1;
        for (int i = d - 1; i >= 0; i--) {
            if (a[i][j] >= k) {
                a[i - 1][j] += 1;
                a[i][j] -= k;
            }
            a[i][j + 1] = a[i][j];
        }
    }

    for (int i = 0; i < d; i++) {
        for ( int j = 0; j < n; j++ )
            cout << a[i][j] + 1 << " ";
        cout << endl;
    }

    return 0;
}
