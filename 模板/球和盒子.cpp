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
//#include<unordered_map>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int MAXN = 1000010;
ll jc[MAXN];
ll inv[MAXN];
ll S[2000][2000];
ll p[2000][2000];
ll ksm(ll a, ll k){
	if(k < 0) return 0;
	ll ans = 1, now = a;
	while(k){
		if(k & 1) ans = (ans * now) % MOD;
		now = (now * now) % MOD;
		k >>= 1;
	}
	return ans;
}
ll C(int n, int m){
	return jc[n] * inv[n - m] % MOD * inv[m] % MOD;
}
ll f1(ll n, ll k){
	return ksm(k, n);
}
ll f2(ll n, ll k){
	if(n > k) return 0;
	return C(k, n) * jc[n] % MOD;
}
ll f3(ll n, ll k){
	return jc[k] * S[n][k] % MOD;;
}
ll f4(ll n, ll k){
	return C(n + k - 1, k - 1);
}
ll f5(ll n, ll k){
	if(n > k) return 0;
	return C(k, n);
}
ll f6(ll n, ll k){
	return C(n - 1, k - 1);
}
ll f7(ll n, ll k){
	ll ans = 0;
	rep(i, 0, k){
		ans += S[n][k - i];
	}
	return ans % MOD;
}
ll f8(ll n, ll k){
	if(n > k) return 0;
	return 1;
}
ll f9(ll n, ll k){
	return S[n][k];
}
ll f10(ll n, ll k){
	ll ans = 0;
	rep(i, 0, k){
		ans += p[n][k - i];
	}
	return ans % MOD;
}
ll f11(ll n, ll k){
	if(n > k) return 0;
	return 1;
}
ll f12(ll n, ll k){
	return p[n][k];
}

int main(){
//	freopen("P2909_2.in", "r", stdin);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int N = 100000;
	jc[0] = 1;
	rep(i, 1, N) jc[i] = (jc[i - 1] * i) % MOD;
	inv[N] = ksm(jc[N], MOD - 2);
	drep(i, N - 1, 0) inv[i] = inv[i + 1] * (i + 1) % MOD;
	int n = 1000;
	S[0][0] = 1;
	rep(i, 1, n){
		S[i][i] = 1;
		S[i][0] = 0;
		rep(j, 1, i - 1){
			S[i][j] = (S[i - 1][j - 1] + j * S[i - 1][j]) % MOD;
		}
	}
	p[0][0] = 1;
	rep(i, 1, n){
		p[i][i] = 1;
		p[i][0] = 0;
		rep(j, 1, i - 1){
			p[i][j] = p[i - 1][j - 1];
			if(i >= j) p[i][j] = (p[i][j] + p[i - j][j]) % MOD;
		}
	}
	int t;
	cin >> t;
	while(t--){
		int op, n, k;
		cin >> op >> n >> k;
		ll ans;
		switch(op){
			case 1: ans = f1(n, k); break;
			case 2: ans = f2(n, k); break;
			case 3: ans = f3(n, k); break;
			case 4: ans = f4(n, k); break;
			case 5: ans = f5(n, k); break;
			case 6: ans = f6(n, k); break;
			case 7: ans = f7(n, k); break;
			case 8: ans = f8(n, k); break;
			case 9: ans = f9(n, k); break;
			case 10: ans = f10(n, k); break;
			case 11: ans = f11(n, k); break;
			case 12: ans = f12(n, k); break;
		}
		cout << ans << endl;
	}
    return 0;
}
