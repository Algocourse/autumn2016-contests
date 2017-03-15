#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MOD = 1400;
const int LIM = 1e+6 + 10;

struct point_t {
    int x, y, id;
};

bool operator <(const point_t& a, const point_t& b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

int id = 1;
istream& operator >>(istream& in, point_t& a) {
    in >> a.x >> a.y;
    a.id = id++;
    return in;
}

vector<point_t> v(LIM);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.begin() + n, [](const point_t& a, const point_t& b){return a.x < b.x;});

    int l = 0, r = 0;
    while (l < n) {
        while (r + 1 < n && v[r + 1].x / MOD == v[l].x / MOD)
            ++r;
        sort(v.begin() + l, v.begin() + r);
        for (int i = l; i <= r; ++i)
            cout << v[i].id << ' ';
        l = r = r + 1;
    }

    cout << endl;

    return 0;
}
