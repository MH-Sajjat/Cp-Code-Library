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
const int Mod     = (int) 1e9 + 7;

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

int ar[N];

// complexity O(sqrt(n))
template<TN T> class sqrd{
private:
    vector<T> segment;
    int n, seg_size;

    // complexity O(n)
    void build() {
        seg_size = sqrt(n);
        int cur_seg = -1;
        for (int i = 0; i < n; ++i) {
            if (i % seg_size == 0) cur_seg++;
            segment[cur_seg] += ar[i];
        }
    }

public:
    sqrd(int _n) {
        n = _n;
        segment.resize(n + 5, 0);
        build();
    }

    // complexity O(sqrt(n))
    T query(int l, int r) {
        T sum = 0;
        while (l < r && l % seg_size != 0) {
            sum += ar[l];
            l++;
        }
        while(l + seg_size <= r) {
            sum += segment[l / seg_size];
            l += seg_size;
        }
        while (l <= r) {
            sum += ar[l];
            l++;
        }
        return sum;
    }

    // complexity O(1)
    void update(int idx, int val) {
        segment[idx / seg_size] -= ar[idx];
        segment[idx / seg_size] += val;
        ar[idx] = val;
    }
};

int main() {
    //Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = Int(), tc = 0;
    while (test--) {
        int n = Int(), q = Int();
        for (int i = 0; i < n; ++i) ar[i] = Int();
        sqrd<ll> ds(n);
        while (q--) {
            int ck = Int();
            if (ck == 1) {
                int idx = Int(), val = Int();
                ds.update(idx, val);
            } else {
                int l = Int(), r = Int();
                ll ans = ds.query(l, r);
                printf("%lld\n", ans);
            }
        }
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
