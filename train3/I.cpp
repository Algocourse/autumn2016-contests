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

    int n, m;
    cin >> n >> m;
    vector<string> matr(n);
    for (int i = 0; i < n; ++i)
        cin >> matr[i];
    vector<vector<int>> ones(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        ones[i][m - 1] = matr[i][m - 1] == '1' ? 1 : 0;
        for (int j = m - 2; j >= 0; --j)
            ones[i][j] = matr[i][j] == '1' ? ones[i][j + 1] + 1 : 0;
    }

    int ans = 0;
    for (int col = 0; col < m; ++col) {
        vector<int> one_lengths(n);
        for (int i = 0; i < n; ++i)
            one_lengths[i] = ones[i][col];
        sort(one_lengths.begin(), one_lengths.end(), greater<int>());
        for (int i = 0; i < n; ++i)
            ans = max(ans, (i + 1) * one_lengths[i]);
    }

    cout << ans << endl;

    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
