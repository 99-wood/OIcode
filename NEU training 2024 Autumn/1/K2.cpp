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
#define endl '\n'
//#include<numeric>
//#include<random>
//#include<unordered_map>
//#include<chrono>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
//#define ls (p << 1)
//#define rs (p << 1 | 1)
//#define mid ((l + r) >> 1)
#define int long long 
using namespace std;
typedef long long ll;
const int MAXN = 1e5+10;
int val[MAXN];
vector<int> nxt[MAXN];
vector<int> son[MAXN];
int mx[MAXN], mn[MAXN];
int n;
int ans = 1e5;
int id[MAXN];
int to[MAXN];
int endd;
vector<int> vis(510);
void dfs(int p, int fa){
//	vis.clear();
	mx[p] = -1;
	mn[p] = 1e5;
	if(nxt[p].size() == 1 && p != 1){
		son[p].push_back(p);
		mx[p] = mn[p] = val[p];
		return;
	}
	int delta = 0;
	for(auto x : nxt[p]){
		if(x == fa) continue;
		dfs(x, p);
		for(auto y : son[x]){
			son[p].push_back(y);
		}
		mx[p] = max(mx[p], mx[x]);
		mn[p] = min(mn[p], mn[x]);
		delta = max(delta, mx[x] - mn[x]);
	}
//	vis.resize(endd + 10, 0);
	rep(i, 1, endd) vis[i] = 0;
	int mxv = -1, mnv = 1e5;
//	cout << p << ":";
	for(auto x : son[p]){
//		cout << id[x] << " ";
		vis[id[x]] = true;
	}
//	rep(i, 1, endd) cout << vis[i] << " ";
//	if(p == 5){
//		cout << 1;
//	}
	rep(i, 1, endd){
		if(vis[i]) continue;
		mxv = max(mxv, val[to[i]]);
		mnv = min(mnv, val[to[i]]);
	}
//	cout << p << " " << delta << " " << mxv - mnv << endl;
	ans = min(ans, max(delta, mxv - mnv));
	return;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>val[i];
//	cout << endl;
	rep(i, 1, n){
		if(val[i]){
			id[i] = ++endd;
			to[endd] = i;
		}
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		nxt[u].push_back(v);
		nxt[v].push_back(u);
	}
	dfs(1, 0);
	cout << ans << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
/*
5 2
1 3 1 4 5
1 3 4 2
2 2 4
*/
