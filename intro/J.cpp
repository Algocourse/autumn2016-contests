#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int LIM = 500;

map<int, int, greater<int>> mp;
vector<int> a;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n * n; ++i) {
        int val;
        cin >> val;
        ++mp[val];
    }

    for (int i = 0; i < n; ++i) {
        while ((*mp.begin()).second == 0)
            mp.erase(mp.begin());
        a[i] = (*mp.begin()).first;
        for (int j = 0; j <= i; ++j)
            --mp[gcd(a[i], a[j])];
        for (int j = 0; j < i; ++j)
            --mp[gcd(a[i], a[j])];
    }

    for (int i : a)
        cout << i << endl;

    return 0;
}
