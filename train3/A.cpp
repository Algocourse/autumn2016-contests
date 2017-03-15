#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans = 0;

    long long last = 2;
    n -= 2;
    while (n >= 0) {
        if (n % 3 == 0)
            ++ans;
        last += 3;
        n -= last;
    }
    cout << ans;

    return 0;
}
