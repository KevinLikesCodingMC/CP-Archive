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
const int N = 1e4 + 5;
int ip[N], p[N], cnt;
int a[N], b[N], d[N];
void init(int n) {
	ip[1] = 1;
	FOR(i, 2, n) {
		if(! ip[i]) p[++ cnt] = i;
		for(int j = 1; j <= cnt && p[j] * i <= n; j ++) {
			ip[p[j] * i] = 1;
			if(i % p[j] == 0) break;
		}
	}
}
int gcd(int x, int y) {
	if(! y) return x;
	return gcd(y, x % y);
}
void solve() {
	LL(A, B); init(N - 1);
	int g = gcd(A, B); A /= g, B /= g;
	FOR(i, 1, cnt) while(A % p[i] == 0) A /= p[i], a[i] ++;
	FOR(i, 1, cnt) while(B % p[i] == 0) B /= p[i], b[i] ++;
	A = B = 1;
	ROF(i, cnt, 1) if(a[i] || b[i]) {
		if((a[i] && a[i] % 2 == 0) || (b[i] && b[i] % 2 == 0)) a[i] ++, b[i] ++;
		REP(_, a[i] + 1 >> 1) A *= p[i];
		REP(_, b[i] + 1 >> 1) B *= p[i];
		if(a[i]) {
			int u = p[i] - 1;
			ROF(j, i, 1) while(u % p[j] == 0) {
				u /= p[j];
				if(! a[j]) a[j] ++, b[j] ++;
				a[j] --;
			}
		}
		if(b[i]) {
			int u = p[i] - 1;
			ROF(j, i, 1) while(u % p[j] == 0) {
				u /= p[j];
				if(! b[j]) a[j] ++, b[j] ++;
				b[j] --;
			}
		}
	}
	print(A, B);
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}