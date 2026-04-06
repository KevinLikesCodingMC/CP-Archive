#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;
#define FOR(i, n, m) for(int i = (n); i <= (m); i ++)
#define ROF(i, n, m) for(int i = (n); i >= (m); i --)
#define REP(i, n) for(int i = 0; i < (n); i ++)
#define SZ(v) int(v.size())
#define PII pair<int, int>
#define FI(v) v.first
#define SE(v) v.second
#define endl '\n'
using VI = vector<int>;
template < class T >
using VC = vector<T>;
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define SHOW(x) #x, '=', x
template < typename A, typename B >
inline bool chmax(A & x, B y) { return (x < y ? (x = y, true) : false); }
template < typename A, typename B >
inline bool chmin(A & x, B y) { return (x > y ? (x = y, true) : false); }
template < class T >
void rd_s(T & x) { cin >> x; }
void read() {}
template < class H , class ... T >
void read(H & h, T & ... t) { rd_s(h); read(t ...); }
template < class T >
void pt_s(T x) { cout << x; }
void print() { pt_s(endl); }
template < class H , class ... T >
void print(H h, T ... t) { pt_s(h); if(sizeof ... (t)) pt_s(' '); print(t ...); }
#define INT(...) int __VA_ARGS__; read(__VA_ARGS__)
#define UINT(...) uint __VA_ARGS__; read(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; read(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__; read(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; read(__VA_ARGS__)
#define CHAR(...) char __VA_ARGS__; read(__VA_ARGS__)
const int N = 2e5 + 5;
const ll V = 1e17;
const int K = 63;
int n, k, h[N], a[N], H[N], A[N];
ll S[N], B[N], ans;
int st[19][N];
int s[K][N], p[K];
int get(int x, int y) {
	return H[x] > H[y] ? x : y;
}
void build() {
	FOR(i, 1, n) st[0][i] = i;
	FOR(j, 1, __lg(n)) FOR(i, 1, n - (1 << j) + 1)
		st[j][i] = get(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
	FOR(i, 1, n + 1) B[i] = S[i] + V;
	ROF(j, K - 1, 0) {
		FOR(i, 1, n + 1) s[j][i] = s[j][i - 1] + (B[i] >> j & 1);
		p[j] = stable_partition(B + 1, B + n + 2, [&] (ll x) { return ! (x >> j & 1); }) - B;
	}
}
int query(int l, int r) {
	int len = __lg(r - l + 1);
	return get(st[len][l], st[len][r - (1 << len) + 1]);
}
int rnk(int l, int r, ll x) {
	int res = 0; x += V;
	ROF(j, K - 1, 0) {
		if(x >> j & 1) {
			l = p[j] + s[j][l - 1];
			r = p[j] + s[j][r] - 1;
		}
		else {
			res += s[j][r] - s[j][l - 1];
			l -= s[j][l - 1];
			r -= s[j][r];
		}
	}
	return res;
}
void slv(int l, int r) {
	if(l > r) return;
	int u = query(l, r);
	slv(l, u - 1); slv(u + 1, r);
	if(u - l < r - u) FOR(i, l, u) ans += rnk(u + 1, r + 1, S[i] + (k + 1) * H[u] - 1);
	else FOR(i, u, r) ans += (u - l + 1) - rnk(l, u, S[i + 1] - (k + 1) * H[u]);
}
void solve() {
	read(n, k);
	FOR(i, 1, n) read(h[i]);
	FOR(i, 1, n) read(a[i]);
	FOR(i, 1, n) {
		if(h[i] > a[i]) H[i] = h[i] - a[i], S[i + 1] = S[i] + H[i];
		else S[i + 1] = S[i] - (a[i] - h[i]) * k;
	}
	build();
	slv(1, n);
	print(ans);
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}