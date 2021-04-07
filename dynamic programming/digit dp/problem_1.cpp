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

// Given A, B and X. Print how many integers between A and B have a digit sum equal to X.
// 1 <= A <= b <= 1e9 and 1<= x <= 1e5

string s;
int dp[12][2][100], x;

int fun(int pos, int isSmall, int digitSum) {
	if (pos == szof(s)) return digitSum == x;
	int& res = dp[pos][isSmall][digitSum];
	if (res != -1) return res;
	res = 0;
	int low = 0, hi = s[pos] - '0';
	if (isSmall) hi = 9;
	for (int i = low; i <= hi; ++i) {
		int newIsSamall = isSmall | (i < hi);
		res += fun(pos + 1, newIsSamall, digitSum + i);
	}
	return res;
}

int main() {
    // Fast_IO
    // clock_t tStart = clock();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    while (test--) {
        memset(dp, -1, sizeof dp);
        int a = Int(), b = Int();
        x = Int();
        s = to_string(a - 1);
        int low = fun(0, 0, 0);

        memset(dp, -1, sizeof dp);
        s = to_string(b);
        int hi = fun(0, 0, 0);
        printf("%d\n", hi - low);
    }
    // fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
