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
const int P = 998244353;
const ll LNF = 1e18;
inline int add(int x, int y) { return x + y < P ? x + y : x + y - P; }
inline void Add(int & x, int y) { x = x + y < P ? x + y : x + y - P; }
inline int mul(int x, int y) { return (1ll * x * y) % P; }
inline void Mul(int & x, int y) { x = (1ll * x * y) % P; }
int n, m; ll ans;
map<int, ll> mp[N];
void add_edge(int u, int v, ll x) {
	if(mp[u].count(v)) {
		ll y = mp[u][v];
		chmax(ans, x + y);
		mp[u][v] = mp[v][u] = max(x, y);
	}
	else {
		mp[u][v] = mp[v][u] = x;
	}
}
void solve() {
	read(n, m);
	ans = - LNF;
	REP(_, m) {
		INT(u, v, w);
		add_edge(u, v, w);
	}
	queue<int> q;
	FOR(i, 1, n) if(SZ(mp[i]) <= 2) q.push(i);
	while(! q.empty()) {
		int u = q.front(); q.pop();
		if(SZ(mp[u]) == 2) {
			int l, r; ll L, R;
			tie(l, L) = * mp[u].begin();
			tie(r, R) = * prev(mp[u].end());
			add_edge(l, r, L + R);
		}
		for(auto h : mp[u]) {
			int v = FI(h);
			mp[v].erase(u);
			if(SZ(mp[v]) <= 2) q.push(v);
		}
		mp[u].clear();
	}
	print(ans);
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}