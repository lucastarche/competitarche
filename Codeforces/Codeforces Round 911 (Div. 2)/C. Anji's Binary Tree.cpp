/*
 * Problem:    C. Anji's Binary Tree
 * Judge:      Codeforces
 * Contest:    Codeforces Round 911 (Div. 2)
 * URL:        https://codeforces.com/contest/1900/problem/C
 * Solve date: 2023-11-26
 * Tags:
 */
#include "santolib/template.hpp"

const tint INF = 1e18;
tint solve(const vector<pii> &next, const string& s, tint x) {
  if (x == 0) return INF;
  char c = s[x - 1];
  if (next[x].first == 0 && next[x].second == 0) return 0;

  return min(
    (c != 'L') + solve(next, s, next[x].first),
    (c != 'R') + solve(next, s, next[x].second)
  );
}

int main() {
  fastIO();

  tint t;
  cin >> t;
  forsn(testcase, 1, t + 1) {
    tint n;
    cin >> n;

    string s;
    cin >> s;

    vector<pii> next(n + 1);
    forn(i, n) cin >> next[i + 1].first >> next[i + 1].second;
    cout << solve(next, s, 1) << '\n';
  }
}
