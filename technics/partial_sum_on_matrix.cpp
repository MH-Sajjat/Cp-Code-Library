/*------------------------------------
   bismillahir rahmanir rahim
   author : md. sajjat hossen
   created : 06-September,2021 22:56:44
-------------------------------------*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long             ll;
typedef long double           ld;
typedef unsigned long long    ull;
typedef pair <int, int>       pii;
typedef pair <ll, ll>         pll;
typedef vector <int>          vi;
typedef vector <ll>           vll;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N          = (int) 2e5 + 5;
const int mxN        = (int) 1e6 + 6;
const int MOD        = (int) 1e9 + 7;
const int INF        = (int) 1e9 + 9;
const double EPS     = (double) 1e-9;

#define debug(x)    cerr << #x << " = " << x << '\n';
#define all(x)      x.begin(), x.end()
#define szof(x)     (int) x.size()
#define ff          first
#define ss          second
#define pb          push_back
#define mp          make_pair
#define PI          acos(-1.0)
#define TN          typename
#define nl          '\n'
#define Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr);

inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }

template <TN T> inline void umin(T &x, T y) { x = x < y ? x : y; }
template <TN T> inline void umax(T &x, T y) { x = x > y ? x : y; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

// partial sum on matrix.
int ar[1000][1000];

void build(int n, int m) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ar[i][j] += (ar[i][j - 1] + ar[i - 1][j] - ar[i - 1][j - 1]);
        }
    }
}

void updae(int x1, int y1, int x2, int y2, int k) {
    ar[x1][y1] += k;
    ar[x2 + 1][y2 + 1] += k;
    ar[x1][y2 + 1] -= k;
    ar[x2 + 1][y1] -= k;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // Fast_IO
    int test = 1, tc = 0;
    while (test--) {
        int n = Int(), m = Int();
        int q = Int();
        while (q--) {
            int x1 = Int(), y1 = Int(), x2 = Int(), y2 = Int();
            int k = Int();
            updae(x1, y1, x2, y2, k);
        }

        build(n, m);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                printf("%d ", ar[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
