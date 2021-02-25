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

vector<pair<int, pii>> edge;
vi par, Rank;

void precal(int n) {
    edge.resize(n + 2);
    par.resize(n + 2, 0);
    Rank.resize(n + 2, 0);
    for (int i = 0; i < n + 2; ++i) {
        par[i] = i;
    }
}

int Find(int u) {
    return par[u] = par[u] == u ? u : Find(par[u]);
}

// complexity O(E) where E = number of edge
bool Union(int a, int b) {
    int x = Find(a), y = Find(b);
    if (x == y) return 0;
    if (Rank[x] < Rank[y]) swap(x, y);
    par[y] = x;
    Rank[x] += Rank[y];
    return 1;
}

// complexity O(ElogE) where E = number of edge
int mstKruskal(int n) {
    sort(all(edge));
    int cost = 0;
    for (auto x : edge) {
        int w = x.ff, u = x.ss.ff, v = x.ss.ss;
        if (Union(u, v)) cost += w;
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
            edge.pb({w, {u, v}});
        }
        printf("Cost : %d\n", mstKruskal(m));
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
