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

const int N       = (int) 1e6 + 5;
const int mxN     = (int) 1e6 + 6;
const int MOD     = (int) 1e9 + 7;
const int INF     = (int) 1e9 + 9;
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

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

// problem link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=422

int ar[N], dp[N], s[N], n;

void fun() {
    for (int i = 1; i <= n + 1; ++i) s[i] = INF;
    s[0] = -INF;
    int len = 0;
    for (int i = 1; i <= n; ++i) {
        int l = 0, r = len;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (s[mid] < ar[i]) {
                l = mid + 1;
            } else r = mid - 1;
        }
        s[l] = ar[i];
        if (len < l) {
            len = l;
        }
        dp[i] = l;
    }
}

int main() {
    // Fast_IO
    // clock_t tStart = clock();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    while (test--) {
        n = 0;
        while (scanf("%d", &ar[++n]) != EOF) {
        }
        --n;
        
        fun();
        int res = 0, start = 0;
        for (int i = n; i >= 1; --i) {
            if (res < dp[i]) {
                res = dp[i];
                start = i;
            }
        }
        vi v;
        int top = start;
        v.pb(ar[start]);
        for (int i = start - 1; i >= 1; --i) {
            if (ar[i] < ar[top] && dp[i] == dp[top] - 1) {
                v.pb(ar[i]);
                top = i;
            }
        }
        printf("%d\n", res);
        printf("-\n");
        for (int i = szof(v) - 1; i >= 0; --i) {
            printf("%d\n", v[i]);
        }
    }
    // fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
