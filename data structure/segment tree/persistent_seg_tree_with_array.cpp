/*-----------------------------------
  bismillahir rahmanir rahim
  @author : md. sajjat hossen
  created : 06-October,2021 19:12:28
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

// problem link : https://vjudge.net/contest/460861#problem/A

class MST {
public:
    struct data {
        int left, right, sum;
        data() : sum(0), left(0), right(0) {}
    };
    vector<data> tree;
    int cnt = 0;

    MST() {
        tree.resize(20 * N);
    }

    int build(int b, int e) {
        int cur = ++cnt;
        if (b == e) return cur;
        int mid = (b + e) >> 1;
        tree[cur].left = build(b, mid);
        tree[cur].right = build(mid + 1, e);
        tree[cur].sum = tree[tree[cur].left].sum + tree[tree[cur].right].sum;
        return cur;
    }

    int update(int pre, int b, int e, int idx, int val) {
        if (idx < b or idx > e) return pre;
        int cur = ++cnt;
        tree[cur] = tree[pre];
        if (b == e) {
            tree[cur].sum += val;
            return cur;
        }
        int mid = (b + e) >> 1;
        tree[cur].left = update(tree[pre].left, b, mid, idx, val);
        tree[cur].right = update(tree[pre].right, mid + 1, e, idx, val);
        tree[cur].sum = tree[tree[cur].left].sum + tree[tree[cur].right].sum;
        return cur;
    }

    int kth(int pre, int cur, int b, int e, int k) {
        if (b == e) return b;
        int sum = tree[tree[cur].left].sum - tree[tree[pre].left].sum;
        int mid = (b + e) >> 1;
        if (sum >= k) {
            return kth(tree[pre].left, tree[cur].left, b, mid, k);
        } else {
            return kth(tree[pre].right, tree[cur].right, mid + 1, e, k - sum);
        }

    }
};

map<int, int> ID, original;

int getID(int x) { return ID[x]; }
int getOriginal(int x) { return original[x]; }

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // Fast_IO
    int test = 1, tc = 0;
    while (test--) {
        int n = Int(), q = Int();
        int nums[n + 2];
        set<int> s;
        for (int i = 1; i <= n; ++i) {
            int x = Int();
            nums[i] = x;
            s.insert(x);
        }
        int p = 0;
        for (auto x : s) {
            ID[x] = ++p;
            original[p] = x;
        }

        int root[n + 1];
        MST ds;
        root[0] = ds.build(1, n);
        for (int i = 1; i <= n; ++i) {
            root[i] = ds.update(root[i - 1], 1, n, getID(nums[i]), 1);
        }

        while (q--) {
            int l = Int(), r = Int(), k = Int();
            printf("%d\n", getOriginal(ds.kth(root[l - 1], root[r], 1, n, k)));
        }
    }
    return 0;
}
