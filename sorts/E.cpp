#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int last = 2;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= last) {
            ++last;
        }
    }

    cout << last << endl;

    return 0;
}
