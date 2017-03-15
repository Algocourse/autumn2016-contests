#include <iostream>

using namespace std;

const int MOD = 1e+9 + 9;

int bin_pow(int x, int pw) {
    int res = 1;
    while (pw > 0) {
        if (pw & 1) {
            res = 1LL * res * x % MOD;
            --pw;
        } else {
            x = 1LL * x * x % MOD;
            pw >>= 1;
        }
    }
    return res;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    int no_double = min(1LL * (n - m) * (k - 1), 1LL * m);
    int cnt_double = (m - no_double) / k;
    no_double += (m - no_double) % k;

    int k_coeff = (bin_pow(2, cnt_double + 1) - 2 + MOD) % MOD;

    cout << (1LL * k * k_coeff % MOD + no_double) % MOD << endl;

    return 0;
}
