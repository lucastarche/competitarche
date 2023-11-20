#pragma once
#include <bits/stdc++.h>
#define forn(i, n) for (tint i = 0; i < tint(n); i++)
#define forsn(i, s, n) for (tint i = s; i < tint(n); i++)
#define dforn(i, n) for (tint i = tint(n) - 1; i >= 0; i--)
#define dforsn(i, s, n) for (tint i = tint(n) - 1; i >= s; i--)
#define sz(x) tint(x.size())
#define all(x) x.begin(), x.end()
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;

using tint = long long;
using vi = vector<tint>;
using pii = pair<tint, tint>;

inline void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

inline string YN(bool x, string y = "YES", string n = "NO") { return (x ? y : n); }

template <typename T>
inline void chmax(T &lhs, T rhs) {
  lhs = max(lhs, rhs);
}

template <typename T>
inline void chmin(T &lhs, T rhs) {
  lhs = min(lhs, rhs);
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  forn(i, sz(v)) {
    if (i > 0) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

template <typename T, size_t N>
ostream &operator<<(ostream &os, const array<T, N> &v) {
  os << "[";
  forn(i, N) {
    if (i > 0) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}
