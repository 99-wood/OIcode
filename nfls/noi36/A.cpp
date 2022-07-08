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
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
typedef long long ll;
typedef unsigned long long ull;
#define Maxq priority_queue<int,vector<int>,greater<int> >
using namespace std;
int mylog(int a){
	int ans=0;
	if(a&0xffff0000){
		ans+=16;
		a>>=16;
	}
	if(a&0x0000ff00){
		ans+=8;
		a>>=8;
	}
	if(a&0x000000f0){
		ans+=4;
		a>>=4;
	}
	if(a&0x0000000c){
		ans+=2;
		a>>=2;
	}
	if(a&0x00000002){
		ans+=1;
		a>>=1;
	}
	return ans;
}
inline int read(){
	register int a=0,b=0;
	register char c;
	c=getchar();
	while(c<'0'||c>'9'){
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
const int MAXN = 2e5 + 10;
int n, q;
int a[MAXN];
struct node{
	int to, w1, w2;
};
vector<struct node> nxt[MAXN];
int fa[MAXN], siz[MAXN], son[MAXN], top[MAXN], dfn[MAXN], dep[MAXN], dep1[MAXN], dep2[MAXN], id[MAXN], endd;
int f[MAXN], w[MAXN], w_[MAXN];
ll sum[MAXN];
void dfs(int p){
	f[p] = a[p];
	for(auto x : nxt[p]){
		if(x.to == fa[p]) continue;
		dfs(x.to);
		if(f[x.to] - x.w1 - x.w2 > 0){
			w[x.to] = f[x.to] - x.w1 - x.w2;
			f[p] += f[x.to] - x.w1 - x.w2;
		}
	}
	return;
}
void dfs_(int p){
	for(auto x : nxt[p]){
		if(x.to == fa[p]){
			w_[p] = max(w_[fa[p]] + f[fa[p]] - w[p] - x.w1 - x.w2, 0);
			break;
		}
	}
	for(auto x : nxt[p]){
		if(x.to == fa[p]) continue;
		dfs_(x.to);
	}
	return;
}
void dfs1(int p, int f){
	fa[p] = f;
	siz[p] = 1;
	dep[p] = dep[fa[p]] + 1;
	for(auto x : nxt[p]){
		if(x.to == fa[p]){
			dep1[p] = dep1[fa[p]] + x.w1;
			dep2[p] = dep2[fa[p]] + x.w2;
			break;
		}
	}
	for(auto x : nxt[p]){
		if(x.to == fa[p]) continue;
		dfs1(x.to, p);
		siz[p] += siz[x.to];
		if(siz[x.to] > siz[son[p]]) son[p] = x.to;
	}
	return;
}
void dfs2(int p){
	dfn[p] = ++endd;
	id[endd] = p;
	if(son[p]){
		top[son[p]] = top[p];
		dfs2(son[p]);
	}
	for(auto x : nxt[p]){
		if(x.to == fa[p] || x.to == son[p]) continue;
		dfs2(x.to);
	}
}
int main(){
	freopen("strawberry.in", "r", stdin);
	freopen("strawberry.out", "w", stdout);
	n = read(), q = read() ;
	rep(i, 1, n){
		top[i] = i;
		a[i] = read();
	}
	frep(i, 1, n){
		int x = read(), y = read(), z1 = read(), z2 = read();
		nxt[x].push_back(node{y, z1, z2});
		nxt[y].push_back(node{x, z2, z1});
	}
	dfs1(1, 0);
	dfs(1);
	dfs_(1);
	dfs2(1);
	rep(i, 1, n){
		sum[i] = sum[i - 1] + (ll)(f[id[i]] - w[son[id[i]]]);
	}
	while(q--){
		int x = read(), y = read();
		int lastx = 0, lasty = 0;
		int ans = 0;
		while(top[x] != top[y]){
			if(dep[top[x]] > dep[top[y]]){
				ans += sum[dfn[x]] - sum[dfn[top[x]] - 1] - lastx + w[son[x]] - (dep1[x] - dep1[fa[top[x]]]);
				lastx = w[top[x]];
				x = fa[top[x]];
			}
			else{
				ans += sum[dfn[y]] - sum[dfn[top[y]] - 1] - lasty + w[son[y]] - (dep2[y] - dep2[fa[top[y]]]);
				lasty = w[top[y]];
				y = fa[top[y]];
			}
		}
		if(dep[x] > dep[y]){
			ans += sum[dfn[x]] - sum[dfn[y] - 1] - lastx - lasty + w[son[x]] - (dep1[x] - dep1[y]);
			ans += w_[y];
		}
		else{
			ans += sum[dfn[y]] - sum[dfn[x] - 1] - lastx - lasty + w[son[y]] - (dep2[y] - dep2[x]);
			ans += w_[x];
		}
		printf("%d\n", ans);
	}
	return 0;
}