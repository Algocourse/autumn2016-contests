#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int LIM = 1e+5 + 10;

int c[LIM];
vector<unordered_set<int>> neig(LIM);
bool is_color[LIM];

int main() {
    int n, m;
    cin >> n >> m;

    int ans = LIM;

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        ans = min(ans, c[i]);
        is_color[c[i]] = true;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (c[u] != c[v]) {
            neig[c[u]].insert(c[v]);
            neig[c[v]].insert(c[u]);
        }
    }

    for (int i = 0; i < LIM; ++i)
        if (is_color[i] && neig[i].size() > neig[ans].size())
            ans = i;

    cout << ans << endl;

    return 0;
}
