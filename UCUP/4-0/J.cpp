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
typedef VC<mint> poly;
VI rev;
inline int bit_ceil(int x) {
	return 1 << (32 - __builtin_clz(x - 1));
}
int set_rev(int n) {
	int lim = bit_ceil(n);
	int l = __lg(lim);
	rev.resize(lim);
	REP(i, lim) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
	return lim;
}
void NTT(poly & a, int o) {
	int lim = SZ(a);
	REP(i, lim) if(i < rev[i]) swap(a[i], a[rev[i]]);
	for(int i = 1; i < lim; i <<= 1) {
		mint wn = mint(o == 1 ? 3 : (P + 1) / 3).pow((P - 1) / (i << 1));
		for(int j = 0; j < lim; j += (i << 1)) {
			mint w = 1;
			REP(k, i) {
				mint x = a[j + k];
				mint y = a[j + k + i] * w;
				a[j + k] = x + y;
				a[j + k + i] = x - y;
				w *= wn;
			}
		}
	}
	if(o == 1) return;
	mint inv = mint(lim).inv();
	REP(i, lim) a[i] *= inv;
}
poly conv_naive(const poly & a, const poly & b) {
	int n = SZ(a), m = SZ(b);
	poly ans(n + m - 1);
	if(n < m) {
		REP(j, m) REP(i, n) ans[i + j] += a[i] * b[j];
	}
	else {
		REP(i, n) REP(j, m) ans[i + j] += a[i] * b[j];
	}
	return ans;
}
poly conv_ntt(poly a, poly b) {
	int n = SZ(a), m = SZ(b);
	int lim = set_rev(n + m - 1);
	a.resize(lim); b.resize(lim);
	NTT(a, 1);
	NTT(b, 1);
	REP(i, lim) a[i] *= b[i];
	NTT(a, - 1);
	a.resize(n + m - 1);
	return a;
}
poly conv(poly a, poly b) {
	int n = SZ(a), m = SZ(b);
	if(! n || ! m) return {};
	if(min(n, m) <= 60) return conv_naive(a, b);
	else return conv_ntt(a, b);
}
int n; string s;
struct F { poly a[3][3]; };
F slv(int l, int r) {
	F res;
	FOR(i, 0, 2) FOR(j, i, 2) res.a[i][j].resize(r - l + 2);
	if(l == r) {
		int u = s[l] == 'R' ? 2 : (s[l] == 'Y');
		res.a[u][u][1] = 1;
		return res;
	}
	int mid = l + r >> 1;
	F L = slv(l, mid), R = slv(mid + 1, r);
	FOR(i, 0, 2) FOR(j, i, 2) {
		REP(u, SZ(L.a[i][j])) res.a[i][j][u] += L.a[i][j][u];
		REP(u, SZ(R.a[i][j])) res.a[i][j][u] += R.a[i][j][u];
	}
	FOR(i, 0, 2) FOR(j, i, 2) FOR(p, j, 2) FOR(q, p, 2) {
		auto h = conv(L.a[i][j], R.a[p][q]);
		REP(u, SZ(h)) res.a[i][q][u] += h[u];
	}
	return res;
}
void solve() {
	read(s); n = SZ(s);
	F res = slv(0, n - 1);
	poly a(n + 1);
	FOR(i, 0, 2) FOR(j, i, 2) 
		REP(u, SZ(res.a[i][j])) a[u] += res.a[i][j][u];
	mint ans = n, C = 1;
	FOR(i, 1, n) {
		C *= n - i + 1; C /= i;
		ans -= a[i] / C;
	}
	print(ans);
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}