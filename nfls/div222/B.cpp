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
int s[MAXN], pp[MAXN];
int n;
int root[MAXN];
int dep[MAXN], dfn[MAXN], d[MAXN], siz[MAXN], son[MAXN], top[MAXN], fa[MAXN], id[MAXN], endd;
ll dis[MAXN], sumdis[MAXN];
struct edge{
	int to, w;
};
int end1;
struct node{
	int l, r, tag;
	ll w;
}tree[MAXN * 190];
#define ls tree[p].l
#define rs tree[p].r
#define mid ((l + r) >> 1)
int clone(int p){
	tree[++end1] = tree[p];
	return end1;
}
void build(int p, int l, int r){
	if(l == r) return;
	ls = ++end1;
	rs = ++end1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	return;
}
void pushdown(int p, int l, int r){
	ls = clone(ls);
	rs = clone(rs);
	tree[ls].tag += tree[p].tag;
	tree[rs].tag += tree[p].tag;
	tree[ls].w += (dis[id[mid]] - dis[fa[id[l]]]) * tree[p].tag;
	tree[rs].w += (dis[id[r]] - dis[fa[id[mid + 1]]]) * tree[p].tag;
	tree[p].tag = 0;
	return;
}
int modify(int p, int l, int r, int x, int y, int w){
	p = clone(p);
	if(x <= l && r <= y){
		tree[p].tag += w;
		tree[p].w += (dis[id[r]] - dis[fa[id[l]]]) * w;
		return p;
	}
	pushdown(p, l, r);
	if(y <= mid) ls = modify(ls, l, mid, x, y, w);
	else if(x > mid) rs = modify(rs, mid + 1, r, x, y, w);
	else{
		ls = modify(ls, l, mid, x, y, w);
		rs = modify(rs, mid + 1, r, x, y, w);
	}
	tree[p].w = tree[ls].w + tree[rs].w;
	return p;
}
ll query(int p, int l, int r, int x, int y){
	if(x <= l && r <= y){
		return tree[p].w;
	}
	pushdown(p, l, r);
	if(y <= mid) return query(ls, l, mid, x, y);
	else if(x > mid) return query(rs, mid + 1, r, x, y);
	else return query(ls, l, mid, x, y) + query(rs, mid + 1, r, x, y);
}
vector<struct edge> nxt[MAXN];
void dfs1(int p, int f){
	fa[p] = f;
	dep[p] = dep[fa[p]] + 1;
	siz[p] = 1;
	for(auto x : nxt[p]){
		if(x.to == fa[p]) continue;
		dis[x.to] = dis[p] + x.w;
		dfs1(x.to, p);
		if(siz[son[p]] < siz[x.to]) son[p] = x.to;
		siz[p] += siz[x.to];
	}
	return;
}
void dfs2(int p){
	dfn[p] = ++endd;
	id[dfn[p]] = p;
	pp[dfn[p]] = s[p];
	sumdis[dfn[p]] = sumdis[dfn[p] - 1] + dis[s[p]];
	if(son[p]){
		top[son[p]] = top[p];
		dfs2(son[p]);
	}
	for(auto x : nxt[p]){
		if(x.to == fa[p] || x.to == son[p]) continue;
		dfs2(x.to);
	}
	return;
}
ll ask(int x, int y, int p){
	ll ans = 0;
	while(p){
		ans += query(root[y], 1, n, dfn[top[p]], dfn[p]) - query(root[x - 1], 1, n, dfn[top[p]], dfn[p]);
		p = fa[top[p]];
	}
	return ans;
}
int main(){
	freopen("dis.in", "r", stdin);
	freopen("dis.out", "w", stdout);
	int ty = read();
	n = read();
	int q = read();
	frep(i, 1, n){
		int x = read(), y = read(), w = read();
		nxt[x].push_back(edge{y, w});
		nxt[y].push_back(edge{x, w});
	}
	rep(i, 1, n){
		s[i] = read();
		top[i] = i;
	}
	dfs1(1, 0);
	dfs2(1);
	build(1, 1, n);
	rep(i, 1, n){
		root[i] = root[i - 1];
		int p = pp[i];
		while(p){
			root[i] = modify(root[i], 1, n, dfn[top[p]], dfn[p], 1);
			p = fa[top[p]];
		}
	}
	ll ans = 0;
	while(q--){
		int x = read() ^ (ans * ty), y = read() ^ (ans * ty), z = read() ^ (ans * ty);
		ans = 0;
		while(top[x] != top[y]){
			if(dep[top[x]] < dep[top[y]]) swap(x, y);
			ans += sumdis[dfn[x]] - sumdis[dfn[top[x]] - 1] + dis[z] * (dfn[x] - dfn[top[x]] + 1) - ask(dfn[x], dfn[top[x]], z) * 2;
			x = fa[top[x]];
		}
		if(dep[x] < dep[y]) swap(x, y);
		ans += sumdis[dfn[x]] - sumdis[dfn[y] - 1] + dis[z] * (dfn[x] - dfn[y] + 1) - ask(dfn[x], dfn[y], z) * 2;
		printf("%lld\n", ans);
	}
	return 0;
}