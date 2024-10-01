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
const int MAXN = 600000;
vector<int> nxt[MAXN];
int dep[MAXN];
int fa[MAXN];
int siz[MAXN];
int sum[MAXN];
int n;
const int INF = 0x3f3f3f3f;
vector<int> leaf[MAXN];
void dfs(int p, int f){
	siz[p] = 0;
	fa[p] = f;
	dep[p] = dep[f] + 1;
	if(nxt[p].size() == 1 && p != 1){
		leaf[dep[p]].push_back(p);
		return;
	}
	for(auto x : nxt[p]){
		if(x == f) continue;
		dfs(x, p);
		++siz[p];
	}
	int mx = 0;
	rep(i, 1, n) mx = max(mx, dep[i]);
	return;
}
int cnt = 0;
void del(int p){
	++cnt;
	if(fa[p]){
		--siz[fa[p]];
		if(siz[fa[p]] == 0){
			del(fa[p]);
		}
	}
}
void solve(){
	cin >> n;
	rep(i, 1, n) nxt[i].clear();
	rep(i, 1, n) leaf[i].clear();
	rep(i, 1, n + 1) sum[i] = 0;
	cnt = 0;
	rep(i, 1, n - 1){
		int u, v;
		cin >> u >> v;
		nxt[u].push_back(v);
		nxt[v].push_back(u);
	}
	dfs(1, 0);
	int mx = 0;
	rep(i, 1, n){
		mx = max(mx, dep[i]);
		sum[dep[i]]++;
	}
	sum[mx + 1] = 0;
	drep(i, mx, 1) sum[i] += sum[i + 1];
	int ans = INF;
	rep(d, 1, mx){
		for(auto x : leaf[d - 1]) del(x);
		ans = min(ans, sum[d + 1] + cnt);
	}
	cout << ans << endl;
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

