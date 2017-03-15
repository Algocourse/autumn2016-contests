#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int LIM = 1e+5 + 10;
const int MOD = 1e+9 + 7;

int cost[LIM];
vector<vector<int>> edge(LIM), rev(LIM);
vector<bool> used;
vector<int> comp, sorted;


void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < (int) edge[v].size(); ++i)
        if (!used[edge[v][i]])
            dfs(edge[v][i]);
    sorted.push_back(v);
}

void rev_dfs(int v) {
    used[v] = true;
    comp.push_back (v);
    for (int i = 0; i < (int)rev[v].size(); ++i)
        if (!used[rev[v][i]])
            rev_dfs(rev[v][i]);
}

int main() {
    int n, m;
    cin >> n;
    used.resize(n + 1);
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    cin >> m;
    int from, to;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        --to;
        --from;
        edge[from].push_back(to);
        rev[to].push_back(from);
    }
    long long ans = 0;
    long long cnt = 1;
    for (int i = 0; i < n; i++) {
        if (!used[i])
            dfs(i);
    }

    used.assign (n, false);

    for (int i = 0; i < n; ++i) {
        int v = sorted[n - i - 1];
        if (!used[v]) {
            rev_dfs(v);
            long long _min = 2e+9;
            long long _cnt = 0;
            for (int i = 0; i < (int)comp.size(); i++) {
                if (cost[comp[i]] == _min) {
                    _cnt++;
                }
                if (cost[comp[i]] < _min) {
                    _min = cost[comp[i]];
                    _cnt = 1;
                }
            }
            ans += _min;
            cnt *= _cnt;
            cnt %= MOD;
            comp.clear();
        }
    }

    cout << ans << " " << cnt;

    return 0;
}
