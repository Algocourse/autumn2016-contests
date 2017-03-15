#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int tmp, n, a, b;
    vector<int> deals;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        deals.push_back(tmp);
    }
    sort(deals.begin(), deals.end());
    int x = deals[b - 1], y = deals[b];
    int ans = abs(x - y);
    cout << ans << endl;
    return 0;
}
