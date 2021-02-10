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
#define    pie         acos(-1.0)
#define    TN          typename
#define    nl          '\n'
#define    Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr);

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

int ar[N];

// complexity O(nlogn)
template<TN T> class SegTree{
private:
    struct data{
        T sum;
        data() { sum = 0; }
    };
    vector<data> g;
    int n;
    
    // complexity O(n)
    void build(int at, int l, int r) {
        if (l == r) {
            g[at].sum = ar[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * at, l, mid);
        build(2 * at + 1, mid + 1, r);
        g[at].sum = g[2 * at].sum + g[2 * at + 1].sum;
    }

    // complexity O(logn)
    void update(int at, int l, int r, int idx, int val) {
        if (idx < l || idx > r) return;
        if (l == r) {
            g[at].sum += val;
            return;
        }
        int mid = (l + r) >> 1;
        update(2 * at, l, mid, idx, val);
        update(2 * at + 1, mid + 1, r, idx, val);
        g[at].sum = g[2 * at].sum + g[2 * at + 1].sum;
    }

    // complexity O(logn)
    T query(int at, int l, int r, int L, int R) {
        if (R < l || r < L) return 0;
        if (L <= l && r <= R) return g[at].sum;
        int mid = (l + r) >> 1;
        int u = query(2 * at, l, mid, L, R);
        int v = query(2 * at + 1, mid + 1, r, L, R);
        return u + v;
    }

public:
    SegTree(int _n) {
        g.resize(4 * N);
        n = _n;
        build(1, 1, n);
    }
    
    void update(int idx, int val) { update(1, 1, n, idx, val); }
    T query(int l, int r) { return query(1, 1, n, l, r); }
};


int main() {
    //Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    while (test--) {
        int n = Int(), q = Int();
        for (int i = 1; i <= n; ++i) {
            ar[i] = Int();
        }
        SegTree<int> ds(n);
        while (q--) {
            int ck = Int();
            if (ck == 1) {
                int idx = Int(), val = Int();
                ds.update(idx, val);
            } else {
                int l = Int(), r = Int();
                int res = ds.query(l, r);
                printf("%d\n", res);
            }
        }
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
