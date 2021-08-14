/*------------------------------------
   bismillahir rahmanir rahim
   author : md. sajjat hossen
   created : 14-August,2021 20:02:09
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

const int N       	= (int) 2e5 + 5;
const int mxN     	= (int) 1e6 + 6;
const int MOD     	= (int) 1e9 + 7;
const int INF     	= (int) 1e9 + 9;
const double EPS	= (double) 1e-9;

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

struct node {
	ll sum, lazy;
	node* left;
	node* right;
	node (): sum(0LL), lazy(0LL), left(nullptr), right(nullptr) {}
};

void propagate(node* cur, int b, int e) {
	if (cur->lazy) {
		cur->sum += (1LL * (e - b + 1) * cur->lazy);
		if (b != e) {
			if (cur->left == nullptr) cur->left = new node();
			if (cur->right == nullptr) cur->right = new node();
			cur->left->lazy += cur->lazy;
			cur->right->lazy += cur->lazy;
		}
		cur->lazy = 0LL;
	}
}

void update(node* cur, int b, int e, int l, int r, int val) {
	propagate(cur, b, e);
	if (b > r or l > e) return;
	if (l <= b and e <= r) {
		cur->sum += (1LL * (e - b + 1) * val);
		if (b != e) {
			if (cur->left == nullptr) cur->left = new node();
			if (cur->right == nullptr) cur->right = new node();
			cur->left->lazy += val;
			cur->right->lazy += val;
		}
		return;
	}
	int mid = (b + e) >> 1;
	if (cur->left == nullptr) cur->left = new node();
	if (cur->right == nullptr) cur->right = new node();
	update(cur->left, b, mid, l, r, val);
	update(cur->right, mid + 1, e, l, r, val);
	cur->sum = cur->left->sum + cur->right->sum;
}

ll query(node* cur, int b, int e, int l, int r) {
	propagate(cur, b, e);
	if (!cur->sum or b > r or l > e) return 0LL;
	if (l <= b and e <= r) return cur->sum;
	int mid = (b + e) >> 1;
	ll u = query(cur->left, b, mid, l, r);
	ll v = query(cur->right, mid + 1, e, l, r);
	return u + v;
}

ll get(int l, int r) {
    int h = r - l + 1;
    return 1LL * (l + r) * h / 2LL;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	// Fast_IO
	int test = 1, tc = 0;
	while (test--) {
		node* root = new node();
		int n = Int(), q = Int();
		while (q--) {
			int ck = Int();
			if (ck == 1) {
				int l = Int(), r = Int(), val = Int();
				update(root, 1, n, l, r, val);
			} else {
				int l = Int(), r = Int();
				printf("%lld\n", get(l, r) - query(root, 1, n, l, r));
			}
		}
	}
	return 0;
}
