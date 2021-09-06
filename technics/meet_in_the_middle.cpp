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

// problem link : https://lightoj.com/problem/coin-change-iv

int n, coin[20];

void fun(vll& v, int pos, int limit, ll sum) {
	if (pos > limit) {
		v.pb(sum);
		return;
	}
	for (int i = 0; i < 3; ++i) {
		fun(v, pos + 1, limit, sum + coin[pos] * i);
	}
}


int main() {
    //Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = Int(), tc = 0;
    while (test--) {
        n = Int();
        ll k = Long();
        for (int i = 1; i <= n; ++i) {
        	coin[i] = Int();
        }
        int mid = n / 2;
        vll v1, v2;
        fun(v1, 1, mid, 0);
        fun(v2, mid + 1, n, 0);
        sort(all(v1));
        sort(all(v2));
        bool ok = 0;
        for (int i = 0; i < szof(v2) && v2[i] <= k; ++i) {
        	ll x = k - v2[i];
        	if (binary_search(all(v1), x)) {
        		ok = 1;
        		break;
        	}

        }
        if (ok) printf("Case %d: Yes\n", ++tc);
        else printf("Case %d: No\n", ++tc);
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
