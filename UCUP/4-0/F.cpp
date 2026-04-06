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
void solve() {
	INT(T); while(T --) {
		INT(n, m, U, R, D, L);
		U -= n - 1, R -= m - 1;
		if(U < 0 || R < 0) {
			print("impossible");
			if(T) print();
			continue;
		}
		VC<VI> a(n, VI(m));
		int x = 0, y = 0;
		REP(_, D) {
			if(y == m - 1) y = 0, x ++;
			a[x][y] = 3;
			y ++;
		}
		REP(_, R) {
			if(y == m - 1) y = 0, x ++;
			a[x][y] = 2;
			y ++;
		}
		x = n - 1, y = 0;
		REP(_, n + m - 2) {
			if(x && ! a[x - 1][y]) a[x][y] = 1, x --;
			else a[x][y] = 2, y ++;
		}
		VC<PII> e;
		REP(i, n) REP(j, m) if(i || j < m - 1) if(! a[i][j]) e.eb(i, j);
		REP(_, U) {
			auto [x, y] = e.back(); e.pop_back();
			a[x][y] = 1;
		}
		REP(_, L) {
			auto [x, y] = e.back(); e.pop_back();
			a[x][y] = 4;
		}
		REP(i, n) {
			REP(j, m) cout << "*URDL"[a[i][j]];
			print();
		}
		if(T) print();
	}
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}