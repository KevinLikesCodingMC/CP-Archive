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
int n, q, a[N], b[N], f[N], s[N];
int pre[N], suf[N];
mint fac[N], finv[N];
mint F[N][N];
void init(int n) {
	fac[0] = 1;
	FOR(i, 1, n) fac[i] = fac[i - 1] * i;
	finv[n] = fac[n].inv();
	ROF(i, n - 1, 0) finv[i] = finv[i + 1] * (i + 1);
}
void solve() {
	read(n, q); init(n);
	FOR(i, 1, n) read(a[i]);
	FOR(i, 1, n) s[i] = s[i - 1] + (a[i] == - 1);
	pre[0] = suf[n + 1] = n;
	FOR(i, 1, n) {
		pre[i] = pre[i - 1];
		if(a[i] != - 1) chmin(pre[i], a[i]);
	}
	ROF(i, n, 1) {
		suf[i] = suf[i + 1];
		if(a[i] != - 1) chmin(suf[i], a[i]);
	}
	FOR(i, 1, n) if(a[i] != - 1) b[a[i]] = i;
	f[0] = ! b[0];
	FOR(i, 1, n) f[i] = f[i - 1] + ! b[i];
	int sum = s[n];
	FOR(len, 0, n) FOR(i, 0, n) {
		F[len][i + 1] = F[len][i];
		if(f[i] <= len) F[len][i + 1] += finv[len - f[i]] * fac[sum - f[i]];
	}
	REP(_, q) {
		INT(l, r);
		int lim = min(pre[l - 1], suf[r + 1]);
		int len = s[r] - s[l - 1];
		print(fac[len] * F[len][lim]);
	}
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}