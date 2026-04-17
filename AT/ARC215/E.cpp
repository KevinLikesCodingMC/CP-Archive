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
int n, m, c[N], vis[N];
string A, B;
VC<PII> e[N];
VI L, R;
void dfs1(int u) {
	for(auto [v, i] : e[u]) if(A[v] == '0') 
		A[v] = '1', L.pb(i), dfs1(v);
}
void dfs2(int u) {
	for(auto [v, i] : e[u]) if(B[v] == '0') 
		B[v] = '1', R.pb(i), dfs2(v);
}
void dfs3(int u) {
	vis[u] = 1;
	for(auto [v, i] : e[u]) if(! vis[v] && A[v] == '1' && B[v] == '0')
		dfs3(v), A[v] = '0', L.pb(i);
	vis[u] = 0;
}
void solve() {
	read(n, A, B, m);
	A = ' ' + A; B = ' ' + B;
	FOR(i, 1, n) e[i].clear();
	FOR(i, 1, n) c[i] = 0;
	FOR(i, 1, m) {
		INT(u, v);
		if(u == v) c[u] = i;
		else e[u].eb(v, i);
	}
	L.clear(); R.clear();
	FOR(i, 1, n) if(A[i] == '1') dfs1(i);
	FOR(i, 1, n) if(B[i] == '1') dfs2(i);
	FOR(i, 1, n) if(A[i] == '1' && B[i] == '0' && c[i]) dfs3(i);
	FOR(i, 1, n) if(A[i] == '1' && B[i] == '0' && c[i])
		A[i] = '0', L.pb(c[i]);
	bool ok = 1;
	FOR(i, 1, n) ok &= A[i] == B[i];
	if(! ok) { print(- 1); return; }
	reverse(begin(R), end(R));
	for(int x : R) L.pb(x);
	print(SZ(L));
	for(int x : L) cout << x << ' ';
	cout << endl;
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}