#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair <int, int>    pii;
typedef pair <ll, ll>      pll;
typedef vector <int>       vi;
typedef vector <ll>        vll;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;
 
inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }
 
int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
 
const int N      = (int) 2e5 + 5;
const int mxN    = (int) 1e6 + 6;
const int MOD    = (int) 1e9 + 7;
const ll  INF    = (ll) 1e18 + 9;
const double EPS = (double) 1e-9;
 
#define debug(x) cerr << #x << " = " << x << '\n';
#define all(x)   x.begin(), x.end()
#define szof(x)  (int) x.size()
#define ff       first
#define ss       second
#define pb       push_back
#define mp       make_pair
#define PI       acos(-1.0)
#define TN       typename
#define nl       '\n'
#define Fast_IO  ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }
 
template <TN T> inline void umin(T &x, T y) { x = x < y ? x : y; }
template <TN T> inline void umax(T &x, T y) { x = x > y ? x : y; }
 
template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }
 
struct Node {
    ll mxPrefix, mxSuffix, totalSum, mxSubAraaySum;
    Node() {
        mxPrefix = mxSuffix = totalSum = mxSubAraaySum = -INF;
    }
} node[5 * mxN + 2];
vi L(5 * mxN + 2, -1), R(5 * mxN + 2, -1);
ll ar[mxN];
 
int cnt = 1;
 
int get(int& u) {
    if (u == -1) u = ++cnt;
    return u;
}
 
void merge(int at, int l, int r) {
    node[at].mxPrefix = max(node[l].mxPrefix, node[l].totalSum + node[r].mxPrefix);
    node[at].mxSuffix = max(node[r].mxSuffix, node[r].totalSum + node[l].mxSuffix);
    node[at].totalSum = node[l].totalSum + node[r].totalSum;
    node[at].mxSubAraaySum = max({node[l].mxSubAraaySum, node[r].mxSubAraaySum, node[l].mxSuffix + node[r].mxPrefix});  
}
 
void build(int at, int b, int e) {
    if (b == e) {
        node[at].mxPrefix = ar[b];
        node[at].mxSuffix = ar[b];
        node[at].totalSum = ar[b];
        node[at].mxSubAraaySum = ar[b];
        return;
    }
    int mid = (b + e) >> 1;
    build(get(L[at]), b, mid);
    build(get(R[at]), mid + 1, e);
    merge(at, L[at], R[at]);
}

void update(int at, int b, int e, int idx, int val) {
    if (idx < b or idx > e) return;
    if (b == e) {
        node[at].mxPrefix = val;
        node[at].mxSuffix = val;
        node[at].totalSum = val;
        node[at].mxSubAraaySum = val;
        return;
    }
    int mid = (b + e) >> 1;
    update(get(L[at]), b, mid, idx, val);
    update(get(R[at]),mid + 1, e, idx, val);
    merge(at, L[at], R[at]);
}
 
int query(int at, int b, int e, int l, int r) {
    if (l <= b and e <= r) return at;
    int mid = (b + e) >> 1;
    if (r <= mid) return query(get(L[at]), b, mid, l, r);
    if (l > mid) return query(get(R[at]), mid + 1, e, l, r);
    int u = query(get(L[at]), b, mid, l, r);
    int v = query(get(R[at]), mid + 1, e, l, r);
    int ret = -1;
    get(ret);
    merge(ret, u, v);
    return ret;
}

// problem link: https://cses.fi/problemset/task/1190/
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // Fast_IO
    int test = 1, tc = 0;
    while (test--) {
        int n = Int(), m = Int();
        for (int i = 1; i <= n; ++i) ar[i] = Long();
        build(1, 1, n);
        while (m--) {
            int idx = Int(), val = Int();
            update(1, 1, n, idx, val);
            int u = query(1, 1, n, 1, n);
            ll res = node[u].mxSubAraaySum;
            res = max(res, 0LL);
            printf("%lld\n", res);
        }
    }
    return 0;
} 
