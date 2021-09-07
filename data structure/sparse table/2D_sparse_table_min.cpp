/*------------------------------------
   bismillahir rahmanir rahim
   author : md. sajjat hossen
   created : 07-September,2021 09:03:21
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

// complexity O(n * m * logn * logm)
template <typename T> class SparseTable2D {
private:
    vector <vector <vector <vector <T>>>> spt;
    int n, m, logN, logM;

    void build(vector <vector< T>>& v) {

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                spt[i][0][j][0] = v[i][j];
            }

            for (int l = 1; l <= logM; ++l) {
                for (int j = 1; j + (1 << l) - 1 <= m; ++j) {
                    spt[i][0][j][l] = min(spt[i][0][j][l - 1], spt[i][0][j + (1 << (l - 1))][l - 1]);
                }
            }
        }

        for (int k = 1; k <= logN; ++k) {
            for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
                for (int l = 1; l <= logM; ++l) {
                    for (int j = 1; j + (1 << l) - 1 <= m; ++j) {
                        spt[i][k][j][l] = min(spt[i][k - 1][j][l], spt[i + (1 << (k - 1))][k - 1][j][l]);
                    }
                }
            }
        }
    }

public:
    SparseTable2D(int _n, int _m, vector <vector <T>>& v) {
        n = _n, m = _m;
        logN = log2(n);
        logM = log2(m);
        spt.assign(n + 2, vector <vector <vector <T>>> (logN + 2, vector <vector <T>> (m + 2, vector <T> (logM + 2, 0))));
        build(v);
    }

    T query(int x1, int y1, int x2, int y2) {
        int logX = log2(x2 - x1 + 1);
        int logY = log2(y2 - y1 + 1);
        T mxR1 = min(spt[x1][logX][y1][logY], spt[x1][logX][y2 - (1 << logY) + 1][logY]);
        T mxR2 = min(spt[x2 - (1 << logX) + 1][logX][y1][logY], spt[x2 - (1 << logX) + 1][logX][y2 - (1 << logY) + 1][logY]);
        return min(mxR1, mxR2);
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // Fast_IO
    int test = 1, tc = 0;
    while (test--) {
        int n = Int(), m = Int();
        vector <vi> v(n + 1, vi(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                v[i][j] = Int();
            }
        }

        SparseTable2D<int> ds(n, m, v);
        printf("%d\n", ds.query(1, 1, 3, 3));
        
    }
    return 0;
}
