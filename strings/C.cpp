#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

string get_eq(string& s) {
    if (s.length() & 1)
        return s;

    string a = "", b = "";
    for (size_t i = 0; i < s.length() / 2; ++i)
        a += s[i];
    a = get_eq(a);
    for (size_t i = s.length() / 2; i < s.length(); ++i)
        b += s[i];
    b = get_eq(b);

    return a < b ? a + b : b + a;
}

int main() {
    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    a = get_eq(a);
    b = get_eq(b);

    cout << (a == b ? "YES" : "NO") << endl;


    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
