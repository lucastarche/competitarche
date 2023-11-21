/*
 * Problem:    B. Milena and Admirer
 * Judge:      Codeforces
 * Contest:    Codeforces Round 910 (Div. 2)
 * URL:        https://codeforces.com/contest/1898/problem/B
 * Solve date: 2023-11-20
 * Tags:
 */
#include "santolib/template.hpp"

int main() {
  fastIO();

  tint t;
  cin >> t;
  forsn(testcase, 1, t + 1) {
    tint n;
    cin >> n;

    vi nums(n);
    forn(i, n) cin >> nums[i];

    tint ans = 0;
    dforn(i, n - 1) {
      tint ops = (nums[i] / nums[i + 1]) + (nums[i] % nums[i + 1] > 0);
      nums[i] /= ops;
      ans += ops - 1;
    }
    cout << ans << '\n';
  }
}
