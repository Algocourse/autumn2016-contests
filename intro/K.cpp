#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a * d == c * b) {
    cout << "0/1";
  } else if (a * d > c * b) {
    int k = (a * d - b * c) / gcd((a * d - b * c), a * d);
    cout << k << '/' << a * d / gcd((a * d - b * c), a * d);
  } else {
    int k = (b * c - a * d) / gcd((b * c - a * d), b * c);
    cout << k << '/' << b * c / gcd((b * c - a * d), b * c);
  }

  return 0;
}
