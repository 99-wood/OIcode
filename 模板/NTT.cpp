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
#define mid ((l + r) >> 1)
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
		for(int l = 1; l < limit; l <<= 1){
			ll W = pr[l];
			if(opt == -1) W = ksm(W, MOD - 2);
//			cout << W << endl;
			for(int len = (l << 1), s = 0; s < limit; s += len){
				ll w = 1;
				frep(k, 0, l){
					ll x = a[s + k] % MOD, y = a[s + k + l] * w % MOD;
					a[s + k] = (x + y) % MOD;
					a[s + k + l] = (x - y + MOD) % MOD;
//					cout << a[s + k]  << " " << a[s + k + l] << endl;
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
const int MAXN = 4e6;
ll a[MAXN], b[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	NTT::pre();
//	rep(i, 1, 100) cout << NTT::pr[i] << ' ';
	int n, m;
	int len = 0;
	cin >> n >> m;
	while((1 << len) < m + n + 1){
		++len;
	}
	NTT::init(1 << len);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];
	NTT::ntt(a, 1 << len);
	NTT::ntt(b, 1 << len);
	frep(i, 0, 1 << len) a[i] = (a[i] * b[i]) % MOD;
	NTT::ntt(a, 1 << len, -1);
	rep(i, 0, m + n) cout << a[i] << " ";
    return 0;
}
