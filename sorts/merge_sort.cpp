#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
void sort(vector<int>& a, int l, int r) {
    if (l == r) {
        return;
    }

    int m = (l + r) >> 1;
    sort(a, l, m);
    sort(a, m + 1, r);

    vector<int> buffer;
    buffer.reserve(r - l + 1);

    {
        int p1, p2;
        for (p1 = l, p2 = m + 1; p1 <= m && p2 <= r; ) {
            if (a[p1] <= a[p2]) {
                buffer.push_back(a[p1]);
                ++p1;
            } else {
                buffer.push_back(a[p2]);
                ++p2;
            }
        }
        while (p1 <= m) {
            buffer.push_back(a[p1]);
            ++p1;
        }
        while (p2 <= r) {
            buffer.push_back(a[p2]);
            ++p2;
        }
    }

    copy(buffer.begin(), buffer.end(), a.begin() + l);
}
*/

void sort(vector<int>& a, int l, int r) {
    if (l == r) {
        return;
    }

    int m = (l + r) >> 1;
    sort(a, l, m);
    sort(a, m + 1, r);

    vector<int> buffer(r - l + 1);

    merge(
        a.begin() + l, a.begin() + m + 1,
        a.begin() + m + 1, a.begin() + r + 1,
        buffer.begin()
    );

    copy(buffer.begin(), buffer.end(), a.begin() + l);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
