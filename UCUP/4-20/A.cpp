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
struct Point {
	double x, y;
	Point(double x = 0, double y = 0): x(x) , y(y) {}
};
struct Vector {
	double x, y;
	Vector(double x = 0, double y = 0): x(x) , y(y) {}
};
Vector operator + (Vector A, Vector B) {
	return Vector(A.x + B.x, A.y + B.y);
}
Vector operator - (Vector A, Vector B) {
	return Vector(A.x - B.x, A.y - B.y);
}
Vector operator - (Point A, Point B) {
	return Vector(A.x - B.x, A.y - B.y);
}
Vector operator * (Vector A, double x) {
	return Vector(A.x * x, A.y * x);
}
Point operator + (Point A, Vector B) {
	return Point(A.x + B.x, A.y + B.y);
}
Point operator - (Point A, Vector B) {
	return Point(A.x - B.x, A.y - B.y);
}
double Dot(Vector A, Vector B) {
	return A.x * B.x + A.y * B.y;
}
double Length(Vector A) {
	return sqrt(Dot(A, A));
}
void solve() {
	Point A, B;
	read(A.x, A.y, B.x, B.y);
	LL(M, W);
	if(M >= 3) { print(- 1); return; }
	cout << fixed << setprecision(10);
	if(M == 1) {
		double a = W / 2.;
		double b = Length(A - B);
		double c = sqrt(a * a + b * b);
		print(c + a);
	}
	else {
		print(Length(A - B) + W * 2);
	}
}
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	INT(T); while(T --)
	solve();
	return 0;
}