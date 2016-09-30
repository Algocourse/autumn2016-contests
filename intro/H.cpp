#include <iostream>

using namespace std;

int a[5555];

int main() {
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a[tmp]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == 0)
            ++ans;
    cout << ans;
    return 0;
}
