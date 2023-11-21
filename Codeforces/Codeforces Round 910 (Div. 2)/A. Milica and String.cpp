/*
 * Problem:    A. Milica and String
 * Judge:      Codeforces
 * Contest:    Codeforces Round 910 (Div. 2)
 * URL:        https://codeforces.com/contest/1898/problem/A
 * Solve date: 2023-11-19
 * Tags:
 */
#include "santolib/template.hpp"

int main() {
  fastIO();

  tint t;
  cin >> t;
  forsn(testcase, 1, t + 1) {
    tint n, k;
    string s;
    cin >> n >> k >> s;

    tint bs = 0;
    for (auto c : s) bs += (c == 'B');

    if (bs == k) {
      cout << 0 << '\n';
    } else if (bs > k) {
      tint ans = 0;
      while (bs > k) {
        bs -= (s[ans++] == 'B');
      }
      cout << "1\n" << ans << " A\n";
    } else {
      tint ans = 0;
      while (bs < k) {
        bs += (s[ans++] == 'A');
      }
      cout << "1\n" << ans << " B\n";
    }
  }
}
