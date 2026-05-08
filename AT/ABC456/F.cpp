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
const ll LNF = 1e18;
int n, k;
ll a[N], s[N], ans;
ll f[N][2][2];
void slv(int l, int r) {
	if(r - l + 1 < k) return;
	int mid = l + r >> 1;
	slv(l, mid); slv(mid + 1, r);
	chmax(l, mid - k);
	chmin(r, mid + k);
	f[mid][0][0] = 0; f[mid][1][1] = a[mid];
	f[mid][0][1] = f[mid][1][0] = - LNF;
	ROF(i, mid - 1, l) REP(o, 2) {
		f[i][o][0] = max(f[i + 1][o][0], f[i + 1][o][1]);
		f[i][o][1] = f[i + 1][o][0] + a[i];
	}
	f[mid + 1][0][0] = 0; f[mid + 1][1][1] = a[mid + 1];
	f[mid + 1][0][1] = f[mid + 1][1][0] = - LNF;
	FOR(i, mid + 2, r) REP(o, 2) {
		f[i][o][0] = max(f[i - 1][o][0], f[i - 1][o][1]);
		f[i][o][1] = f[i - 1][o][0] + a[i];
	}
	FOR(i, 1, k - 1) {
		int pl = mid - i + 1, pr = mid + k - i;
		if(pl < l || pr > r) continue;
		REP(o, 2) REP(e, 2) if(! (o && e)) {
			ll L = max(f[pl][o][0], f[pl][o][1]);
			ll R = max(f[pr][e][0], f[pr][e][1]);
			chmin(ans, s[pr] - s[pl - 1] - L - R);
		}
	}
}
void solve() {
	read(n, k); n += 2; k += 2;
	a[1] = a[n] = LNF;
	FOR(i, 2, n - 1) read(a[i]);
	FOR(i, 1, n) s[i] = s[i - 1] + a[i];
	ans = LNF;
	slv(1, n);
	print(ans);
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}