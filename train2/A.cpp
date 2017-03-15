#include <iostream>
#include <vector>

using namespace std;

vector <int> ans;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        bool good = true;
        for (int j = 0; j < n; ++j) {
            int res;
            cin >> res;
            if (res == 1 || res == 3)
                good = false;
        }
        if (good)
            ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
