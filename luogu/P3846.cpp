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
//#include<chrono>
#include<random>
#include<functional>
#include<unordered_set>
#include<unordered_map>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
//#define ls (p << 1)
//#define rs (p << 1 | 1)
//#define mid ((l + r) >> 1)
#define endl '\n'
using namespace std;
typedef long long ll;
const int MAXN = 1000010;
const int N = 200000;
//#define int long long
ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a % b);
}
void exgcd(ll a, ll b, ll &x, ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return;
	}
	exgcd(b, a % b, y, x);
	y = y - a / b * x;
	return;
}
ll BSGS(ll a, ll b, ll p){
	ll k = sqrt(p) + 1;
	unordered_map<ll, ll> s;
	ll now = b;
	rep(i, 0, k){
		s[now] = i;
		now = now * a % p;
	}
	ll ak = 1;
	rep(i, 1, k) ak = ak * a % p;
	now = ak;
	rep(i, 1, k){
		if(s.count(now)){
			return i * k - s[now];
		}
		now = now * ak % p;
	}
	return -1;
}
void solve(){
	ll a, b, p;
	cin >> p >> a >> b;
	ll ans = BSGS(a, b, p);
	if(ans == -1) cout << "no solution" << endl;
	else cout << ans << endl;
//	cout << ans << endl;
}
signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int _t = 1;
//	cin >> _t;
	while(_t--){
		solve();
	}
}
