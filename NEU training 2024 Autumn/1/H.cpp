//#pragma GCC optimize(3, "Ofast", "inline")
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
//#include<numeric>
//#include<random>
//#include<unordered_map>
//#include<chrono>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define int long long 
using namespace std;
typedef long long ll;
const int MAXN = 100010;
const ll INF = 1e18;
const int N = 40000;
vector<int> prime;
int d[MAXN];
void Euler(){
	for(int i = 2; i <= N; ++i){
		if(!d[i]){
			d[i] = i;
			prime.push_back(i);
		}
		for(auto p : prime){
			if((ll)p * i > N || p > d[i]) break;
			d[p * i] = p;
		}
	}
}
ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a % b);
}
vector<int> son;
vector<pair<int, int> > s;
void dfs(int p, int now){
	if(p >= s.size()){
		son.push_back(now);;
		return;
	}
	dfs(p + 1, now);
	rep(i, 1, s[p].second){
		now *= s[p].first;
		dfs(p + 1, now);
	}
	return;
}
int check(ll m, ll n){
	if(m * m - 4 * n < 0) return -1;
	ll tmp = sqrt(m * m - 4 * n);
	ll x = (m + tmp) / 2, y = (m - tmp) / 2;
	if(x + y == m && x * y == n && gcd(x, y) == 1) return x;
	else return -1;
}
void solve(){
	ll n, k;
	cin >> n >> k;
	ll nn = n;
	int p = 0;
	s.clear();
	son.clear();
	while(n != 1 && p < prime.size()){
		if(prime[p] > n) break;
		int cnt = 0;
		while(n % prime[p] == 0){
			n /= prime[p];
			++cnt;
		}
		if(cnt) s.push_back(pair<int, int> (prime[p], cnt));
		++p;
	}
	if(n > 1) s.push_back(pair<int, int> (n, 1));
	dfs(0, 1);
	for(auto x : son){
//		cout << x << " ";
		if(k % x == 0 && check(nn / x, k / x) != -1){
			ll p = check(nn / x, k / x);
			ll q = nn / x - p;
			if(p > q) swap(p, q);
			cout << x * p << " " << x * q << endl;
		}
	}
}
signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	Euler();
//	cout << prime.size();
//	for(auto p : prime) cout << p << " ";
//	cout << pri
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
