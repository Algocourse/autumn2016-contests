#include <iostream>

using namespace std;

const int LIM = 1e+4 + 10;

struct point_t {
    int x, y;
};

point_t operator -(const point_t& a, const point_t& b) {
    return {a.x - b.x, a.y - b.y};
}

int operator *(const point_t& a, const point_t& b) {
    return a.x * b.y - a.y * b.x;
}

point_t lake[LIM];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> lake[i].x >> lake[i].y;
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        point_t first = lake[(i + 1) % n] - lake[i];
        point_t second = lake[(i + 2) % n] - lake[(i + 1) % n];
        if (first * second > 0)
            ++ans;
    }
    cout << ans << endl;

    return 0;
}
