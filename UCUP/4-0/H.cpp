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
int n, k, w[N];
VI e[N];
int f[N]; ll s[N]; bool fail;
void dfs(int u, int fa) {
	f[u] = w[u] == - 1 ? k : w[u];
	ll sum; sum = s[u] = f[u];
	ll res = w[u] == - 1 ? 0 : w[u];
	for(int v : e[u]) {
		if(v == fa) continue;
		dfs(v, u);
		s[u] += s[v];
		sum += f[v];
		if(w[v] != - 1) res += w[v];
	}
	if(res > k) fail = 1;
	if(sum > k) {
		if(w[u] == - 1) {
			ll x = min<ll>(f[u], sum - k);
			f[u] -= x, s[u] -= x, sum -= x;
		}
		if(sum > k) s[u] -= sum - k;
	}
}
void solve() {
	read(n, k);
	FOR(i, 1, n) read(w[i]);
	REP(_, n - 1) {
		INT(u, v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1, 0);
	print(fail ? - 1 : s[1]);
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}