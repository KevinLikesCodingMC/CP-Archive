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
template <uint p>
struct Modint {
	uint x;
	Modint () : x(0) {}
	template < typename T >
	Modint (T v) { v %= int(p); if (v < 0) v += p; x = v; }
	Modint & operator ++ () { x ++; if (x == p) x = 0; return * this; }
	Modint & operator -- () { if (x == 0) x = p; x --; return * this; }
	Modint operator ++ (int) { Modint v = * this; ++ * this; return v; }
	Modint operator -- (int) { Modint v = * this; -- * this; return v; }
	Modint & operator += (const Modint & v) { x += v.x; if (x >= p) x -= p; return * this; }
	Modint & operator -= (const Modint & v) { x -= v.x; if (x >= p) x += p; return * this; }
	Modint & operator *= (const Modint & v) { ull z = x; z *= v.x; x = z % p; return * this; }
	Modint & operator /= (const Modint & v) { return * this = * this * v.inv(); }
	Modint operator + () const { return * this; }
	Modint operator - () const { return Modint() - * this; }
	Modint pow(ll n) const { Modint x = * this, r = 1; while (n) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
	Modint inv() const { return pow(p - 2); }
	friend Modint fp (const Modint & l, ll n) { return l.pow(n); }
	friend Modint inv (const Modint & l) { return Modint(l).inv(); }
	friend Modint operator + (const Modint & l, const Modint & r) { return Modint(l) += r; }
	friend Modint operator - (const Modint & l, const Modint & r) { return Modint(l) -= r; }
	friend Modint operator * (const Modint & l, const Modint & r) { return Modint(l) *= r; }
	friend Modint operator / (const Modint & l, const Modint & r) { return Modint(l) /= r; }
	friend bool operator == (const Modint & l, const Modint & r) { return l.x == r.x; }
	friend bool operator != (const Modint & l, const Modint & r) { return l.x != r.x; }
	friend istream & operator >> (istream & is, Modint & A) { return is >> A.x; }
	friend ostream & operator << (ostream & os, Modint A) { return os << A.x; }
};
const int P = 998244353;
typedef Modint<P> mint;
const int N = 5e3 + 5;
int n, a[N];
int f[N], sz[N], c[N];
mint fac[N], F[N];
int find(int u) {
	if(f[u] == u) return u;
	return f[u] = find(f[u]);
}
void merge(int u, int v) {
	u = find(u), v = find(v);
	if(u == v) return;
	f[v] = u;
	sz[u] += sz[v];
	c[u] += c[v];
}
void solve() {
	read(n);
	FOR(i, 1, n) read(a[i]);
	FOR(i, 1, n) f[i] = i, sz[i] = 1, c[i] = 0;
	FOR(i, 1, n / 2) if(a[i] != a[n - i + 1]) {
		merge(a[i], a[n - i + 1]);
		c[find(a[i])] ++;
	}
	int cnt = 0, sum = 0;
	FOR(i, 0, n) F[i] = 0;
	F[0] = 1;
	fac[0] = 1;
	FOR(i, 1, n + 1) fac[i] = fac[i - 1] * i;
	FOR(i, 1, n) if(find(i) == i) {
		if(c[i] > sz[i]) {
			print(fac[n + 1]);
			return;
		}
		if(c[i] < sz[i]) {
			cnt ++;
			ROF(k, n, 1) F[k] += F[k - 1] * sz[i];
		}
		if(c[i] == sz[i]) sum += sz[i];
	}
	mint ans = fac[n] * (n + 1);
	FOR(i, 0, cnt) ans -= F[i] * fac[i] * fac[n - i];
	print(ans);
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}