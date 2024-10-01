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
#include<complex>
//#include<unordered_map>
//#include<chrono>
#include<random>
#include<unordered_set>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define endl '\n'
using namespace std;
typedef long long ll;
const int MAXN = 2000;
ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a % b);
}
ll MOD = 1000000007;
ll ksm(ll a, ll k){
	ll ans = 1, now = a;
	while(k){
		if(k & 1) ans = ans * now % MOD;
		now = now * now % MOD;
		k >>= 1;
	}
	return ans;
}
int a[MAXN];
void solve(){
	int n;
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	int ans = 0;
	int mx = 0, cnt = 0;
	for(int i = 1; i <= n; i += 2){
		++cnt;
		mx = max(mx, a[i]);
	}
	ans = max(ans, mx + cnt);
	mx = 0, cnt = 0;
	for(int i = 2; i <= n; i += 2){
		++cnt;
		mx = max(mx, a[i]);
	}
	ans = max(ans, mx + cnt);
	cout << ans << endl;
}
int main(){
//	cout << ksm(2, 100);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int _t = 1;
	cin >> _t;
	while(_t--){
		solve();
	}
	return 0;
}

