#include <iostream>
#include <iomanip>

using namespace std;

double bin_pow(double x, int p) {
    double t;
    if (p == 1)
        return x;
    if (p == 0)
        return 1;
    t = bin_pow(x, p / 2);
    if ( p % 2 == 0 )
        return t * t;
    else
        return t * t * x;
}

int main() {
    cout << fixed << setprecision(10);
    int n, m;
    cin >> m >> n;
    double ans = 0;
    double one = 1.0 / m;
    double prev = 0;
    for ( int i = 1; i <= m; i++ ) {
        double t = bin_pow(i*one, n);
        ans += (t - prev)*i;
        prev = t;
    }

    cout << ans << endl;

    return 0;
}
