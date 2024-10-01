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
const int MAXN = 300000;
ll a[MAXN];
int n;
ll k;
#define int long long
void solve(){
	cin >> n;
	cin >> k;
	rep(i, 1, n) cin >> a[i];
	ll mx = 0;
	ll sum = 0;
	rep(i, 1, n) mx = max(mx, a[i]);
	rep(i, 1, n) sum += a[i];
	ll ans = 1;
	for(ll h = n; h >= 1; --h){
		ll x = (sum + k) / h;
		if(x < mx || x * h < sum) continue;
		cout << h << endl;
		return;
	}
}
signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int _t = 1;
	cin >> _t;
	while(_t--){
		solve();
	}
	return 0;
}

