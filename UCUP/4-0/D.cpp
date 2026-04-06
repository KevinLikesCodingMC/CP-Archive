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
template < typename T >
T floor(T x, T y) { return x / y - (x % y && (x ^ y) < 0); }
template < typename T >
T ceil(T x, T y) { return floor(x + y - 1, y); }
const int N = 1e5 + 5;
int n, m, w, h;
int L[N], R[N];
PII a[N], b[N];
void solve() {
	read(n, m, w, h);
	FOR(i, 0, w) L[i] = - h, R[i] = h;
	FOR(i, 1, n) read(FI(a[i]), SE(a[i]));
	FOR(i, 1, m) read(FI(b[i]), SE(b[i]));
	FOR(i, 1, n) { auto [x, y] = a[i]; chmin(R[x], y); }
	FOR(i, 1, m) { auto [x, y] = b[i]; chmax(L[x], y); }
	FOR(i, 1, n - 1) {
		auto [xl, yl] = a[i];
		auto [xr, yr] = a[i + 1];
		if(xl == xr) continue;
		ll x = xr - xl, y = yr - yl;
		FOR(j, xl, xr) chmin(R[j], yl + ceil((j - xl) * y, x));	
	}
	FOR(i, 1, m - 1) {
		auto [xl, yl] = b[i];
		auto [xr, yr] = b[i + 1];
		if(xl == xr) continue;
		ll x = xr - xl, y = yr - yl;
		FOR(j, xl, xr) chmax(L[j], yl + floor((j - xl) * y, x));
	}
	int l = 0, r = 0;
	FOR(i, 1, w) {
		l --; r ++;
		while(L[i] >= l) l += 2;
		while(R[i] <= r) r -= 2;
		if(l > r) { print("impossible"); return; }
	}
	print(l, r);
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}