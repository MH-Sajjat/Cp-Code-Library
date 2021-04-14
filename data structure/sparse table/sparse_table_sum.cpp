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
#define    PI          acos(-1.0)
#define    TN          typename
#define    nl          '\n'
#define    Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr);

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

int ar[N];

// Complexity O(mlogn)
template<TN T> class spaseTable{
private:
    vector<vector<T>> SPT;

public:
    // Complexity O(nlogn)
    void build(int n) {
        for (int i = 1; i <= n; ++i)
            SPT[i][0] = ar[i];
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                SPT[i][j] = SPT[i][j - 1] + SPT[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    // Complexity O(logn)
    T query(int l, int r) {
        T sum = 0;
        for (int k = 23; k >= 0; --k) {
            if ((1 << k) <= (r - l + 1)) {
                sum += SPT[l][k];
                l += (1 << k);
            }
        }
        return sum;
    }

    spaseTable(int n) {
        SPT.resize(N, vector<T>(24, 0));
        build(n);
    }
};

int main() {
    // Fast_IO
    // clock_t tStart = clock();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    while (test--) {
        int n = Int(), m = Int();
        for (int i = 1; i <= n; ++i) ar[i] = Int();
        spaseTable<int> ds(n);
        while (m--) {
            int l = Int(), r = Int();
            printf("%d\n", ds.query(l, r));
        }
    }
    // fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
