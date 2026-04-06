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
const int N = 4e5 + 5;
int n; ll K;
VI e[N];
int d[N], p[N];
void dfs(int u, int fa) {
	for(int v : e[u]) {
		if(v == fa) continue;
		d[v] = d[u] + 1;
		p[v] = u;
		dfs(v, u);
	}
}
void solve() {
	read(n, K); n <<= 1;
	FOR(i, 1, n) e[i].clear();
	REP(_, n - 1) {
		INT(u, v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1, 0);
	ll sum = K;
	FOR(u, 1, n) sum ^= d[u];
	if(sum & 1) {
		print(2, p[2]);
		print(2, p[2]);
	}
	else {
		FOR(u, 2, n) if(SZ(e[u]) == 1 && d[u] >= 2) {
			print(p[u], u);
			print(p[p[u]], u);
			return;
		}
		print(1, 3);
		print(2, 3);
	}
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}