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
int n; uint a[N];
struct Node {
	int l, k; uint x;
	bool operator < (const Node & A) const {
		return l > A.l;
	}
};
inline ull shift(ull x) {
	x ^= x << 7;
	x ^= x >> 17;
	x ^= x << 13;
	return x;
}
struct Basis {
	uint b[32]; int p[32];
	Basis() {
		REP(i, 32) b[i] = p[i] = 0;
	}
	void insert(uint x, int i) {
		ROF(k, 31, 0) if(x >> k & 1) {
			if(! b[k]) {
				b[k] = x;
				p[k] = i;
				return;
			}
			if(i > p[k]) {
				swap(i, p[k]);
				swap(x, b[k]);
			}
			x ^= b[k];
		}
	}
	void add(uint x, int k) {
		b[k] = x;
		REP(i, k) if(b[k] >> i & 1) b[k] ^= b[i];
		FOR(i, k + 1, 31) if(b[i] >> k & 1) b[i] ^= b[k];
	}
	ull get() {
		ull res = 1145141;
		REP(i, 32) res = shift(res) ^ b[i];
		return res;
	}
};
void solve() {
	read(n);
	FOR(i, 1, n) read(a[i]);
	Basis b;
	unordered_set<ull> S;
	FOR(i, 1, n) if(a[i] == 0) {
		S.insert(b.get());
		break;
	}
	FOR(i, 1, n) {
		b.insert(a[i], i);
		VC<Node> e;
		REP(k, 32) if(b.b[k])
			e.pb({b.p[k], k, b.b[k]});
		sort(begin(e), end(e));
		Basis f;
		for(auto h : e) {
			f.add(h.x, h.k);
			S.insert(f.get());
		}
	}
	print(SZ(S));
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}