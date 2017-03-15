#include <iostream>
#include <vector>

using namespace std;

const int LIM = 3e+5 + 10;
const int MAX_LOG = 20;

int a[LIM];
int _min[LIM][MAX_LOG];
int gcd[LIM][MAX_LOG];
int log[LIM];

int get_gcd(int a, int b) {
  while (b != 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
}

void init(int n) {
  log[0] = 0;
  for (int i = 1; i < LIM; ++i) {
    log[i] = log[i - 1];
    if ((1 << (log[i] + 1)) < i)
      ++log[i];
  }

  for (int i = 0; i < n; ++i)
    _min[i][0] = gcd[i][0] = a[i];

  for (int pw = 1; pw < MAX_LOG; ++pw) {
    for (int i = 0; i < n; ++i) {
      int right = i + (1 << (pw - 1));
      _min[i][pw] = min(_min[i][pw - 1], right < n ? _min[right][pw - 1] : _min[i][pw - 1]);
      gcd[i][pw] = get_gcd(gcd[i][pw - 1], right < n ? gcd[right][pw - 1] : gcd[i][pw - 1]);
    }
  }
}

int get_min_seg(int l, int r) {
  int pw = log[r - l + 1];
  return min(_min[l][pw], _min[r - (1 << pw) + 1][pw]);
}

int get_gcd_seg(int l, int r) {
  int pw = log[r - l + 1];
  return get_gcd(gcd[l][pw], gcd[r - (1 << pw) + 1][pw]);
}

bool check(int n, int len) {
  for (int i = 0; i + len - 1 < n; ++i)
    if (get_min_seg(i, i + len - 1) == get_gcd_seg(i, i + len - 1))
      return true;
  return false;
}

vector<int> get_all(int n, int len) {
  vector<int> res;
  for (int i = 0; i + len - 1 < n; ++i)
    if (get_min_seg(i, i + len - 1) == get_gcd_seg(i, i + len - 1))
      res.push_back(i + 1);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  init(n);

  int l = 1, r = n, ans = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (check(n, m)) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  vector<int> res = get_all(n, ans);

  cout << res.size() << ' ' << ans - 1 << '\n';
  for (int i : res)
    cout << i << ' ';
  cout << '\n';

  return 0;
}
