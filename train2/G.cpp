#include <iostream>
#include <vector>

using namespace std;

bool can(const vector<int>& labels, int val) {
    for (int i : labels) {
        if (i + val > labels.back())
            break;
        if (*lower_bound(labels.begin(), labels.end(), i + val) == i + val)
            return true;
    }
    return false;
}

int main() {
    int n, l, x, y;
    cin >> n >> l >> x >> y;
    vector<int> labels(n);
    for (int i = 0; i < n; ++i)
        cin >> labels[i];
    bool is_boys = can(labels, y), is_girls = can(labels, x);

    if (is_boys && is_girls) {
        cout << 0 << endl;
    } else if (is_boys) {
        cout << 1 << endl << x << endl;
    } else if (is_girls) {
        cout << 1 << endl << y << endl;
    } else {
        for (int p : labels) {
            if (p - x >= 0) {
                if (p - x - y >= 0) {
                    if (*lower_bound(labels.begin(), labels.end(), p - x - y) == p - x - y) {
                        cout << 1 << endl << p - x << endl;
                        return 0;
                    }
                }
                if (p - x + y <= l) {
                    if (*lower_bound(labels.begin(), labels.end(), p - x + y) == p - x + y) {
                        cout << 1 << endl << p - x << endl;
                        return 0;
                    }
                }
            }
            if (p + x <= l) {
                if (p + x - y >= 0) {
                    if (*lower_bound(labels.begin(), labels.end(), p + x - y) == p + x - y) {
                        cout << 1 << endl << p + x << endl;
                        return 0;
                    }
                }
                if (p + x + y >= 0) {
                    if (*lower_bound(labels.begin(), labels.end(), p + x + y) == p + x + y) {
                        cout << 1 << endl << p + x << endl;
                        return 0;
                    }
                }
            }
        }
        cout << 2 << endl << x << " " << y << endl;
    }

    return 0;
}
