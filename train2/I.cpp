#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        cout << lower_bound(a.begin(), a.end(), t + 1) - a.begin() << " ";
    }
    cout << endl;

    return 0;
}
