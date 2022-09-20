#include <bits/stdc++.h>
using namespace std;

typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair<int, int>     pii;
typedef pair<ll, ll>       pll;
typedef vector<int>        vi;
typedef vector<ll>         vll;

const int N      = (int) 2e5 + 5;
const int mxN    = (int) 1e6 + 6;
const int MOD    = (int) 1e9 + 7;
const int INF    = (int) 1e9 + 9;
const double EPS = (double) 1e-9;

#define all(x)   x.begin(), x.end()
#define szof(x)  (int) x.size()
#define ff       first
#define ss       second
#define pb       push_back
#define nl       '\n'
#define PI       acos(-1.0)
#define debug(x) cerr << #x << " = " << x << '\n';

/*................. let's try one more time .................*/

vi g[N];
vector<bool> used, art;
vector<int> dis, low;
int T = 0;

void dfs(int u, int par = -1) {
  used[u] = 1;
  dis[u] = low[u] = ++T;
  int child = 0;
  for (auto v : g[u]) {
    if (v == par) continue;
    if (used[v]) {
      low[u] = min(low[u], dis[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      child++;
    }
    if (low[v] >= dis[u] and par != -1) art[u] = 1;
  }
  if (par == -1 and child > 1) art[u] = 1;
}

int main() {
#ifdef LOCAL
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  cin >> test;
  while (test--) {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) g[i].clear();
    used.assign(n + 2, 0);
    art.assign(n + 2, 0);
    dis.assign(n + 2, 0);
    low.assign(n + 2, 0);
    T = 0;
    for (int i = 1; i <= m; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans += art[i];
    cout << "Case " << ++tc << ": " << ans << nl;
    for (int i = 1; i <= n; ++i) if (art[i]) cout << i << " ";
    cout << nl;

  }
  return 0;
}
