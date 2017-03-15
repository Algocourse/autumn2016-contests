#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    for (int pos = s.length() - 1; pos >= 0; --pos) {
        if (s[pos] == 'z') {
            s[pos] = 'a';
        } else {
            ++s[pos];
            break;
        }
    }

    cout << (s < t ? s : "No such string") << endl;

    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
