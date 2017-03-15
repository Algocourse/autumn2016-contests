#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int LIM = 2e+5 + 10;
const long long SHIFT = 1e+9 + 10;
const long long MAX_COORD = 1e+9 + 10 + SHIFT;

struct segment {
    int l, r, id;
};

struct node {
    int l, r, cnt;
};

node tree[100 * LIM];
int root = 0, size = 1;
vector<int> ans;

bool operator <(const segment& a, const segment& b) {
    return a.r < b.r;
}

template <class T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    for (const T elem : v)
        out << elem << "\n";
    out << endl;
    return out;
}

void build() {
    tree[root].l = tree[root].r = -1;
    tree[root].cnt = 0;
}

void set(int v, long long l, long long r, int pos) {
    if (l == r) {
        tree[v].l = tree[v].r = -1;
        tree[v].cnt = 1;
        return;
    }

    if (tree[v].l == -1) {
        tree[size].l = tree[size].r = -1;
        tree[size].cnt = 0;
        tree[v].l = size++;
    }
    if (tree[v].r == -1) {
        tree[size].l = tree[size].r = -1;
        tree[size].cnt = 0;
        tree[v].r = size++;
    }

    long long m = (l + r) / 2;

    if (pos <= m)
        set(tree[v].l, l, m, pos);
    else
        set(tree[v].r, m + 1, r, pos);

    tree[v].cnt = tree[tree[v].l].cnt + tree[tree[v].r].cnt;
}

int get(int v, long long l, long long r, int ql, int qr) {
    if (v == -1)
        return 0;

    if (l == ql && r == qr)
        return tree[v].cnt;

    long long m = (l + r) / 2;
    if (qr <= m)
        return get(tree[v].l, l, m, ql, qr);
    else if (ql > m)
        return get(tree[v].r, m + 1, r, ql, qr);
    else
        return get(tree[v].l, l, m, ql, m) + get(tree[v].r, m + 1, r, m + 1, qr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    ans.resize(n);
    vector<segment> seg(n);
    for (int i = 0; i < n; ++i) {
        cin >> seg[i].l >> seg[i].r;
        seg[i].l += SHIFT;
        seg[i].r += SHIFT;
        seg[i].id = i;
    }

    sort(seg.begin(), seg.end());
    build();

    for (const auto& it : seg) {
        ans[it.id] = get(root, 0, MAX_COORD, it.l, MAX_COORD);
        set(root, 0, MAX_COORD, it.l);
    }

    cout << ans;

    return 0;
}
