#include <iostream>

using namespace std;

int main() {
    long long n;
    long long ans = 0;
    cin >> n;
    long long cur = 9;
    long long step = 1;
    while (true) {
        if (cur > n) {
            ans += n * step;
            break;
        }
        ans += cur * step;
        n -= cur;
        cur *= 10;
        ++step;
    }
    cout << ans << endl;

    return 0;
}
