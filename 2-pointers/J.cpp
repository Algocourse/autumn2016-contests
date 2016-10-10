#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<pair<int, int>> solder, brone, ans;
    pair<int, int> tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp.first;
        tmp.second = i;
        solder.push_back(tmp);
    }
    for (int i = 1; i <= m; i++) {
        cin >> tmp.first;
        tmp.second = i;
        brone.push_back(tmp);
    }
    sort(solder.begin(), solder.end());
    sort(brone.begin(), brone.end());

    unsigned int j = 0;
    unsigned int i = 0;

    while ((i < solder.size()) && (j < brone.size())) {
        int minsize = solder[i].first - x, maxsize = solder[i].first + y;
        while ((brone[j].first < minsize) && (j < brone.size())) {
            j++;
        }
        if ((j < brone.size()) && (brone[j].first <= maxsize)) {
            tmp.first = solder[i].second;
            tmp.second = brone[j].second;
            ans.push_back(tmp);
            j++;
        }
        i++;
    }
    cout << ans.size() << endl;

    for (unsigned int o = 0; o < ans.size(); o++)
        cout << ans[o].first << " " << ans[o].second << endl;
    return 0;
}
