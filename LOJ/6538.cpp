#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls tree[p].l
#define rs tree[p].r
//#define mid ((l + r) >> 1)
typedef long long ll;
typedef unsigned long long ull;
#define Maxq priority_queue<int,vector<int>,greater<int> >
using namespace std;
const double PI = acos(-1.0);
const int N = 1e6 + 10;
const int MOD = 998244353, g = 3;
ll ksm(ll a, ll k){
	ll now = a;
	ll ans = 1;
	while(k){
		if(k & 1) ans = (ans * now) % MOD;
		now = (now * now) % MOD;
		k >>= 1ll;
	}
	return ans;
}
namespace NTT{
	ll rev[N * 2];
	ll pr[N * 2];
	void pre(){
		for(ll l = 1; l < N; l <<= 1ll)
			pr[l] = ksm(g, (MOD - 1) / (l * 2));
	}
	void init(int len){
		memset(rev, 0, sizeof(rev));
		ll lim = 0;
		while((1ll << lim) < len) lim++;
		for(long long i = 0; i <= (1 << lim) - 1; i++)
			rev[i] = (rev[i >> 1ll] >> 1ll) | ((i & 1ll) << (lim - 1));
	}
	void ntt(ll a[], int limit, int opt = 1){
		frep(i, 0, limit) if(i < rev[i]) swap(a[i], a[rev[i]]);
		for(int mid = 1; mid < limit; mid <<= 1){
			ll W = pr[mid];
			if(opt == -1) W = ksm(W, MOD - 2);
//			cout << W << endl;
			for(int len = (mid << 1), s = 0; s < limit; s += len){
				ll w = 1;
				frep(k, 0, mid){
					ll x = a[s + k] % MOD, y = a[s + k + mid] * w % MOD;
					a[s + k] = (x + y) % MOD;
					a[s + k + mid] = (x - y + MOD) % MOD;
//					cout << a[s + k]  << " " << a[s + k + mid] << endl;
					w = w * W % MOD;
				}
			}
		}
		if(opt == -1){
			ll tmp = ksm(limit, MOD - 2);
			frep(i, 0, limit) a[i] = a[i] * tmp % MOD;
		}
	}
}
const int MAXN = 1e6;
//ll f[MAXN], ans[MAXN];
ll A[MAXN], B[MAXN];
void mul(ll a[], ll b[], int n, int m, ll res[]){
	int len = 1;
	while(len < m + n) len <<= 1;
	NTT::init(len);
	frep(i, 0, n) A[i] = a[i]; frep(i, n, len) A[i] = 0;
	frep(i, 0, m) B[i] = b[i]; frep(i, m, len) B[i] = 0;
	NTT::ntt(A, len, 1);
	NTT::ntt(B, len, 1);
	frep(i, 0, len) res[i] = A[i] * B[i];
	NTT::ntt(res, len, -1);
	return;
}
void inv(ll f[], int n, ll ans[]){
	ans[0] = ksm(f[0], MOD - 2);
	for(int len = 1; len < n; len <<= 1){
		frep(i, 0, len) B[i] = ans[i]; frep(i, len, len << 2) B[i] = 0;
		frep(i, 0, min(len << 1, n)) A[i] = f[i]; frep(i, min(len << 1, n), len << 2) A[i] = 0; 
//		frep(i, 0, len << 1) cout << A[i] << " "; cout << endl;
		NTT::init(len << 2);
		NTT::ntt(A, len << 2, 1);
		NTT::ntt(B, len << 2, 1);
//		frep(i, 0, len << 1) cout << A[i] << " "; cout << endl;
		frep(i, 0, len << 2) ans[i] = (2 * B[i] - A[i] * B[i] % MOD * B[i] % MOD + MOD) % MOD;
		NTT::ntt(ans, len << 2, -1);
		frep(i, len << 1, len << 2) ans[i] = 0;
	}
	return;
}
ll f[MAXN];
void newton(int n){
	f[0] = 1;
	for(int len = 1; len < n; len <<= 1){
		static ll f_2[MAXN], f_3[MAXN];
		static ll s_1[MAXN], s_2[MAXN];
		static ll m_1[MAXN], m[MAXN];
		mul(f, f, len, len, m_1);
		mul(m_1, f, len << 1, len, s_1);
		frep(i, 0, len << 1) f_2[i] = 0, f_3[i] = 0;
		for(int i = 0; i * 2 < (len << 1); ++i) f_2[i * 2] = f[i];
		for(int i = 0; i * 3 < (len << 1); ++i) f_3[i * 3] = f[i];
		mul(f, f_2, len, len << 1, s_2);
		static ll s[MAXN];
		frep(i, 0, len << 1) s[i] = (s_1[i] + 3 * s_2[i] + 2 * f_3[i]) % MOD;
		drep(i, (len << 1) - 1, 1) s[i] = s[i - 1];
		s[0] = 6 + MOD;
		frep(i, 0, len) s[i] = (s[i] + (MOD - 6) * f[i] % MOD) % MOD;
//		mul(f, f, len, len, m_1);
		frep(i, 0, (len << 1) - 1) m[i + 1] = 3 * (m_1[i] + f_2[i]) % MOD;
		m[0] = -6 + MOD;
		static ll inv_[MAXN];
		inv(m, len << 1, inv_);
		static ll tmp[MAXN];
		mul(s, inv_, len << 1, len << 1, tmp);
		frep(i, 0, len << 1) f[i] = (f[i] - tmp[i] + MOD) % MOD;
	}
	return;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	NTT::pre();
	int n = 97150;
	cin >> n;
	newton(n + 1);
	cout << f[n];
    return 0;
}
