#include <iostream>
#include <vector>

using namespace std;

const int LIM = 2014;

vector<vector<int>> pos(LIM);
vector<vector<int>> ans(3);

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        pos[val].push_back(i + 1);
    }
    bool third = false, ready = false;
    for (int i = 0; i < LIM; ++i) {
        if (pos[i].size() == 0) {
            continue;
        } else if (pos[i].size() == 1) {
            ans[0].push_back(pos[i][0]);
            ans[1].push_back(pos[i][0]);
            ans[2].push_back(pos[i][0]);
        } else if (pos[i].size() == 2) {
            if (!third) {
                ans[0].push_back(pos[i][0]);
                ans[0].push_back(pos[i][1]);
                ans[1].push_back(pos[i][0]);
                ans[1].push_back(pos[i][1]);
                ans[2].push_back(pos[i][1]);
                ans[2].push_back(pos[i][0]);
                third = true;
            } else {
                ans[0].push_back(pos[i][1]);
                ans[0].push_back(pos[i][0]);
                ans[1].push_back(pos[i][0]);
                ans[1].push_back(pos[i][1]);
                ans[2].push_back(pos[i][1]);
                ans[2].push_back(pos[i][0]);
                ready = true;
            }
        } else {
            for (int j = 0; j < (int)pos[i].size(); ++j) {
                ans[0].push_back(pos[i][j]);
                ans[1].push_back(pos[i][(j + 1) % pos[i].size()]);
                ans[2].push_back(pos[i][(j + 2) % pos[i].size()]);
                ready = third = true;
            }
        }
    }
    if (!ready) {
        cout << "NO" << endl;
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i)
            cout << ans[0][i] << " ";
        cout << endl;
        for (int i = 0; i < n; ++i)
            cout << ans[1][i] << " ";
        cout << endl;
        for (int i = 0; i < n; ++i)
            cout << ans[2][i] << " ";
        cout << endl;
    }
    return 0;
}
