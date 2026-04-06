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
const ll LNF = 1e18;
int n, m; ll a[N], k;
void shift() {
	int pos = 0;
	while(pos < m && ! a[pos + 1]) pos ++;
	if(! pos) return;
	m -= pos;
	FOR(i, 1, m) a[i] = a[i + pos];
}
void F() {
	sort(a + 1, a + m + 1); shift();
	FOR(i, 2, m) a[i] -= a[i - 1];
}
void pt() {
	REP(_, n - m) cout << 0 << ' ';
	FOR(i, 1, m) cout << a[i] << ' ';
	cout << endl;
}
void solve() {
	read(n, k);
	FOR(i, 1, n) read(a[i]);
	m = n;
	while(m >= 4) {
		F(); k --;
		if(m <= 1 || ! k) { pt(); return; }
	}
	while(k) {
		sort(a + 1, a + m + 1); shift();
		if(m <= 1) { pt(); return; }
		ll res = LNF;
		FOR(i, 2, m) chmin(res, a[i] / a[i - 1]);
		chmin(res, k);
		a[3] -= a[2] * res - a[1] * res * (res + 1) / 2;
		a[2] -= a[1] * res;
		k -= res;
	}
	pt();
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}