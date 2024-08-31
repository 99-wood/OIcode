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
int co[MAXN];
int siz[MAXN];
int n;
vector<int> nxt[MAXN];
int fa[MAXN];
int cnt;
ll sum;
void dfs(int p){
	siz[p] = 1;
	for(auto x : nxt[p]){
		dfs(x);
		siz[p] += siz[x];
	}
	return;
}
int findco(int p){
	return co[p] == p ? p : co[p] = findco(co[p]);
}
void merge(int x, ll w){
//	if(x == 2){
//		cout << 1;
//	}
	int y = fa[x];
	int fy = findco(y);
	int fx = findco(x);
	int pre = x - 1 == 0 ? n : x - 1, suf = x + siz[x] > n ? 1 : x + siz[x];
	sum += w * 2;
	if(findco(pre) == fy) ++cnt;
	if(findco(suf) == fy && findco(x + siz[x] - 1) == fx) ++cnt;
	co[fx] = fy;
	return;
}
signed main(){
//	freopen("P2909_2.in", "r", stdin);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		ll w;
		cin >> n >> w;
		rep(i, 1, n) co[i] = i;
		rep(i, 1, n) nxt[i].clear();
		cnt = sum = 0;
		rep(i, 2, n){
			cin >> fa[i];
			nxt[fa[i]].push_back(i);
		}
		dfs(1);
		rep(i, 1, n - 1){
			int x;
			ll v;
			cin >> x >> v;
			merge(x, v);
			w -= v;
			cout << sum + (n - cnt) * w << " ";
//			cout << cnt << " ";
//			cout << sum << " ";
		}
		cout << endl;
	}
    return 0;
}
/*
1
6 100
1 2 3 2 1
6 17
3 32
2 4
4 26
5 21
*/
