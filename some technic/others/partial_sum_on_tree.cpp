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

// problem link: https://www.codechef.com/JCI42021/problems/IPLTREE

ll c[N], psum[N];
vi g[N];
int par[N];

void dfs(int u, int p = -1) {
    par[u] = p;
    if (u != 1) psum[u] += psum[p];
    for (auto v : g[u]) {
        if (v != p) dfs(v, u);
    }
}

void query(int u, int v, ll val) {
    if (par[u] == v) {
        psum[u] += val;
    } else {
        psum[v] -= val;
        psum[1] += val;
    }
}

int main() {
    // Fast_IO
    // clock_t tStart = clock();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    while (test--) {
        int n = Int();
        for (int i = 1; i <= n; ++i) c[i] = Long();
        int a[n + 1], b[n + 1];
        for (int i = 1; i < n; ++i) {
            int u = Int(), v = Int();
            g[u].pb(v);
            g[v].pb(u);
            a[i] = u;
            b[i] = v;
        }
        dfs(1);
        int q = Int();
        while (q--) {
            int ck = Int(), id = Int();
            ll val = Long();
            if (ck == 1) query(a[id], b[id], val);
            else query(b[id], a[id], val);
        }
        dfs(1);
        for (int i = 1; i <= n; ++i) cout << psum[i] + c[i] << nl;
    }
    // fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
