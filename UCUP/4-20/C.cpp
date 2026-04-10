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
const int N = 5e5 + 5;
int n, m, a[N];
int stk[N], tp;
int pre0[N], pre1[N];
int nxt0[N], nxt1[N];
struct Query { int l, r, x, i; };
VC<Query> e[N], q[N];
ll ans[N];
#define ls (u << 1)
#define rs (u << 1 | 1)
struct SgT1 {
	int le[N << 2], ri[N << 2];
	int F[N << 2];
	void build(int u, int l, int r) {
		le[u] = l, ri[u] = r;
		if(l == r) { F[u] = a[l]; return; }
		int mid = l + r >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		F[u] = min(F[ls], F[rs]);
	}
	int ql(int u, int l, int x) {
		if(ri[u] <= l || F[u] >= x) return - 1;
		if(le[u] == ri[u]) return le[u];
		int val = ql(ls, l, x);
		if(val == - 1) val = ql(rs, l, x);
		return val;
	}
	int qr(int u, int r, int x) {
		if(le[u] >= r || F[u] >= x) return - 1;
		if(le[u] == ri[u]) return le[u];
		int val = qr(rs, r, x);
		if(val == - 1) val = qr(ls, r, x);
		return val;
	}
} t1;
struct SgT2 {
	int le[N << 2], ri[N << 2];
	ll F[N << 2], H[N << 2];
	ll A[N << 2], T[N << 2], C[N << 2];
	inline void up(int u) {
		F[u] = F[ls] + F[rs];
		H[u] = H[ls] + H[rs];
	}
	inline void push(int u, ll x, ll h, ll c) {
		H[u] += h * (ri[u] - le[u] + 1) + c * F[u];
		T[u] += h + c * A[u];
		C[u] += c;
		F[u] += x * (ri[u] - le[u] + 1);
		A[u] += x;
	}
	inline void down(int u) {
		if(A[u] || T[u] || C[u]) {
			push(ls, A[u], T[u], C[u]);
			push(rs, A[u], T[u], C[u]);
			A[u] = T[u] = C[u] = 0;
		}
	}
	void build(int u, int l, int r) {
		le[u] = l, ri[u] = r;
		F[u] = H[u] = A[u] = T[u] = C[u] = 0;
		if(l == r) return;
		int mid = l + r >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		up(u);
	}
	void add(int u, int l, int r, ll x) {
		if(l <= le[u] && ri[u] <= r) return push(u, x, 0, 0);
		int mid = le[u] + ri[u] >> 1;
		down(u);
		if(l <= mid) add(ls, l, r, x);
		if(mid < r) add(rs, l, r, x);
		up(u);
	}
	ll query(int u, int l, int r) {
		if(l <= le[u] && ri[u] <= r) return H[u];
		down(u);
		int mid = le[u] + ri[u] >> 1;
		ll res = 0;
		if(l <= mid) res += query(ls, l, r);
		if(mid < r) res += query(rs, l, r);
		return res;
	}
} t2;
void add(int l1, int r1, int l2, int r2) {
	if(l1 > r1 || l2 > r2) return;
	e[l1].pb({l2, r2, 1});
	e[r1 + 1].pb({l2, r2, - 1});
}
void solve() {
	read(n, m);
	FOR(i, 1, n) read(a[i]);
	tp = 0; stk[tp] = 0;
	FOR(i, 1, n) {
		while(tp && a[stk[tp]] >= a[i]) tp --;
		pre0[i] = stk[tp];
		stk[++ tp] = i;
	}
	tp = 0; stk[tp] = 0;
	FOR(i, 1, n) {
		while(tp && a[stk[tp]] > a[i]) tp --;
		pre1[i] = stk[tp];
		stk[++ tp] = i;
	}
	tp = 0; stk[tp] = n + 1;
	ROF(i, n, 1) {
		while(tp && a[stk[tp]] >= a[i]) tp --;
		nxt0[i] = stk[tp];
		stk[++ tp] = i;
	}
	tp = 0; stk[tp] = n + 1;
	ROF(i, n, 1) {
		while(tp && a[stk[tp]] > a[i]) tp --;
		nxt1[i] = stk[tp];
		stk[++ tp] = i;
	}
	FOR(i, 1, n) e[i].clear();
	t1.build(1, 1, n);
	FOR(i, 1, n) {
		add(1, pre1[i], nxt1[i], n);
		int u = i - 1;
		while(u > pre1[i]) {
			int v = t1.ql(1, i, 2 * a[i] - a[u]);
			if(v != - 1) add(pre0[u] + 1, u, v, n);
			u = pre0[u];
		}
		u = i + 1;
		while(u < nxt1[i]) {
			int v = t1.qr(1, i, 2 * a[i] - a[u]);
			if(v != - 1) add(1, v, u, nxt0[u] - 1);
			u = nxt0[u];
		}
	}
	FOR(i, 1, n) q[i].clear();
	FOR(i, 1, m) {
		INT(l, r); ans[i] = 0;
		q[r].pb({l, r, 1, i});
		q[l - 1].pb({l, r, - 1, i});
	}
	t2.build(1, 1, n);
	FOR(i, 1, n) {
		for(auto h : e[i]) t2.add(1, h.l, h.r, h.x);
		t2.push(1, 0, 0, 1);
		for(auto h : q[i]) ans[h.i] += h.x * t2.query(1, h.l, h.r); 
	}
	FOR(i, 1, m) print(ans[i]);
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}