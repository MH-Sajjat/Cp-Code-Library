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

// complexity O(m alpha(n)) where alpha(n) <= 4. final O(m)
template <TN T> class dsu{
private:
    struct data{
        T par, rank, setsize;
        data() {par = rank = setsize = 0; }
    };
    vector<data> g;
    int n;
    
public:
    int setnum;
    dsu(int _n) {
        n = _n;
        setnum = n;
        g.resize(n + 5);
        for (int i = 1; i <= n; ++i) {
            g[i].par = i;
            g[i].rank = 0;
            g[i].setsize = 1;
        }
    }

    T root(int x) {
        return g[x].par = g[x].par == x ? x : root(g[x].par);
    }

    void merge(int a, int b) {
        int x = root(a);
        int y = root(b);
        if (x == y) return;
        if (g[x].rank <= g[y].rank) swap(x, y);
        g[y].par = x;
        g[x].setsize += g[y].setsize;
        if (g[x].rank == g[y].rank)
            g[y].rank++;
        setnum--;
    }
};

int main() {
    //Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    while (test--) {
        int n = Int(), m = Int();
        dsu<int> ds(n);
        while (m--) {
            int a = Int(), b = Int();
            ds.merge(a, b);
        }
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
