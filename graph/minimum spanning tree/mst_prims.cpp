#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef  long long               ll;
typedef  long double             ld;
typedef  unsigned long long      ull;
typedef  pair<int, int>          pii;
typedef  pair<ll, ll>            pll;
typedef  vector<int>             vi;
typedef  vector<ll>              vll;
typedef  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef  tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N       = (int) 2e5 + 5;
const int mxN     = (int) 1e6 + 6;
const ll MOD      = (ll) 1e9 + 7;

#define    debug(x)    cerr << #x << " = " << x << '\n';
#define    all(x)      x.begin(), x.end()
#define    szof(x)     (int) x.size()
#define    ff          first
#define    ss          second
#define    pb          push_back
#define    mp          make_pair
#define    PI          acos(-1.0)
#define    TN          typename
#define    nl          '\n'
#define    Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

vector<vector<pii>> g;
vector<bool> vis;

void precal(int n) {
    g.clear();
    vis.clear();
    g.resize(n + 3);
    vis.resize(n + 3, 0);
}

// complexity O(ElongE) where E = number of edge.
int mstPrims(int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    int cost = 0;
    while (!pq.empty()) {
        int u = pq.top().ss, w = pq.top().ff;
        pq.pop();
        if (vis[u]) continue;
        cost += w;
        vis[u] = 1;
        for (auto x : g[u]) {
            int v = x.ss, wt = x.ff;
            if (!vis[v]) pq.push({wt, v});
        }
    }
    return cost;
}

int main() {
    //Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = Int(), tc = 0;
    while (test--) {
        int n = Int(), m = Int();
        precal(n);
        for (int i = 1; i <= m; ++i) {
            int u = Int(), v = Int(), w = Int();
            g[u].pb({w, v});
            g[v].pb({w, u});
        }
        printf("Cost : %d\n", mstPrims(1));
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
