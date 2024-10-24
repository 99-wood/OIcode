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
	if(x + y == m && x * y == n) return x;
	else return -1;
}
int n,m,x;
int vis[1<<23];
void solve(){
	int ans=0;
	cin>>n>>m>>x;
	vector<vector<int>> a(max(n,m)+10,vector<int>(min(n,m)+10));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(n>m) cin>>a[i][j];
			else cin>>a[j][i];
		}
	if(n<m)swap(n,m);
	for(int l=1;l<=m;l++){
		for(int r=l+1;r<=m;r++){
			for(int i=1;i<=n;i++){
				ans+=vis[x^(a[i][l]^a[i][r])];
				vis[a[i][l]^a[i][r]]++;
			}
			for(int i=1;i<=n;i++)vis[a[i][l]^a[i][r]]--;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	for(auto p : prime) cout << p << " ";
//	cout << pri
	int t = 1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
