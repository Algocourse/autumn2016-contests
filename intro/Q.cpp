#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long MAX_LL = (1LL << 63) - 1LL;

long long get_max_ll(long long x) {
    long long tmp = MAX_LL;
    long long res = 1;
    while (tmp / x >= res)
        res *= x;
    return res;
}

int main() {
    long long t, a, b;
    cin >> t >> a >> b;

    if (a == 1) {
        if (t == 1) {
            if (b == 1)
                cout << "inf" << endl;
            else
                cout << 0 << endl;
        } else {
            if (a == b)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        return 0;
    }

    int ans = 0;
    if (t != 1) {
        long long tmpa = a;
        vector<long long> numa;
        long long base = get_max_ll(t);
        while (base > 0) {
            numa.push_back(tmpa / base);
            tmpa %= base;
            base /= t;
        }
        reverse(numa.begin(), numa.end());
        while (numa.back() == 0)
            numa.pop_back();

        long long tmpb = b;
        vector<long long> numb;
        base = get_max_ll(a);
        while (base > 0) {
            numb.push_back(tmpb / base);
            tmpb %= base;
            base /= a;
        }
        reverse(numb.begin(), numb.end());
        while (numb.back() == 0)
            numb.pop_back();

        if (numa.size() == numb.size()) {
            ans += 1;
            for (size_t i = 0; i < numa.size(); ++i) {
                if (numa[i] != numb[i]) {
                    --ans;
                    break;
                }
            }
        }

        if (numa.size() > 1 || numb.size() > 1)
            if (a == b)
                ++ans;
    } else {
        long long tmpb = b;
        vector<long long> numb;
        long long base = get_max_ll(a);
        while (base > 0) {
            numb.push_back(tmpb / base);
            tmpb %= base;
            base /= a;
        }
        reverse(numb.begin(), numb.end());
        while (numb.back() == 0)
            numb.pop_back();

        long long sum = 0;
        for (long long c : numb)
            sum += c;

        if (sum == a)
            ++ans;

        if (sum == 1 && numb.size() > 1)
            ++ans;
    }

    cout << ans << endl;

    return 0;
}
