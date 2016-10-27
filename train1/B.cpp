#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long r, x, y, a, b;
    cin >> r >> x >> y >> a >> b;
    long long dist = (x - a) * (x - a) + (y - b) * (y - b);
    long long real = sqrt(dist);
    if (real * real < dist)
        ++real;
    r *= 2;

    if (real % r == 0)
        cout << real / r;
    else
        cout << real / r + 1;
    return 0;
}
