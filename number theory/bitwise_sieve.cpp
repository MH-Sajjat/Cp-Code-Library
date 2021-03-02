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

const int N       = (int) 1e7 + 5;
const int mxN     = (int) 1e6 + 6;
const ll MOD      = (ll) 1e9 + 7;

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

bool isOn(int n, int at) { return (bool) (n & (1 << at)); }
int bitOn(int n, int at) { return n = n | (1 << at); }

int vis[(N >> 5) + 2];
vi v;

// complexity O(nloglogn)
void bitwiseSieve() {
    vis[1 >> 5] = bitOn(vis[1 >> 5], 1 & 31);
    for (int i = 4; i <= N; i += 2) {
        vis[i >> 5] = bitOn(vis[i >> 5], i & 31);
    }
    for (int i = 3; i * i <= N; i += 2) {
        if (!isOn(vis[i >> 5], i & 31)) {
            for (int j = i * i; j <= N; j += (2 * i)) {
                vis[j >> 5] = bitOn(vis[j >> 5], j & 31);
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (!isOn(vis[i >> 5], i & 31)) {
            v.pb(i);
        }
    }
}

int main() {
    //Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    while (test--) {
        bitwiseSieve();
        for (auto x : v) cout << x  << " ";
        cout << nl;
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
