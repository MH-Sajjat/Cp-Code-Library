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
#define    Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr);

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

// problem link : https://codeforces.com/problemset/problem/676/C

int main() {
    Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    //cin >> test;
    while (test--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int cnt1 = 0, cnt2 = 0, ans = 0, cnt = 0;
        int l = 0, r = 0;
        while (r < n) {
        	if (s[r] == 'a' && cnt < k) {
        		cnt++;
        		ans = max(ans, (r - l + 1));
        		r++;
        	} else if (s[r] == 'a' && cnt == k) {
        		if (s[l] == 'a') cnt--;
        		l++;
        	} else if (s[r] == 'b') {
        		ans = max(ans, (r - l + 1));
        		r++;
        	}
        }
        cnt = 0, l = 0, r = 0;
        while (r < n) {
        	if (s[r] == 'b' && cnt < k) {
        		cnt++;
        		ans = max(ans, (r - l + 1));
        		r++;
        	} else if (s[r] == 'b' && cnt == k) {
        		if (s[l] == 'b') cnt--;
        		l++;
        	} else if (s[r] == 'a') {
        		ans = max(ans, (r - l + 1));
        		r++;
        	}
        }
        cout << ans << nl;
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
