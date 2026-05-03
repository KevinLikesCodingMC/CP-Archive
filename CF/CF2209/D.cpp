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
int a[3];
string s;
void sw(int x, int y) {
	if(a[x] > a[y]) return;
	swap(a[x], a[y]);
	swap(s[x], s[y]);
}
void solve() {
	REP(i, 3) read(a[i]);
	s = "RGB";
	sw(0, 1); sw(1, 2); sw(0, 1);
	if(a[0] >= a[1] + a[2] + 1) {
		chmin(a[0], a[1] + a[2] + 1);
		REP(_, a[1]) cout << s[0] << s[1];
		REP(_, a[2]) cout << s[0] << s[2];
		cout << s[0] << endl;
		return;
	}
	if(a[2] == 1) {
		REP(_, a[1]) cout << s[0] << s[1];
		if(a[0] > a[1]) cout << s[0];
		cout << s[2] << endl;
		return;
	}
	int sum = a[0] + a[1] + a[2];
	if(sum & 1) a[0] --, cout << s[0];
	sum >>= 1;
	REP(_, sum - a[2]) cout << s[1] << s[0];
	REP(_, sum - a[1]) cout << s[2] << s[0];
	REP(_, sum - a[0]) cout << s[2] << s[1];
	cout << endl;
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}