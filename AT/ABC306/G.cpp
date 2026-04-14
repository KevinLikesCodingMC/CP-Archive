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
int n, m;
VI e[N], g[N];
int v1[N], v2[N], d[N];
int gcd(int x, int y) {
	if(! y) return x;
	return gcd(y, x % y);
}
void dfs1(int u) {
	for(int v : e[u]) if(! v1[v]) {
		v1[v] = 1;
		d[v] = d[u] + 1;
		dfs1(v);
	}
}
void dfs2(int u) {
	for(int v : g[u]) if(! v2[v]) {
		v2[v] = 1;
		dfs2(v);
	}
}
void solve() {
	read(n, m);
	FOR(i, 1, n) e[i].clear();
	FOR(i, 1, n) g[i].clear();
	REP(_, m) {
		INT(u, v);
		e[u].pb(v);
		g[v].pb(u);
	}
	FOR(i, 1, n) v1[i] = v2[i] = 0;
	for(int u : e[1]) d[u] = v1[u] = 1, dfs1(u);
	for(int u : g[1]) v2[u] = 1, dfs2(u);
	if(! v1[1]) { print("No"); return; }
	int ans = d[1];
	FOR(u, 1, n) for(int v : e[u]) if(v1[u] && v1[v] && v2[u] && v2[v])
		ans = gcd(ans, d[u] + 1 - d[v]);
	ans = abs(ans);
	while(ans % 2 == 0) ans /= 2;
	while(ans % 5 == 0) ans /= 5;
	print(ans == 1 ? "Yes" : "No");
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}