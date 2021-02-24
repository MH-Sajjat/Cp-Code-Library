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
const int inf     = (int) 2e9 + 9;
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
vi dis, par;

void precal(int n) {
    n += 2;
    g.resize(n);
    dis.resize(n, inf);
    par.resize(n, 0);
}

// complexity O(v * e) where v = number of vertex and e = number of edge;
bool belmanFord(int src, int n) {
    dis[src] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int u = 1; u <= n; ++u) {
            for (auto x : g[u]) {
                int v = x.ff, w = x.ss;
                if (dis[v] > dis[u] + w) {
                    if (i == n) return 0;
                    dis[v] = dis[u] + w;
                    par[v] = u;
                }
            }
        }
    }
    return 1;
}

void path(int u) {
    if (par[u]) path(par[u]);
    printf("%d ", u);
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
        for (int i = 1; i <= n; ++i) {
            int u = Int(), v = Int(), w = Int();
            g[u].pb({v, w});
        }
        int src = Int(), q = Int();
        if (belmanFord(src, n)) {
            while (q--) {
                int d = Int();
                if (dis[d] == inf) printf("Distance = infinite\n");
                else {
                    printf("Distance = %d\n", dis[d]);
                    path(d);
                    printf("\n");
                }
            }
        } else {
            printf("Negative cycle exists\n");
        }
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
