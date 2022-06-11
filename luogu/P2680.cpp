#include<iostream>
#include<cstdio>
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
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls tree[p].l
#define rs tree[p].r
typedef long long ll;
typedef unsigned long long ull;
#define Maxq priority_queue<int,vector<int>,greater<int> >
using namespace std;
int mylog(int a) {
	int ans=0;
	if(a&0xffff0000) {
		ans+=16;
		a>>=16;
	}
	if(a&0x0000ff00) {
		ans+=8;
		a>>=8;
	}
	if(a&0x000000f0) {
		ans+=4;
		a>>=4;
	}
	if(a&0x0000000c) {
		ans+=2;
		a>>=2;
	}
	if(a&0x00000002) {
		ans+=1;
		a>>=1;
	}
	return ans;
}
inline int read() {
	register int a=0,b=0;
	register char c;
	c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')b=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}
const int MAXN = 3e5 + 10;
struct line{
	int p, w;
};
vector<struct line> nxt[MAXN];
int dep_[MAXN], dep[MAXN], fa[MAXN][20], tag[MAXN];
void dfs1(int p, int f){
	fa[p][0] = f;
	for(int i = 0; fa[fa[p][i]][i]; ++i){
		fa[p][i + 1] = fa[fa[p][i]][i];
	}
	for(auto x : nxt[p]){
		if(x.p == f) continue;
		dep_[x.p] = dep_[p] + x.w;
		dep[x.p] = dep[p] + 1;
		dfs1(x.p, p);
	}
	return;
}
int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 19; i >= 0; --i){
		if(fa[x][i] && dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if(x == y) return x;
	for(int i = 19; i >= 0; --i){
		if(fa[x][i] && fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
struct T{
	int x, y, lca, w;
}ask[MAXN];
int ans;
int check(int p, int q){
	int res = 0;
	for(auto x : nxt[p]){
		if(x.p == fa[p][0]) continue;
		int tmp = check(x.p, q);
		if(tmp >= q) ans = max(ans, x.w);
		res += tmp;
	}
	res += tag[p];
	tag[p] = 0;
	return res;
}
int main(){
	int n = read(), m = read();
	frep(i, 1, n){
		int x = read(), y = read(), z = read();
		nxt[x].push_back(line{y, z});
		nxt[y].push_back(line{x, z});
	}
	dfs1(1, 0);
	int l = 0, r = 0;
	int maxx = 0;
	rep(i, 1, m){
		ask[i].x = read();
		ask[i].y = read();
		ask[i].lca = lca(ask[i].x, ask[i].y);
		ask[i].w = dep_[ask[i].x] + dep_[ask[i].y] - 2 * dep_[lca(ask[i].x, ask[i].y)];
		maxx = max(maxx, ask[i].w);
	}
	r = maxx;
	l = max(0, r - 1010);
	int res;
	while(l <= r){
		int mid = (l + r) >> 1;
		int cnt = 0;
		rep(i, 1, m){
//			cout << dep[ask[i].x] + dep[ask[i].y] - 2 * dep[lca(ask[i].x, ask[i].y)] << " ";
			if(ask[i].w > mid){
				tag[ask[i].x] += 1;
				tag[ask[i].y] += 1;
				tag[ask[i].lca] -= 2;
				++cnt;
			}
		}
//		cout << endl;
		ans = 0;
		check(1, cnt);
		if(ans >= maxx - mid){
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d\n", res);
	return 0;
}