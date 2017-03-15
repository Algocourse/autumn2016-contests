#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> ph[100100];

int main() {
    int n, d, a, b;
    cin >> n >> d >> a >> b;
    int t1, t2;
    for (int i = 1; i <= n; i++) {
        cin >> t1 >> t2;
        ph[i - 1].first = t1 * a + t2 * b;
        ph[i - 1].second = i;
    }
    sort(ph, ph + n);
    vector<int> ans;
    int i = 0;
    while (d - ph[i].first >= 0 && i < n) {
        ans.push_back(ph[i].second);
        d -= ph[i].first;
        i++;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
