/*-----------------------------------
  bismillahir rahmanir rahim
  @author : md. sajjat hossen
  created : 07-October,2021 16:17:03
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

int nums[N];

class MST {
private:
    vector<vector<int>> tree;
    int n;

    void merge(vi& a, vi& b, vi& c) {
        int k = (int) b.size(), l = (int) c.size();
        int i = 0, j = 0;
        while (i < k or j < l) {
            if (i < k and j < l) {
                if (b[i] <= c[j]) {
                    a.push_back(b[i]);
                    i++;
                } else {
                    a.push_back(c[j]);
                    j++;
                }
            } else if (i < k) {
                a.push_back(b[i]);
                i++;
            } else {
                a.push_back(c[j]);
                j++;
            }
        }
    }

    void build(int at, int b, int e) {
        if (b == e) {
            tree[at].push_back(nums[b]);
            return;
        }
        int mid = (b + e) >> 1;
        build(2 * at, b, mid);
        build(2 * at + 1, mid + 1, e);
        merge(tree[at], tree[2 * at], tree[2 * at + 1]);
    }

    int query(int at, int b, int e, int l, int r, int k) {
        if (r < b or e < l) return 0;
        if (l <= b and e <= r) {
            int cnt = lower_bound(tree[at].begin(), tree[at].end(), k) - tree[at].begin();
            return cnt;
        }
        int mid = (b + e) >> 1;
        int x = query(2 * at, b, mid, l, r, k);
        int y = query(2 * at + 1, mid + 1, e, l, r, k);
        return x + y;
    }

public:
    MST(int n) {
        this->n = n;
        tree.resize(4 * n, vector<int>());
        build(1, 1, n);
    }

    int query(int l, int r, int k) {
        return query(1, 1, n, l, r, k);
    }

};

// find number of element less then k in a given range l to r.

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // Fast_IO
    int test = 1, tc = 0;
    while (test--) {
        int n = Int();
        for (int i = 1; i <= n; ++i) nums[i] = Int();

        MST ds(n);

        int q = Int();
        while (q--) {
            int l = Int(), r = Int(), k = Int();
            printf("%d\n", ds.query(l, r, k));
        }
    }
    return 0;
}
