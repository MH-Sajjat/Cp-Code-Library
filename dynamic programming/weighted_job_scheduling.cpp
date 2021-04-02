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
const int MOD     = (ll) 1e9 + 7;

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

// Given N jobs with start time, end time and profit.
// Find maximum profit and two jobs does not overlap.

// complexity O(nlogn)

int n, dp[N];
vector<pair<int, pii>> ar;

// O(logn)
int upperBound(int val, int l) {
	int ans = n, r = n - 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (ar[mid].ff >= val) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	return ans;
}

// O(n)
ll fun(int i) {
	if (i == n) return 0;
	if (dp[i] != -1) return dp[i];
	int u = fun(i + 1);
	int next = upperBound(ar[i].ss.ff, i + 1);
	int v = ar[i].ss.ss + fun(next);
	return dp[i] = max(u, v);
}

int main() {
    // Fast_IO
    // clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    while (test--) {
    	memset(dp, -1, sizeof dp);
        ar.clear();
        n = Int();
        for (int i = 0; i < n; ++i) {
        	int x = Int(), y = Int(), w = Int();
        	ar.pb({x, {y, w}});
        }
        sort(all(ar));
        printf("%d\n", fun(0));
    }
    // fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
