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
const int N = 4e6 + 10;
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
const int MAXN = 4e5;
ll f[MAXN], ans[MAXN];
ll A[MAXN], B[MAXN], tmp[MAXN];
//void mul(ll a[], ll b[], int n, int m, ll res[]){
//	int len = 1;
//	while(len < (n + m) + 1) len <<= 1;
//	NTT::init(len);
//	frep(i, 0, n) A[i] = a[i]; frep(i, n, len) A[i] = 0;
//	frep(i, 0, m) B[i] = b[i]; frep(i, m, len) B[i] = 0;
//	NTT::ntt(A, len, 1);
//	NTT::ntt(B, len, 1);
//	frep(i, 1, len) res[i] = A[i] * B[i];
//	NTT::ntt(res, len, -1);
//	return;
//}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	NTT::pre();
	int n;
	cin >> n;
	frep(i, 0, n) cin >> f[i];
	ans[0] = ksm(f[0], MOD - 2);
	for(int len = 1; len < n; len <<= 1){
		frep(i, 0, len) B[i] = ans[i]; frep(i, len, len << 1) B[i] = 0;
		frep(i, 0, len << 1) A[i] = f[i];
//		frep(i, 0, len << 1) cout << A[i] << " "; cout << endl;
		NTT::init(len << 2);
		NTT::ntt(A, len << 2, 1);
		NTT::ntt(B, len << 2, 1);
//		frep(i, 0, len << 1) cout << A[i] << " "; cout << endl;
		frep(i, 0, len << 2) ans[i] = (2 * B[i] - A[i] * B[i] % MOD * B[i] % MOD + MOD) % MOD;
		NTT::ntt(ans, len << 2, -1);
		frep(i, len << 1, len << 2) ans[i] = 0;
	}
	
	frep(i, 0, n) cout << ans[i] << " ";
    return 0;
}
