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

const int N       = (int) 5e5 + 5;
const int mxN     = (int) 1e6 + 6;
const int MOD     = (int) 1e9 + 7;

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
#define    Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr);

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

ll ar[N];
vi g[N];
ll SPT[N][22], MX[N][22];
int level[N];

void dfs(int u, int p = -1, int l = 0) {
    level[u] = l;
    SPT[u][0] = (ll)p;
    if (p != -1) {
        MX[u][0] = max(ar[u], ar[p]);
    }
    for (int k = 1; k <= 20; ++k) {
        if (SPT[u][k - 1] != -1 && SPT[SPT[u][k - 1]][k - 1] != -1) {
            SPT[u][k] = SPT[SPT[u][k - 1]][k - 1];
            MX[u][k] = max(MX[u][k - 1], MX[SPT[u][k - 1]][k - 1]);
        }
    }
    for (auto v : g[u]) {
        if (p != v) {
            dfs(v, u, l + 1);
        }
    }
}

void build() {
    memset(SPT, -1, sizeof SPT);
    memset(MX, -1, sizeof MX);
    dfs(1);
}

ll query(int u, int v) {
    ll ans = max(ar[u], ar[v]);
    if (level[u] < level[v]) swap(u, v);
    for (int k = 20; k >= 0; --k) {
        if (SPT[u][k] != -1 && level[SPT[u][k]] >= level[v]) {
            ans = max(ans, MX[u][k]);
            u = SPT[u][k];
        }
    }
    if (u == v) return ans;
    for (int k = 20; k >= 0; --k) {
        if (SPT[u][k] != SPT[v][k]) {
            ans = max({ans, MX[u][k], MX[v][k]});
            u = SPT[u][k];
            v = SPT[v][k];
        }
    }
    ans = max({ans, MX[u][0], MX[v][0]});
    return ans;
}

int main() {
    // Fast_IO
    // clock_t tStart = clock();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    while (test--) {
        int n = Int(), q = Int();
        for (int i = 1; i <= n; ++i) ar[i] = Long();
        for (int i = 1; i < n; ++i) {
            int u = Int(), v = Int();
            g[u].pb(v);
            g[v].pb(u);
        }
        build();
        while (q--) {
            int u = Int(), v = Int();
            printf("%lld\n", query(u, v));
        }
    }
    // fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
