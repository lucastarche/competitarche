/*
 * Problem:    A. Sorting with Twos
 * Judge:      Codeforces
 * Contest:    Codeforces Round 907 (Div. 2)
 * URL:        https://codeforces.com/contest/1891/problem/A
 * Solve date: 2023-11-26
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

    bool increasingPerGroup = true;
    forn(i, 5) {
      forsn(j, (1 << i) + 1, min(1LL << (i + 1), n)) {
        if (nums[j - 1] > nums[j]) increasingPerGroup = false;
      }
    }

    cout << YN(increasingPerGroup) << '\n';
  }
}
