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
template < class T >
using VC = vector<T>;
using VI = VC<int>;
template < class T >
using pq_max = priority_queue<T>;
template < class T >
using pq_min = priority_queue<T, VC<T>, greater<T>>;
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
const int N = 5e2 + 5;
int n;
struct Point {
	double x, y;
} a[N];
void solve() {
	read(n);
	FOR(i, 1, n) read(a[i].x, a[i].y);
	VI ans;
	FOR(i, 1, n) {
		Point A = a[i], B = a[i % n + 1];
		if(A.x < B.x) {
			int L = ceil(A.x), R = floor(B.x);
			double k = (B.y - A.y) / (B.x - A.x);
			FOR(x, L, R) ans.pb(floor(A.y + (x - A.x) * k));
		}
		if(A.y < B.y) {
			int L = ceil(A.y), R = floor(B.y);
			double k = (B.x - A.x) / (B.y - A.y);
			FOR(y, L, R) ans.pb(floor(A.x + (y - A.y) * k));
		}
	}
	print(SZ(ans));
	for(int x : ans) print(x);
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}