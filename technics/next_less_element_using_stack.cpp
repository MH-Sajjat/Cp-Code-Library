/*----------------------------
  bismillahir rahmanir rahim
----------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair <int, int>    pii;
typedef pair <ll, ll>      pll;
typedef vector <int>       vi;
typedef vector <ll>        vll;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N      = (int) 2e5 + 5;
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

inline int add(int a, int b, int mod) {
    a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a;
}
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }

template <TN T> inline void umin(T &x, T y) { x = x < y ? x : y; }
template <TN T> inline void umax(T &x, T y) { x = x > y ? x : y; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

// ---------------------------- let's try again ---------------------------- //

// problem link: https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1

vector<int> help_classmate(vector<int> arr, int n)  {
    vector<int> res(n, -1);
    stack<pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
        int next = arr[i];
        if (st.empty()) {
            st.push({next, i});
            continue;
        }

        while (!st.empty() and st.top().first > next) {
            res[st.top().second] = next;
            st.pop();
        }
        st.push({next, i});
    }
    return res;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // Fast_IO
    int test = 1, tc = 0;
    while (test--) {
        int n = Int();
        vi v(n, 0);
        for (int& x : v) x = Int();
        vi res = help_classmate(v, n);
        for (int i = 0; i < n; ++i) {
            cout << res[i] << " \n"[i == (n - 1)];
        }
    }
    return 0;
}
