/*
 * Problem:    E. Transitive Graph
 * Judge:      Codeforces
 * Contest:    Codeforces Round 911 (Div. 2)
 * URL:        https://codeforces.com/contest/1900/problem/E
 * Solve date: 2023-11-26
 * Tags:
 */
#include "santolib/template.hpp"

const tint INF = 1e18;

pii operator+(pii lhs, pii rhs) {
  return make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

void dfs(const vector<vi> &adj, vi &comp, vi *order, tint compNum, tint u) {
  if (comp[u] >= 0) return;
  comp[u] = compNum;
  for (auto v : adj[u]) dfs(adj, comp, order, compNum, v);
  if (order) order->push_back(u);
}

pair<vi, tint> kosaraju(const vector<pii> &edges, tint n) {
  vector<vi> adj(n), rev(n);
  for (auto [u, v] : edges) adj[u].push_back(v), rev[v].push_back(u);

  vi comp(n, -1), dfsOrder;
  dfsOrder.reserve(n);
  forn(i, n) dfs(adj, comp, &dfsOrder, 0, i);

  fill(all(comp), -1);
  reverse(all(dfsOrder));

  tint compNum = 0;
  for (auto u : dfsOrder) {
    if (comp[u] < 0) dfs(rev, comp, nullptr, compNum++, u);
  }

  return {comp, compNum};
}

int main() {
  fastIO();

  tint t;
  cin >> t;
  forsn(testcase, 1, t + 1) {
    tint n, m;
    cin >> n >> m;

    vi val(n);
    vector<pii> edges(m);
    forn(i, n) cin >> val[i];
    forn(i, m) {
      tint u, v;
      cin >> u >> v;
      u--, v--;
      edges[i] = {u, v};
    }

    auto [comp, k] = kosaraju(edges, n);
    vector<pii> fatval(k);
    vector<vi> byComp(k);
    forn(i, n) 
      fatval[comp[i]].first++, fatval[comp[i]].second -= val[i], byComp[comp[i]].push_back(i + 1);

    vector<vi> adj(k);
    for (auto [u, v] : edges) {
      if (comp[u] != comp[v]) adj[comp[u]].push_back(comp[v]);
    }

    vi order, visit(k, -1);
    forn(i, k) dfs(adj, visit, &order, 0, i);

    vector<pii> dp(k, {-INF, -INF});
    forn(i, k) dp[i] = fatval[i];
    reverse(all(order));

    for (auto u : order) {
      for (auto v : adj[u]) {
        if (dp[v] < dp[u] + fatval[v]) {
          dp[v] = dp[u] + fatval[v];
        }
      }
    }

    tint end = 0;
    forn(i, k) if (dp[i] > dp[end]) end = i;
    cout << dp[end].first << ' ' << (-dp[end].second) << '\n';
  }
}
