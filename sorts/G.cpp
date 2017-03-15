#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int LIM = 1e+3 + 10;
pair<int, int> towns[LIM];

int main() {
    cout << fixed << setprecision(10);
    int n, s;
    cin >> n >> s;
    int x, y, popul;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> popul;
        towns[i].first = x * x + y * y;
        towns[i].second = -1 * popul;
    }

    sort(towns, towns + n);

    for (int i = 0; i < n; i++) {
        s -= towns[i].second;
        if (s >= 1000000) {
            cout << sqrt(towns[i].first);
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
