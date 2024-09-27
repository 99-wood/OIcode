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
int a[MAXN];
int color[MAXN];
bool vis[MAXN];
int ans[MAXN];
int dfs(int i, int now){
	if(vis[i]) return now;
	vis[i] = true;
	if(color[i] == 0) ans[i] = dfs(a[i], now + 1);
	else ans[i] = dfs(a[i], now);
	return ans[i];
}
signed main(){
//	freopen("P2909_2.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
//	cin >> t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		rep(i, 1, n) vis[i] = false;
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n){
			char c;
			scanf("\n%c", &c);
			color[i] = c - '0';
		}
		rep(i, 1, n){
			if(!vis[i]) dfs(i, 0);
		}
		rep(i, 1, n) cout << ans[i] << " ";
		cout << endl;
	}
    return 0;
}
