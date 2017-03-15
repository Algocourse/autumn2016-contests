#include <iostream>
#include <cstring>

using namespace std;

int a[4];

int main() {
    string s;
    cin >> s;
    for (char c : s)
        if (c != '+' )
            ++a[c - '1'];

    int pos = 0;
    while (a[0]) {
        s[pos] = '1';
        --a[0];
        pos += 2;
    }
    while (a[1] > 0) {
        s[pos] = '2';
        --a[1];
        pos += 2;
    }
    while (a[2] > 0) {
        s[pos] = '3';
        --a[2];
        pos += 2;
    }

    cout << s << endl;

    return 0;
}
