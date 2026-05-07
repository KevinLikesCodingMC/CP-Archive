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
const int N = 1e4 + 5;
int n, b[N], p[N];
mt19937 rnd(114);
map<PII, int> mp;
int query(int x, int y) {
	if(x > y) swap(x, y);
	if(mp.count({x, y})) return mp[{x, y}];
	print('?', x, y);
	INT(o); return mp[{x, y}] = o;
}
bool cmp(int x, int y) {
	int o = query(x, y);
	return (b[x] + o) % 3 == b[y];
}
void solve() {
	read(n); mp.clear();
	FOR(i, 1, n) b[i] = 2;
	b[1] = 0;
	FOR(i, 2, n) if(query(1, i) == 0) b[i] = 0;
	int pos = 0;
	FOR(i, 1, n) if(b[i]) {
		pos = i;
		break;
	}
	b[pos] = 1;
	FOR(i, 1, n) if(i != pos && query(pos, i) == 0) b[i] = 1;
	VC<VI> L, R; VI e;
	FOR(i, 1, n) if(b[i] == 0) e.pb(i);
	L.pb(e); e.clear();
	FOR(i, 1, n) if(b[i] == 1) e.pb(i);
	R.pb(e); VI ans;
	while(SZ(L) || SZ(R)) {
		if(! SZ(L)) { ans.pb(R[0][0]); break; }
		if(! SZ(R)) { ans.pb(L[0][0]); break; }
		if(SZ(L.back()) == 1) {
			int u = L.back()[0];
			VI l, r;
			for(int x : R.back()) {
				if(cmp(u, x)) r.pb(x);
				else l.pb(x);
			}
			if(r.empty()) {
				ans.pb(u);
				L.pop_back();
				continue;
			}
			R.pop_back();
			if(SZ(l)) R.pb(l); 
			if(SZ(r)) R.pb(r);
		}
		if(SZ(R.back()) == 1) {
			int u = R.back()[0];
			VI l, r;
			for(int x : L.back()) {
				if(cmp(u, x)) r.pb(x);
				else l.pb(x);
			}
			if(r.empty()) {
				ans.pb(u);
				R.pop_back();
				continue;
			}
			L.pop_back();
			if(SZ(l)) L.pb(l); 
			if(SZ(r)) L.pb(r);
		}
		if(SZ(L.back()) <= SZ(R.back())) {
			VI l, r;
			int sz = SZ(L.back());
			int u = L.back()[rnd() % sz];
			for(int x : R.back()) {
				if(cmp(u, x)) r.pb(x);
				else l.pb(x);
			}
			R.pop_back();
			if(SZ(l)) R.pb(l); 
			if(SZ(r)) R.pb(r);
		}
		else {
			VI l, r;
			int sz = SZ(R.back());
			int u = R.back()[rnd() % sz];
			for(int x : L.back()) {
				if(cmp(u, x)) r.pb(x);
				else l.pb(x);
			}
			L.pop_back();
			if(SZ(l)) L.pb(l); 
			if(SZ(r)) L.pb(r);
		}
	}
	reverse(begin(ans), end(ans));
	VC<PII> f;
	FOR(i, 1, n) if(b[i] == 2) {
		int L = 0, R = SZ(ans) - 1, res = SZ(ans);
		while(L <= R) {
			int mid = L + R >> 1;
			if(cmp(i, ans[mid])) res = mid, R = mid - 1;
			else L = mid + 1; 
		}
		f.eb(res, i);
	}
	sort(begin(f), end(f));
	reverse(begin(f), end(f));
	int tot = 0;
	REP(i, SZ(ans)) {
		if(SZ(f) && FI(f.back()) == i) {
			p[++ tot] = SE(f.back());
			f.pop_back();
		}
		p[++ tot] = ans[i];
	}
	if(SZ(f)) p[++ tot] = SE(f.back());
	if(p[1] > p[n]) reverse(p + 1, p + n + 1);
	cout << "! ";
	FOR(i, 1, n) cout << p[i] << ' ';
	print();
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}