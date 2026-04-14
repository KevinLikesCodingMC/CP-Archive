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
const int N = 5e5 + 5;
const int M = 5e7 + 5;
int n, m, a[N], f[M], b[M];
int find(int u) {
	if(f[u] == u) return u;
	return f[u] = find(f[u]);
}
void merge(int u, int v) {
	u = find(u), v = find(v);
	if(u == v) return;
	f[v] = u;
}
void solve() {
	read(n, m);
	FOR(i, 1, n) read(a[i]);
	FOR(i, 0, m) f[i] = i;
	int l = 0, r = m;
	FOR(i, 1, n) {
		if(a[i] > r - l) continue;
		if(a[i] * 2 >= r - l + 1) {
			FOR(u, l + a[i], r) merge(u, u - a[i]);
			r = l + a[i] - 1;
		}
		else {
			FOR(u, l, l + a[i] - 1) merge(u, u + a[i]);
			l += a[i];
		}
	}
	FOR(i, l, r) b[find(i)] = i - l;
	ull ans = 0;
	FOR(i, 1, m) ans ^= 1ll * i * (i - b[find(i)]);
	print(ans);
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}