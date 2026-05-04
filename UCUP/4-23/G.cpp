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
const int N = 1e6 + 5;
int n, a[N], b[N];
int pre[N], nxt[N], s[N];
bool f[N][5];
int ans[N];
bool check(int l, int r, int x) {
	if(l < 1) return 0;
	int R = pre[r], L = nxt[l];
	if(R < l) return 1;
	if(a[R] != x || a[L] != x) return 0;
	return s[R] - s[L] == 0;
}
void solve() {
	read(n);
	FOR(i, 1, n) read(a[i]);
	FOR(i, 1, n) pre[i] = a[i] ? i : pre[i - 1];
	nxt[n + 1] = n + 1;
	ROF(i, n, 1) nxt[i] = a[i] ? i : nxt[i + 1];
	FOR(i, 1, n) s[i] = 0;
	FOR(i, 1, n) if(a[i] && pre[i - 1]) s[i] = a[pre[i - 1]] != a[i];
	FOR(i, 1, n) s[i] += s[i - 1];
	FOR(i, 1, n) b[i] = a[pre[i]];
	FOR(i, 0, n) REP(o, 5) f[i][o] = 0;
	FOR(o, 1, 2) f[0][o] = 1;
	FOR(i, 1, n) {
		FOR(o, 1, 4) {
			int l = i - o;
			if(! check(l + 1, i, o)) continue;
			FOR(e, 1, 4) if(o != e) f[i][o] |= f[l][e];
			if(b[l] != o) f[i][o] |= f[l][0];
		}
		if(pre[i]) {
			int o = b[i], l = i - o;
			if(! check(l + 1, i, o)) continue;
			FOR(e, 1, 4) if(o != e) f[i][0] |= f[l][e];
			if(b[l] != o) f[i][0] |= f[l][0];
		}
	}
	int r = n, o = - 1;
	REP(i, 5) if(f[n][i]) o = i;
	if(o == - 1) { print("No"); return; }
	print("Yes");
	while(r) {
		int len = o ? o : b[r];
		REP(_, len) ans[r --] = len;
		o = 0;
		FOR(i, 1, 4) if(f[r][i] && i != len) o = i;
	}
	FOR(i, 1, n) cout << ans[i] << ' ';
	cout << endl;
}
int main() {
	// freopen("G.in", "r", stdin);
	// freopen("G.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}