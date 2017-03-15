#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());

    if (a.back() != a[0])
        cout << a.back() - a[0] << " " << 1LL * (upper_bound(a.begin(), a.end(), a[0]) - a.begin()) * (a.end() - lower_bound(a.begin(), a.end(), a.back())) << endl;
    else
        cout << 0 << " " << 1LL * n * (n - 1) / 2 << endl;
    return 0;
}
