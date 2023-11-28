/*
 * Problem:    B. Laura and Operations
 * Judge:      Codeforces
 * Contest:    Codeforces Round 911 (Div. 2)
 * URL:        https://codeforces.com/contest/1900/problem/B
 * Solve date: 2023-11-26
 * Tags:
 */
#include "santolib/template.hpp"

tint trySolve(tint a, tint b, tint c) {
  if (b > c) swap(b, c);

  if ((c - b) % 2 != 0) return 0;
  return 1;
}

int main() {
  fastIO();

  tint t;
  cin >> t;
  forsn(testcase, 1, t + 1) {
    tint a, b, c;
    cin >> a >> b >> c;

    cout << trySolve(a, b, c) << ' ' << trySolve(b, c, a) << ' ' << trySolve(c, a, b) << '\n';
  }
}
