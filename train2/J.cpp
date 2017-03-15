#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

long long a[110000];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    set<int> s;
    for (int i = 0; i < n; i++)
        if (a[i] % k != 0)
            s.insert(a[i]);
        else
            if (s.find(a[i] / k) == s.end())
                s.insert(a[i]);
    cout << s.size() << endl;
    return 0;
}
