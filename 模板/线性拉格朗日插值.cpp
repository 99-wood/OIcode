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
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;
typedef long long ll;
//const int MOD = 1000;
const ll MAXN = 1000010;
const ll MOD = 1e9 + 7;
ll ksm(ll a, ll k){
	ll ans = 1, now = a;
	while(k){
		if(k & 1) ans = (ans * now) % MOD;
		now = (now * now) % MOD;
		k >>= 1;
	}
	return ans;
}
ll jc[MAXN], inv[MAXN];
ll a[MAXN];
ll b[MAXN];
int main(){
//	freopen("P2909_2.in", "r", stdin);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int N = 1000005;
	int n, k;
	cin >> n >> k;
	rep(i, 1, k + 2) a[i] = (a[i - 1] + ksm(i, k)) % MOD;
	if(k == 0){
		cout << n << endl;
		return 0;
	}
	if(n <= k + 2){
		ll ans = 0;
		rep(i, 1, n) ans = (ans + ksm(i, k)) % MOD;
		cout << ans;
		return 0;
	}
	jc[0] = 1;
	rep(i, 1, N) jc[i] = jc[i - 1] * i % MOD;
	inv[N] = ksm(jc[N], MOD - 2);
	drep(i, N - 1, 0) inv[i] = inv[i + 1] * (i + 1) % MOD;
//	b[0] = n % MOD;
	b[0] = 1;
	rep(i, 1, k + 2) b[i] = b[i - 1] * (n - i) % MOD;
	ll ans = 0;
	rep(i, 1, k + 2){
		ll y = a[i];
		ll A = b[k + 2] * ksm(n - i, MOD - 2) % MOD;
		ll B = (((k + 2 - i) & 1) ? -1ll : 1ll) * inv[i - 1] % MOD * inv[k + 2 - i] % MOD;
		ans += y * A % MOD * B % MOD;
		ans %= MOD;
	}
	cout << (ans + MOD) % MOD;
    return 0;
}
