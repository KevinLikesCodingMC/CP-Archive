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
void print() { pt_s(endl); cout << flush; }
template < class H , class ... T >
void print(H h, T ... t) { pt_s(h); if(sizeof ... (t)) pt_s(' '); print(t ...); }
#define INT(...) int __VA_ARGS__; read(__VA_ARGS__)
#define UINT(...) uint __VA_ARGS__; read(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; read(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__; read(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; read(__VA_ARGS__)
#define CHAR(...) char __VA_ARGS__; read(__VA_ARGS__)
#define popcount __builtin_popcount
ull shift(ull x) {
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	return x;
}
ull shift(initializer_list<int> a) {
	ull res = 1145141;
	for(int x : a) res = shift(res) ^ x;
	return res;
}
int n, m;
int dx[] = {0, 0, 1, - 1};
int dy[] = {1, - 1, 0, 0};
int pre[10][10];
map<ull, int> mp1, mp2, mp3;
int dfs1(int u, int U, int A);
int dfs2(int u, int U, int L, int R);
int dfs3(int u, int U, int A);
int dfs4(int u, int U, int A);
int dfs1(int u, int U, int A) {
	ull hs = shift({u, U, A});
	if(mp1.count(hs)) return mp1[hs];
	REP(S, 1 << 9) if((S & A) == S) 
		if(dfs2(u, U, S, A ^ S)) return mp1[hs] = 1;
	return mp1[hs] = 0;
}
int dfs2(int u, int U, int L, int R) {
	ull hs = shift({u, U, L, R});
	if(mp2.count(hs)) return mp2[hs];
	return mp2[hs] = min(dfs3(u, U, L), dfs3(u, U, R));
}
int dfs3(int u, int U, int A) {
	ull hs = shift({u, U, A});
	if(mp3.count(hs)) return mp3[hs];
	REP(x, 9) if(U >> x & 1)
		if(dfs4(u, U ^ (1 << x), A)) return mp3[hs] = 1;
	return mp3[hs] = 0;
}
int dfs4(int u, int U, int A) {
	int S = 0;
	REP(x, 3) REP(y, 3) {
		int X = x * 3 + y;
		if(A >> X & 1) REP(d, 4) {
			int px = x + dx[d];
			int py = y + dy[d];
			if(px < 0 || px > 2 || py < 0 || py > 2) continue;
			int Y = px * 3 + py;
			if(U >> Y & 1) S |= 1 << Y;
		}
	}
	if(S == 0) return 1;
	if(u == n) return 0;
	return dfs1(u + 1, U, S);
}
void solve() {
	read(n, m);
	int U = (1 << 9) - 1;
	REP(_, m) {
		INT(x);
		U ^= 1 << (x - 1);
	}
	int res = dfs1(1, U, U);
	if(res) {
		print("Trapper");
		int A = U;
		FOR(u, 1, n) {
			int L = 0, R = 0;
			REP(S, 1 << 9) if((S & A) == S) 
				if(dfs2(u, U, S, A ^ S)) {
					L = S, R = A ^ S;
					break;
				}
			print(popcount(L));
			REP(x, 9) if(L >> x & 1) cout << x + 1 << ' ';
			print();
			STR(o);
			if(o == "Yes") A = L;
			else A = R;
			REP(x, 9) if(U >> x & 1)
				if(dfs4(u, U ^ (1 << x), A)) {
					print(x + 1);
					U ^= 1 << x;
					break;
				}
			int S = 0;
			REP(x, 3) REP(y, 3) {
				int X = x * 3 + y;
				if(A >> X & 1) REP(d, 4) {
					int px = x + dx[d];
					int py = y + dy[d];
					if(px < 0 || px > 2 || py < 0 || py > 2) continue;
					int Y = px * 3 + py;
					if(U >> Y & 1) S |= 1 << Y;
				}
			}
			A = S;
			read(o);
			if(o == "Trapped") return;
		}
	}
	else {
		print("Runner");
		int A = U;
		FOR(u, 1, n) {
			INT(k); int L = 0;
			REP(_, k) {
				INT(x);
				L |= 1 << (x - 1);
			}
			if(! dfs3(u, U, L)) {
				print("Yes");
				A = L;
			}
			else {
				print("No");
				A ^= L;
			}
			INT(pos); U ^= 1 << (pos - 1);
			int S = 0;
			REP(x, 3) REP(y, 3) {
				int X = x * 3 + y;
				if(A >> X & 1) REP(d, 4) {
					int px = x + dx[d];
					int py = y + dy[d];
					if(px < 0 || px > 2 || py < 0 || py > 2) continue;
					int Y = px * 3 + py;
					if(U >> Y & 1) {
						S |= 1 << Y;
						pre[u][Y] = X;
					}
				}
			}
			A = S;
			print("Free");
		}
		VI ans;
		int pos = __lg(A);
		ans.pb(pos);
		ROF(u, n, 1) {
			pos = pre[u][pos];
			ans.pb(pos);
		}
		reverse(begin(ans), end(ans));
		for(int x : ans) cout << x + 1 << ' ';
		print();
	}
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}