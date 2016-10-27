#include <iostream>

using namespace std;

const int LIM = 1e+5 + 10;

int a[LIM];
int cnt[LIM];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    cnt[a[i]] = max(1, cnt[a[i] - 1] + 1);
    ans = max(ans, cnt[a[i]]);
  }
  cout << n - ans << endl;

  return 0;
}
