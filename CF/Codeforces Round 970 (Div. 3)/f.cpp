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
const int MAXN = 200010;
const int MOD = 1000000007;
ll ksm(ll a, ll k){
	ll ans = 1, now = a;
	while(k){
		if(k & 1) ans = (ans * now) % MOD;
		now = (now * now) % MOD;
		k >>= 1;
	}
	return ans;
}
ll inv(ll a){
	return ksm(a, MOD - 2);
}
ll a[MAXN];
ll sum[MAXN];
signed main(){
//	freopen("P2909_2.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
//	scanf("%d", &t);
	while(t--){
		int n;
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) sum[i] = (sum[i - 1] + a[i]) % MOD;
		ll ans = 0;
		rep(i, 2, n){
			ans += a[i] * sum[i - 1] % MOD;
			ans %= MOD;
		}
		ll P = 2 * inv(n) % MOD * inv(n - 1) % MOD;
		ans = ans * P % MOD;
		cout << ans << endl;
	}
    return 0;
}
