/*-----------------------------------
  bismillahir rahmanir rahim
  @author : md. sajjat hossen
  created : 16-October,2021 22:40:39
------------------------------------*/

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
const int INF    = (int) 1e9 + 9;
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

// problem link: https://codeforces.com/contest/888/problem/E

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // Fast_IO
    int test = 1, tc = 0;
    while (test--) {
        int n = Int(), m = Int();
        vi v1, v2, c1, c2;
        for (int i = 1; i <= n; ++i) {
            int x = Int();
            x %= m;
            if (i <= (n / 2)) v1.pb(x);
            else v2.pb(x);
        }

        int n1 = szof(v1), n2 = szof(v2);
        for (int i = 0; i < (1 << n1); ++i) {
            bitset<31> bit(i);
            int x = 0;
            for (int j = 0; j < 31; ++j) {
                if (bit.test(j)) x = add(x, v1[j], m);
            }
            c1.pb(x);
        }
        for (int i = 0; i < (1 << n2); ++i) {
            bitset<31> bit(i);
            int x = 0;
            for (int j = 0; j < 31; ++j) {
                if (bit.test(j)) x = add(x, v2[j], m);
            }
            c2.pb(x);
        }
        sort(all(c1));
        sort(all(c2));

        n1 = szof(c1), n2 = szof(c2);
        int res = 0;
        for (auto x : c1) {
            int y = m - x;
            int l = 0, r = n2 - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (c2[mid] < y) {
                    umax(res, x + c2[mid]);
                    l = mid + 1;
                } else r = mid - 1;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
