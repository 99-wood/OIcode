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
#define rep(i,a,b) for(int i = a; i <= (b); ++i)
#define frep(i,a,b) for(int i = a; i < (b); ++i)
#define drep(i,a,b) for(int i = a; i >= (b); --i)
#define Maxq priority_queue<int,vector<int>,greater<int> >
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
typedef long long ll;
typedef unsigned long long ull;
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
	while(c>='0'&&c<='9') {
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}

const int MAXN = 100010;

vector<int> tree[MAXN];
struct node{
	int w, l, r;
	node(int w, int l, int r): w(w), l(l), r(r){}
	node(): w(0), l(0), r(0){}
}w[MAXN << 2];
int fa[MAXN], siz[MAXN], dfn[MAXN], id[MAXN], dep[MAXN], son[MAXN], top[MAXN], color[MAXN];
int tim;
void dfs1(int p, int f){
	fa[p] = f;
	siz[p] = 1;
	dep[p] = dep[fa[p]] + 1;
	int maxx = 0;
	frep(i,0,tree[p].size()){
		int x = tree[p][i];
		if(x == fa[p]) continue;
		dfs1(x, p);
		if(siz[x] > maxx){
			maxx = siz[x];
			son[p] = x;
		}
		siz[p] += siz[x];
	}
	return;
}
void dfs2(int p){
	dfn[p] = ++tim;
	id[dfn[p]] = p;
	if(son[p]){
		top[son[p]] = top[p];
		dfs2(son[p]);
	}
	frep(i,0,tree[p].size()){
		int x = tree[p][i];
		if(x == son[p] || x == fa[p]) continue;
		dfs2(x);
	}
	return;
}
void pushdown(int p, int l, int r){
	if(w[p].w > 1) return;
	int m = (l + r) >> 1;
	w[ls(p)] = node(1, w[p].l, w[p].l);
	w[rs(p)] = node(1, w[p].r, w[p].r);
	return;
}
void build(int p, int l, int r){
	if(l == r){
		w[p] = node(1, color[id[l]], color[id[l]]);
		return;
	}
	int m = (l + r) >> 1;
	build(ls(p), l, m);
	build(rs(p), m + 1, r);
	w[p] = node(w[ls(p)].w + w[rs(p)].w - (w[ls(p)].r == w[rs(p)].l), w[ls(p)].l, w[rs(p)].r);
	return;
}
void modify(int p, int l, int r, int x, int y, int v){
	if(x <= l && r <= y){
		w[p] = node(1, v, v);
		return;
	}
	if(y < l || x > r) return;
	pushdown(p,l,r);
	int m = (l + r) >> 1;
	modify(ls(p), l, m, x, y, v);
	modify(rs(p), m + 1, r, x, y, v);
	w[p] = node(w[ls(p)].w + w[rs(p)].w - (w[ls(p)].r == w[rs(p)].l), w[ls(p)].l, w[rs(p)].r);
	return;
}
struct node getsum(int p, int l, int r, int x, int y){
	if(x <= l && r <= y) return w[p];
	if(y < l || x > r) return node(0, -1, -1);
	pushdown(p,l,r);
	int m = (l + r) >> 1;
	struct node la = getsum(ls(p), l, m, x, y), ra = getsum(rs(p), m + 1, r, x, y);
	return  node(la.w + ra.w - (la.r == ra.l), la.l == -1 ? ra.l : la.l, ra.r == -1 ? la.r : ra.r);
}
int main(){
	int n = read(), q = read();
	rep(i,1,n){
		top[i] = i;
		color[i] = read();
	}
	rep(i,2,n){
		int x = read(), y = read();
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs1(1, 0);
	dfs2(1);
	build(1,1,n);
	while(q--){
		char op;
		scanf("\n%c",&op);
		if(op == 'C'){
			int x = read(), y = read(), c = read();
			while(top[x] != top[y]){
				if(dep[top[x]] < dep[top[y]]) swap(x, y);
				modify(1, 1, n, dfn[top[x]], dfn[x], c);
				x = fa[top[x]];
			}
			if(dep[x] < dep[y]) swap(x, y);
				modify(1, 1, n, dfn[y], dfn[x], c);
		}
		else{
			int ans = 0;
			int x = read(), y = read();
			int lx = -1, ly = -1;
			while(top[x] != top[y]){
				if(dep[top[x]] < dep[top[y]]){
					swap(x, y);
					swap(lx, ly);
				}
				struct node res = getsum(1, 1, n, dfn[top[x]], dfn[x]);
				ans += res.w - (res.r == lx);
				lx = res.l;
				x = fa[top[x]];
			}
			if(dep[x] < dep[y]){
				swap(x, y);
				swap(lx, ly);
			}
			struct node res = getsum(1, 1, n, dfn[y], dfn[x]);
			ans += res.w - (res.l == ly) - (res.r == lx);
			printf("%d\n", ans);
		}
	}
	return 0;
}