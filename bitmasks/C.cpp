#include <iostream>
#include <cstring>

using namespace std;

long long l, r;
string s1, s2, ans;

void init() {
    long long t1 = l, t2 = r;
    for (int i = 0; i < 64; ++i) {
        int bit0 = t1 & 1;
        s1[63 - i] = bit0 + '0';
        bit0 = t2 & 1;
        s2[63 - i] = bit0 + '0';
        t1 = t1 >> 1;
        t2 = t2 >> 1;
    }
}

void solve(int bit) {
    while (s1[bit] == s2[bit] && bit < 64) {
        ++bit;
        ans[bit] = '0';
    }
    while (bit < 64) {
        ans[bit] = '1';
        ++bit;
    }
}

void print() {
    long long answer = 0;
    for (int i = 0; i < 64; ++i)
        answer = answer * 2 + (ans[i] - '0');
    cout << answer << endl;
}

int main() {
    cin >> l >> r;
    for (int i = 0; i < 64; i++)
        s1 += "0";
    ans = s2 = s1;
    init();
    solve(0);
    print();

    return 0;
}

