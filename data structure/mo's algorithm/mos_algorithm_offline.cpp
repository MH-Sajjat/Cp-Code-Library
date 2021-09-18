/*---------------------------------
bismillahir rahmanir rahim
@author : md. sajjat hossen
created : 16-September,2021 21:20:19
----------------------------------*/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair <int, int>    pii;
typedef pair <ll, ll>      pll;
typedef vector <int>       vi;
typedef vector <ll>        vll;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;
 
inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }
 
int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
 
const int N      = (int) 5e5 + 5;
const int mxN    = (int) 1e6 + 6;
const int MOD    = (int) 1e9 + 7;
const int INF    = (int) 1e9 + 9;
const double EPS = (double) 1e-9;
 
#define debug(x) cerr << #x << " = " << x << '\n';
#define all(x)   x.begin(), x.end()
#define szof(x)  (int) x.size()
#define ff       first
#define ss       second
#define pb       push_back
#define mp       make_pair
#define PI       acos(-1.0)
#define TN       typename
#define nl       '\n'
#define Fast_IO  ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }
 
template <TN T> inline void umin(T &x, T y) { x = x < y ? x : y; }
template <TN T> inline void umax(T &x, T y) { x = x > y ? x : y; }
 
template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

// problem link : https://cses.fi/problemset/task/1734/
 
const int blockSize = 440;
int disNum = 0;
vi cnt(N, 0);
vi ar(N, 0);
 
struct data1 {
    int l, r, idx;
};
 
void add(int idx) {
    cnt[ar[idx]]++;
    if (cnt[ar[idx]] == 1) disNum++;
}
 
void remove(int idx) {
    cnt[ar[idx]]--;
    if (cnt[ar[idx]] == 0) disNum--;
}
 
vi fun(vector<data1>& query) {
    int m = szof(query);
    vi res(m + 2, 0);
    sort(all(query), [] (data1 a, data1 b) -> bool {
        if ((a.l / blockSize) == (b.l / blockSize)) {
            return ((a.l / blockSize) & 1) ? a.r > b.r : a.r < b.r;
        }
        return (a.l / blockSize) < (b.l / blockSize);
    });
 
    int curL = 1, curR = 0;
    for (auto x : query) {
        while (curL > x.l) add(--curL);
        while (curL < x.l) remove(curL++);
        while (curR > x.r) remove(curR--);
        while (curR < x.r) add(++curR);
        res[x.idx] = disNum;
    }
    return res;
}
 
void clr() {
    cnt.assign(N, 0);
    ar.assign(N, 0);
    disNum = 0;
}
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // Fast_IO
    int test = 1, tc = 0;
    while (test--) {
        int n = Int(), m = Int();
        vi v;
        int k = 0;
        map<int, int> MAP;
        for (int i = 1; i <= n; ++i) {
            ar[i] = Int();
            if (!MAP.count(ar[i])) {
                MAP[ar[i]] = ++k;
            }
        }
        for (int i = 1; i <= n; ++i) {
            ar[i] = MAP[ar[i]];
        }
 
        vector<data1> query;
        for (int i = 1; i <= m; ++i) {
            data1 Q;
            Q.l = Int();
            Q.r = Int();
            Q.idx = i;
            query.pb(Q);
        }
 
        vi res = fun(query);
        for (int i = 1; i <= m; ++i) {
            printf("%d\n", res[i]);
        }
 
        clr();
    }
    return 0;
}
