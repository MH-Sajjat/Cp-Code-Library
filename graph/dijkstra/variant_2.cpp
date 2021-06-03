/*---------------------------------------
   BISMILLAHIR RAHMANIR RAHIM
   AUTHOR : Md. Sajjat Hossen
   TIME : 02-June,2021 10:22:39 AM
----------------------------------------*/

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

const int N       = (int) 2e4 + 5;
const int mxN     = (int) 1e6 + 6;
const int MOD     = (int) 1e9 + 7;
const ll INF      = (ll) 1e16 + 9;
const double EPS  = (double) 1e-9;

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

inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }

template <TN T> inline void umin(T &x, T y) { x = x < y ? x : y; }
template <TN T> inline void umax(T &x, T y) { x = x > y ? x : y; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

// problem link: https://vjudge.net/contest/441453#problem/H

vector<pair<int, ll>> g1[N], g2[N];
ll dis1[N], dis2[N], W[N];
int U[N], V[N];

void dijkstra1(int src, int n) {
    for (int i = 1; i <= n; ++i) dis1[i] = INF;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dis1[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        ll du = pq.top().ff;
        int u = pq.top().ss;
        pq.pop();
        if (du != dis1[u]) continue;
        for (auto x : g1[u]) {
            int v = x.ff;
            ll w = x.ss;
            if (dis1[v] > dis1[u] + w) {
                dis1[v] = dis1[u] + w;
                pq.push({dis1[v], v});
            }
        }
    }
}

void dijkstra2(int src, int n) {
    for (int i = 1; i <= n; ++i) dis2[i] = INF;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dis2[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        ll du = pq.top().ff;
        int u = pq.top().ss;
        pq.pop();
        if (du != dis2[u]) continue;
        for (auto x : g2[u]) {
            int v = x.ff;
            ll w = x.ss;
            if (dis2[v] > dis2[u] + w) {
                dis2[v] = dis2[u] + w;
                pq.push({dis2[v], v});
            }
        }
    }
}

void clr(int n) {
    for (int i = 1; i <= n; ++i) {
        g1[i].clear();
        g2[i].clear();
    }
}

int main() {
    // Fast_IO
    // clock_t tStart = clock();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int test = Int(), tc = 0;
    while (test--) {
        int n = Int(), m = Int(), s = Int(), t = Int();
        ll p = Long();
        for (int i = 1; i <= m; ++i) {
            U[i] = Int(), V[i] = Int(), W[i] = Long();
            g1[U[i]].pb({V[i], W[i]});
            g2[V[i]].pb({U[i], W[i]});
        }
        dijkstra1(s, n);
        dijkstra2(t, n);
        ll res = -1;
        for (int i = 1; i <= m; ++i) {
            if (dis1[U[i]] + dis2[V[i]] + W[i] <= p) umax(res, W[i]);
        }
        printf("%lld\n", res);
        clr(n);
    }
    // fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
