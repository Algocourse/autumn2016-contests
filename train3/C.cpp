#include <iostream>

using namespace std;

char a[400][400];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    bool f = true;
    char x = a[0][0];
    char y = a[0][1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || (i + j == n - 1)) {
                if (a[i][j] != x)
                    f = false;
            } else if (a[i][j] != y) {
                f = false;
            }
        }
    }
    if (x == y)
        f = false;
    cout << (f ? "YES" : "NO") << endl;

    return 0;
}
