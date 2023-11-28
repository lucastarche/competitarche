/*
 * Problem:    D. Small GCD
 * Judge:      Codeforces
 * Contest:    Codeforces Round 911 (Div. 2)
 * URL:        https://codeforces.com/contest/1900/problem/D
 * Solve date: 2023-11-27
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
    sort(all(nums));

    tint m = nums.back() + 1;
    vector<vi> indices(m);
    forn(i, n) {
      tint x = nums[i];
      indices[1].push_back(i);
      if (x != 1) indices[x].push_back(i);

      for (tint y = 2; y * y <= x; y++) {
        if (x % y == 0) {
          indices[y].push_back(i);
          if (y * y != x) indices[x / y].push_back(i);
        }
      }
    }

    vi x(m);
    forn(i, m) forn(j, sz(indices[i])) {
      x[i] += j * (n - indices[i][j] - 1);
    }

    dforsn(i, 1, m) for (tint j = 2 * i; j < m; j += i) x[i] -= x[j];
    forn(i, m) x[i] *= i;

    tint ans = accumulate(all(x), 0LL);
    cout << ans << '\n';
  }
}
