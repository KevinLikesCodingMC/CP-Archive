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
template < typename A >
struct MaxFlow {
	struct Edge { int ne, to; A ew; };
	int n, S, T; 
	VI fi; VC<Edge> e;
	VI d, c;
	MaxFlow(int n) : n(n) {
		fi = VI(n + 1);
		e.resize(2);
	}
	void add(int u, int v, A w) {
		e.pb({fi[u], v, w});
		fi[u] = SZ(e) - 1;
		e.pb({fi[v], u, 0});
		fi[v] = SZ(e) - 1;
	}
	bool bfs() {
		const int INF = 1e9 + 7;
		d = VI(n + 1, INF);
		queue<int> q;
		d[S] = 0; q.push(S);
		while(! q.empty()) {
			int u = q.front(); q.pop();
			if(u == T) return 1;
			for(int i = fi[u]; i; i = e[i].ne) if(e[i].ew) {
				int v = e[i].to;
				if(d[v] == INF) {
					d[v] = d[u] + 1;
					q.push(v);
				}
			}
		}
		return 0;
	}
	A dfs(int u, A w) {
		if(u == T || ! w) return w;
		A res = 0;
		for(int & i = c[u]; i; i = e[i].ne) if(e[i].ew) {
			int v = e[i].to;
			if(d[v] != d[u] + 1) continue;
			A val = dfs(v, min(w, e[i].ew));
			if(! val) continue;
			res += val; w -= val;
			e[i].ew -= val;
			e[i ^ 1].ew += val;
			if(! w) return res;
		}
		return res;
	}
	A dinic(int _S, int _T) {
		S = _S, T = _T;
		A res = 0;
		A INF = numeric_limits<A> :: max();
		while(bfs()) {
			c = fi;
			res += dfs(S, INF);
		}
		return res;
	}
};
const int N = 305;
int n, m;
string s[N];
int dx[] = {0, 0, - 1, 1};
int dy[] = {- 1, 1, 0, 0};
int gp(int x, int y, int o) {
	return (x - 1) * m + y + o * n * m;
}
void solve() {
	read(n, m);
	FOR(i, 1, n) read(s[i]), s[i] = ' ' + s[i];
	int S = 0, T = n * m * 2 + 1;
	MaxFlow<int> flow(T);
	int cnt = 0;
	FOR(i, 1, n) FOR(j, 1, m) {
		if(s[i][j] == '?') {
			flow.add(gp(i, j, 1), T, 1);
		}
		if(s[i][j] == '2') {
			cnt ++;
			flow.add(S, gp(i, j, 0), 1);
			flow.add(gp(i, j, 1), T, 1);
			REP(d, 4) {
				int x = i + dx[d], y = j + dy[d];
				if(x < 1 || x > n || y < 1 || y > m) continue;
				flow.add(gp(i, j, 0), gp(x, y, 1), 1);
			}
		}
	}
	print(flow.dinic(S, T) == cnt ? "Yes" : "No");
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}