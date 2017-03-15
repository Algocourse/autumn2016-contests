#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

const int MAX_BIT = 62;

inline bool is_bit(long long mask, int b) {
    return (mask >> b) & 1;
}

bool is_all_bits(long long mask, int b) {
    while (b >= 0) {
        if (!is_bit(mask, b))
            return false;
        --b;
    }
    return true;
}

long long solve(long long l, long long r) {
    long long res = 0;
    int bit = MAX_BIT;
    while (bit >= 0) {
        if (is_bit(r, bit) && !is_bit(l, bit)) {
            if (is_all_bits(r, bit))
                res += (1LL << bit);
            --bit;
            break;
        }
        res += (1LL * is_bit(r, bit) << bit);
        --bit;
    }

    while (bit >= 0) {
        res += (1LL << bit);
        --bit;
    }

    return res;
}

int main() {
    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long l, r;
        cin >> l >> r;
        cout << solve(l, r) << '\n';
    }

    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
