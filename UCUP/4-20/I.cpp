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
int n; ll a[N], b[N];
ll gcd(ll x, ll y) {
	if(! y) return x;
	return gcd(y, x % y);
}
void solve() {
	read(n);
	FOR(i, 1, n) read(a[i], b[i]);
	ll A = 0, B = 0;
	FOR(i, 1, n - 1) A = gcd(A, abs(a[i] - a[i + 1]));
	FOR(i, 1, n - 1) B = gcd(B, abs(b[i] - b[i + 1]));
	if(A != B) { print("NO"); return; }
	if(A == 0) {
		FOR(i, 1, n) if(a[i] != b[i]) { print("NO"); return; }
	}
	else {
		ll len = abs(a[1] - b[1]);
		if(len % A) { print("NO"); return; }
		int L = 0, R = 0;
		FOR(i, 1, n) {
			ll x = abs(a[1] - a[i]) / A;
			if(x & 1) L ++;
		}
		FOR(i, 1, n) {
			ll x = abs(a[1] - b[i]) / A;
			if(x & 1) R ++;
		}
		if(L != R) { print("NO"); return; }
	}
	print("YES");
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}