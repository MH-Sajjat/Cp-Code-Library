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
const double EPS  = (double) 1e-9;

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

inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

struct node {
    node* edge[26];
    int cntEnd = 0;
    node() {
        cntEnd = 0;
        for (int i = 0; i < 26; ++i)
            edge[i] = NULL;
    } 
} *root;

void add(string& s) {
    node* cur = root;
    for (int i = 0; i < szof(s); ++i) {
        int id = s[i] - 'a';
        if (cur->edge[id] == NULL) {
            cur->edge[id] = new node();
        }
        cur = cur->edge[id];
    }
    cur->cntEnd++;
}

int search(string& s) {
    node* cur = root;
    for (int i = 0; i < szof(s); ++i) {
        int id = s[i] - 'a';
        if (cur->edge[id] == NULL) return 0;
        cur = cur->edge[id];
    }
    return cur->cntEnd;
}

void del(node* cur) {
    for (int i = 0; i < 26; ++i) {
        if (cur->edge[i] != NULL) del(cur->edge[i]);
    }
    delete(cur);
}

int main() {
    Fast_IO
    // clock_t tStart = clock();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        string s;
        root = new node();
        for (int i = 1; i <= n; ++i) {
            cin >> s;
            add(s);
        }
        int q;
        cin >> q;
        while (q--) {
            cin >> s;
            cout << search(s) << nl;
        }
        del(root);
    }
    // fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
