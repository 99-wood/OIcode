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
#include<bitset>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
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
const int MAXN = 1e5 + 10;
int n, m;
struct node{
	int top, siz;
	struct node operator + (const struct node a){
		return node{top + a.top, siz + a.siz};
	}
}tree[MAXN << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
void pushdown(int p){
	if(tree[p].top){
		tree[ls].top = tree[p].top;
		tree[rs].top = tree[p].top;	
	}
	tree[ls].siz += tree[p].siz;
	tree[rs].siz += tree[p].siz;
	tree[p] = node{0, 0};
	return;
}
void mul(int p, int l, int r, int x, int y, int w){
	if(x <= l && r <= y){
		tree[p].siz += w;
		return;
	}
	if(r < x || y < l) return;
	pushdown(p);
	mul(ls, l, mid, x, y, w);
	mul(rs, mid + 1, r, x, y, w);
	return;
}
void modify(int p, int l, int r, int x, int y, int w){
	if(x <= l && r <= y){
		tree[p].top = w;
		return;
	}
	if(r < x || y < l) return;
	pushdown(p);
	modify(ls, l, mid, x, y, w);
	modify(rs, mid + 1, r, x, y, w);
	return;

}
struct node query(int p, int l, int r, int x){
	if(l == r) return tree[p];
	pushdown(p);
	if(x <= mid) return query(ls, l, mid, x);
	else return query(rs, mid + 1, r, x);
}
vector<int> nxt[MAXN];
int dfn[MAXN], son[MAXN], dep[MAXN], siz[MAXN], top[MAXN], fa[MAXN], id[MAXN], tail[MAXN], endd;
void dfs1(int p, int f){
	fa[p] = f;
	dep[p] = dep[fa[p]] + 1;
	siz[p] = 1;
	for(auto x : nxt[p]){
		if(x == fa[p]) continue;
		dfs1(x, p);
		if(siz[x] > siz[son[p]]) son[p] = x;
		siz[p] += siz[x];
	}
	return;
}
void dfs2(int p){
	dfn[p] = ++endd;
	tail[top[p]] = p;
	id[dfn[p]] = p;
	if(son[p]){
		top[son[p]] = top[p];
		dfs2(son[p]);
	}
	for(auto x : nxt[p]){
		if(x == fa[p] || x == son[p]) continue;
		dfs2(x);
	}
	return;
}
struct T{
	bool op;
	int x, y;
}q[MAXN];
ll ans[MAXN];
void init(){
	rep(i, 1, n) top[i] = i;
}
void build(int p, int l, int r){
	if(l == r){
		tree[p].siz = siz[id[l]];
		tree[p].top = top[id[l]];
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	return;
}
int main(){
	n = read(), m = read();
	init();
	rep(i, 1, m){
		char c;
		scanf("\n%c", &c);
		if(c == 'A') q[i].op = true;
		else q[i].op = false;
		q[i].x = read(), q[i].y = read();
		if(q[i].op){
			nxt[q[i].x].push_back(q[i].y);
			nxt[q[i].y].push_back(q[i].x);
		}
	}
	rep(i, 1, n){
		if(!fa[i]){
			dfs1(i, 0);
			dfs2(i);
		}
	}
	build(1, 1, n);
	drep(i, m, 1){
		int x = q[i].x, y = q[i].y;
		if(dep[x] > dep[y]) swap(x, y);
		if(q[i].op){
			fa[y] = 0;
			top[y] = query(1, 1, n, dfn[y]).top;
			top[x] = query(1, 1, n, dfn[x]).top;
			if(top[y] != y){
				modify(1, 1, n, dfn[y], dfn[y] + dep[tail[top[y]]] - dep[y], y);
				top[y] = y;
				tail[top[y]] = tail[top[x]];
				tail[top[x]] = x;
			}
			siz[y] = query(1, 1, n, dfn[y]).siz;
			while(x){
				top[x] = query(1, 1, n, dfn[x]).top;
				mul(1, 1, n, dfn[top[x]], dfn[x], -siz[y]);
				x = fa[top[x]];
			}
		}
		else{
			siz[y] = query(1, 1, n, dfn[y]).siz;
			top[x] = query(1, 1, n, dfn[x]).top;
			while(fa[top[x]]){
				x = fa[top[x]];
				top[x] = query(1, 1, n, dfn[x]).top;;
			}
			x = top[x];
			siz[x] = query(1, 1, n, dfn[x]).siz;
			ans[i] = 1LL * siz[y] * (siz[x] - siz[y]);
		}
	}
	rep(i, 1, m){
		if(ans[i]) printf("%lld\n", ans[i]);
	}
	return 0;
}