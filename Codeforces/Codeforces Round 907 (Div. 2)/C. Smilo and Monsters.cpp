/*
 * Problem:    C. Smilo and Monsters
 * Judge:      Codeforces
 * Contest:    Codeforces Round 907 (Div. 2)
 * URL:        https://codeforces.com/contest/1891/problem/C
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

    sort(all(nums));
    tint total = accumulate(all(nums), 0LL);

    tint x = 0, pos = 0;
    while (x + nums[pos] <= total / 2 + total % 2) x += nums[pos], pos++;

    cout << (total / 2 + total % 2) + (n - pos) << '\n';
  }
}
