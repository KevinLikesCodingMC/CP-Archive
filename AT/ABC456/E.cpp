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
const int N = 1e5 + 5;
const int M = 1e6 + 5;
int n, m, w, ru[M]; 
string s[N];
VI e[M];
int gp(int u, int x) {
	return x * n + u;
}
void solve() {
	read(n, m);
	VC<PII> E(m);
	REP(i, m) read(FI(E[i]), SE(E[i]));
	read(w);
	FOR(i, 1, n) read(s[i]);
	FOR(u, 1, n * w) e[u].clear();
	FOR(u, 1, n * w) ru[u] = 0;
	FOR(u, 1, n) REP(l, w) {
		int r = (l + 1) % w;
		if(s[u][l] == 'o' && s[u][r] == 'o') {
			e[gp(u, l)].pb(gp(u, r));
			ru[gp(u, r)] ++;
		}
	}
	REP(i, m) {
		int u, v; tie(u, v) = E[i];
		REP(l, w) {
			int r = (l + 1) % w;
			if(s[u][l] == 'o' && s[v][r] == 'o') {
				e[gp(u, l)].pb(gp(v, r));
				ru[gp(v, r)] ++;
			}
			if(s[v][l] == 'o' && s[u][r] == 'o') {
				e[gp(v, l)].pb(gp(u, r));
				ru[gp(u, r)] ++;
			}
		}
	}
	queue<int> q;
	FOR(u, 1, n * w) if(! ru[u]) q.push(u);
	while(! q.empty()) {
		int u = q.front(); q.pop();
		for(int v : e[u]) {
			ru[v] --;
			if(! ru[v]) q.push(v);
		}
	}
	bool ok = 0;
	FOR(u, 1, n * w) ok |= ru[u] > 0;
	print(ok ? "Yes" : "No");
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}