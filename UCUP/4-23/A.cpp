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
#define popcount __builtin_popcount
const int N = 1e5 + 5;
const ll LNF = 1e18;
int n, m, s[N], pc[N];
string A[N], B[N];
ll dp[2][1 << 6];
void solve() {
	read(n, m);
	int lim = 1 << m, U = lim - 1;
	FOR(i, 1, n) read(A[i]);
	FOR(i, 1, n) read(B[i]);
	FOR(k, 1, n) {
		s[k] = s[k - 1];
		REP(i, m) s[k] -= (A[k][i] == 'C');
		REP(i, m) s[k] += (B[k][i] == 'C');
	}
	REP(S, lim) pc[S] = popcount(S);
	int o = 0;
	REP(S, lim) {
		dp[o][S] = 0;
		int c = 0;
		REP(i, m) {
			if(A[1][i] == 'C') dp[o][S] -= c;
			if(B[1][i] == 'C') dp[o][S] += c;
			(S >> i & 1) ? c ++ : c --;
		}
	}
	FOR(k, 2, n) {
		REP(S, lim) dp[o ^ 1][S] = - LNF;
		REP(S, lim) {
			int T = (S << 1) & U;
			chmax(dp[o ^ 1][T], dp[o][S] - s[k - 1]);
		}
		REP(S, lim) {
			int T = (S << 1 | 1) & U;
			chmax(dp[o ^ 1][T], dp[o][S] + s[k - 1]);
		}
		o ^= 1;
		FOR(i, 1, m - 1) {
			REP(S, lim) dp[o ^ 1][S] = dp[o][S];
			REP(S, lim) {
				int l = S >> (i - 1) & 1;
				int r = S >> i & 1;
				if(l != r) {
					int T = S;
					T ^= 1 << i - 1; T ^= 1 << i;
					chmax(dp[o ^ 1][T], dp[o][S]);
				}
			}
			o ^= 1;
			int val = (B[k][i] == 'C') - (A[k][i] == 'C');
			REP(S, lim) {
				int w = pc[S & ((1 << i) - 1)] * 2 - i;
				dp[o][S] += val * w;
			}
		}
	}
	ll ans = - LNF;
	REP(S, lim) chmax(ans, dp[o][S]);
	print(ans);
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}