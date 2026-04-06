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
#define uset unordered_set
const int N = 2e5 + 50;
const ll P = ll(1e18) + 3;
ll add(ll x, ll y) { return x + y < P ? x + y : x + y - P; }
ll sub(ll x, ll y) { return x < y ? x - y + P : x - y; }
int n, a[N];
int st[20][N];
ll pw[N], s[N];
VC<pair<ll, int>> e[N];
ll ans;
int get(int x, int y) {
	return a[x] > a[y] ? x : y;
}
void build() {
	FOR(i, 1, n) st[0][i] = i;
	FOR(j, 1, __lg(n)) FOR(i, 1, n - (1 << j) + 1)
		st[j][i] = get(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
}
int query(int l, int r) {
	int len = __lg(r - l + 1);
	return get(st[len][l], st[len][r - (1 << len) + 1]);
}
uset<ll> * dfs(int l, int r) {
	if(l > r) return nullptr;
	int u = query(l, r);
	if(l == r) {
		ans ++;
		uset<ll> * S = new uset<ll>();
		S -> insert(s[l]);
		return S;
	}
	uset<ll> * L = dfs(l, u - 1); 
	uset<ll> * R = dfs(u + 1, r);
	if(u - l + 1 <= r - u) {
		delete L;
		R -> insert(s[u]);
		FOR(i, l, u) FOR(k, a[u], a[u] + 20)
			ans += R -> count(add(s[i - 1], pw[k]));
		FOR(i, l, u) R -> insert(s[i]);
		return R;
	}
	else {
		delete R;
		FOR(i, u, r) FOR(k, a[u], a[u] + 20) {
			ans += L -> count(sub(s[i], pw[k]));
			ans += sub(s[i], pw[k]) == s[l - 1];
		}
		FOR(i, u, r) L -> insert(s[i]);
		return L;
	}
}
void solve() {
	read(n);
	FOR(i, 1, n) read(a[i]);
	pw[0] = 1;
	FOR(i, 1, N - 1) pw[i] = (pw[i - 1] * 2) % P;
	FOR(i, 1, n) s[i] = add(s[i - 1], pw[a[i]]);
	build();
	dfs(1, n);
	print(ans);
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}