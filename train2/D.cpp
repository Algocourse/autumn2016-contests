#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int k;
    vector<int> m(12);
    cin >> k;
    if (k == 0) {
        cout << "0";
        return 0;
    }

    for (int i = 0; i < 12; ++i)
        cin >> m[i];
    sort(m.begin(), m.end());
    int ans = 0;
    for (int i = 11; i >= 0; --i) {
        ans += m[i];
        int f = 12 - i;
        if (ans >= k) {
            cout << f;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}
