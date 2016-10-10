#include <iostream>
#include <vector>

using namespace std;

const int LIM = 1e+5 + 10;

int a[LIM];

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> left(n), right(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    left[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1])
            left[i] = left[i - 1] + 1;
        else
            left[i] = 1;
    }
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] < a[i + 1])
            right[i] = right[i + 1] + 1;
        else
            right[i] = 1;
    }

    int ans = 0;
    //i == 0
    ans = max(ans, right[0]);
    if (n >= 2)
        ans = max(ans, right[1] + 1);
    //i == n - 1
    ans = max(ans, left[n - 1]);
    if (n >= 2)
        ans = max(ans, left[n - 2] + 1);
    //other
    for (int i = 1; i + 1 < n; ++i) {
        ans = max(ans, left[i - 1] + 1);
        ans = max(ans, right[i + 1] + 1);
        if (a[i - 1] + 1 < a[i + 1])
            ans = max(ans, left[i - 1] + 1 + right[i + 1]);
    }

    cout << ans << endl;

    return 0;
}
