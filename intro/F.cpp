#include <iostream>
#include <cstring>

using namespace std;

const int LIM = 1010;

int a[2][LIM];

int main() {
    int n, m;
    cin >> n >> m;
    if (n >= m) {
        cout << "YES" << endl;
        return 0;
    }
    int id = 0;
    int x;
    cin >> x;
    a[id][x % m] = 1;
    for (int i = 1; i < n; ++i) {
        int next = 1 - id;
        memset(a[next], 0, LIM * sizeof(int));
        cin >> x;
        a[next][x % m] = 1;
        for (int j = 0; j < m; ++j)
            if (a[id][j] == 1)
                a[next][j] = a[next][(j + x) % m] = 1;
        id = next;
    }

    cout << (a[id][0] == 1 ? "YES" : "NO") << endl;

    return 0;
}
