/*
 * Problem:    B. Deja Vu
 * Judge:      Codeforces
 * Contest:    Codeforces Round 907 (Div. 2)
 * URL:        https://codeforces.com/contest/1891/problem/B
 * Solve date: 2023-11-26
 * Tags:
 */
#include "santolib/template.hpp"

tint ctz(tint x) {
  tint ans = 0;
  while (x % 2 == 0) ans++, x /= 2;
  return ans;
}

int main() {
  fastIO();

  tint t;
  cin >> t;
  forsn(testcase, 1, t + 1) {
    tint n, q;
    cin >> n >> q;
    vi nums(n);
    vector<vi> buckets(31);

    forn(i, n) {
      tint x;
      cin >> x;
      buckets[ctz(x)].push_back(i);
      nums[i] = x;
    }

    forn(i, q) {
      tint x;
      cin >> x;

      forsn(xi, x, 31) {
        for (auto y : buckets[xi]) {
          buckets[x - 1].push_back(y);
          nums[y] += (1 << (x - 1));
        }
        buckets[xi].clear();
      }
    }

    forn(i, n) cout << nums[i] << " \n"[i == n - 1];
  }
}
