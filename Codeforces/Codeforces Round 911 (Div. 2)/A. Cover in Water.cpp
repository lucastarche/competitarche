/*
 * Problem:    A. Cover in Water
 * Judge:      Codeforces
 * Contest:    Codeforces Round 911 (Div. 2)
 * URL:        https://codeforces.com/contest/1900/problem/0
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

    string s;
    cin >> s;
    s += '#';

    tint len = 0, maxLen = 0, totalLen = 0;
    for (auto c : s) {
      if (c == '.') len++;
      else {
        chmax(maxLen, len);
        totalLen += len;
        len = 0;
      }
    }

    if (maxLen >= 3) {
      cout << 2 << '\n';
    } else {
      cout << totalLen << '\n';
    }
  }
}
