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
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define mid ((l + r) >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)
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
	while(c>='0'&&c<='9') {
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}
const int MAXN = 200010;
vector<int> tree[MAXN];
int tim = 0;
int siz[MAXN], id[MAXN], dfn[MAXN], son[MAXN], fa[MAXN], top[MAXN], dep[MAXN];
int w[MAXN];
struct node{
	int p, f;
	node(int p, int f) : p(p), f(f){}
	node() : p(0), f(0){}
}stac[MAXN];
int vis[MAXN], endd;
void dfs1(){
	stac[++endd] = node(1, 0);
	while(endd){
		int p = stac[endd].p;
		int f = stac[endd].f;
		if(dep[p]){
			int maxx = 0;
			frep(i,0,tree[p].size()){
				int x = tree[p][i];
				if(x == fa[p]) continue;
				siz[p] += siz[x];
				if(siz[x] > maxx){
					son[p] = x;
					maxx = siz[x];
				}
			}
			--endd;
		}
		else{
			fa[p] = f;
			dep[p] = dep[fa[p]] + 1;
			siz[p] = 1;
			frep(i,0,tree[p].size()){
				int x = tree[p][i];
				if(x == fa[p]) continue;
				stac[++endd] = node(x, p);
			}
		}
	}
	return;
}
void dfs2(){
	++endd;
	stac[endd] = node(1, 0);
	while(endd){
		int p = stac[endd].p;
		int f = stac[endd].f;
		++vis[p];
		if(vis[p] == 1){
			dfn[p] = ++tim;
			id[dfn[p]] = p;
			if(son[p]){
				top[son[p]] = top[p];
				stac[++endd] = node(son[p], p);
			}
		}
		else if(vis[p] == 2){
			frep(i,0,tree[p].size()){
				int x = tree[p][i];
				if(x == fa[p] || x == son[p]) continue;
				stac[++endd] = node(x, p);
			}
		}
		else{
			--endd;
		}
	}
	return;
}
int a[MAXN << 2], b[MAXN << 2], c[MAXN << 2]; // sum max min
bool tag[MAXN];
void build(int p, int l, int r){
	if(l == r){
		b[p] = a[p] = c[p] = w[id[l]];
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	a[p] = a[ls] + a[rs];
	b[p] = max(b[ls], b[rs]);
	c[p] = min(c[ls], c[rs]);
	return;
}
void pushdown(int p, int l, int r){
	if(tag[p]){
		tag[ls] ^= 1;
		tag[rs] ^= 1;
		a[ls] = -a[ls];
		b[ls] = -b[ls];
		c[ls] = -c[ls];
		swap(b[ls], c[ls]);
		a[rs] = -a[rs];
		b[rs] = -b[rs];
		c[rs] = -c[rs];
		swap(b[rs], c[rs]);
		tag[p] = false;
	}
	return;
}
void modify(int p, int l, int r, int x, int w){
	if(l == r){
		a[p] = b[p] = c[p] = w;
		return;
	}
	pushdown(p, l, r);
	if(x <= mid) modify(ls, l, mid, x, w);
	else modify(rs, mid + 1, r, x, w);
	a[p] = a[ls] + a[rs];
	b[p] = max(b[ls], b[rs]);
	c[p] = min(c[ls], c[rs]);
	return;
}
void change(int p, int l, int r, int x, int y){
	if(x <= l && y >= r){
		tag[p] ^= 1;
		a[p] = -a[p];
		b[p] = -b[p];
		c[p] = -c[p];
		swap(b[p], c[p]);
		return;
	}
	if(x > r || y < l) return;
	pushdown(p, l, r);
	change(ls, l, mid, x, y);
	change(rs, mid + 1, r, x, y);
	a[p] = a[ls] + a[rs];
	b[p] = max(b[ls], b[rs]);
	c[p] = min(c[ls], c[rs]);
	return;
}
int getsum(int p, int l, int r, int x, int y){
	if(x <= l && y >= r){
		return a[p];
	}
	if(x > r || y < l) return 0;
	pushdown(p, l, r);
	return getsum(ls, l, mid, x, y) + getsum(rs, mid + 1, r, x, y);
}
int getmax(int p, int l, int r, int x, int y){
	if(x <= l && y >= r){
		return b[p];
	}
	if(x > r || y < l) return -1000000;
	pushdown(p, l, r);
	return max(getmax(ls, l, mid, x, y), getmax(rs, mid + 1, r, x, y));
}
int getmin(int p, int l, int r, int x, int y){
	if(x <= l && y >= r){
		return c[p];
	}
	if(x > r || y < l) return 1000000;
	pushdown(p, l, r);
	return min(getmin(ls, l, mid, x, y), getmin(rs, mid + 1, r, x, y));
}
struct L{
	int x, y, w;
}line[MAXN];
int main(){
	int n = read();
	frep(i,1,n){
		line[i].x = read(), line[i].y = read(), line[i].w = read();
		tree[line[i].x].push_back(line[i].y);
		tree[line[i].y].push_back(line[i].x);
	}
	rep(i,1,n){
		top[i] = i;
	}
	dfs1();
	dfs2();
	frep(i,1,n){
		w[dep[line[i].x] < dep[line[i].y] ? line[i].y : line[i].x] = line[i].w;
	}
	build(1, 1, n);
	while(true){
		char op[10];
		memset(op,0,sizeof(op));
		scanf("\n%s", op);
		switch(op[0]){
			case 'C' :{
				int x = read(), w = read();
				modify(1, 1, n, dfn[dep[line[x].x] < dep[line[x].y] ? line[x].y : line[x].x], w);
				break;
			}
			case 'N' :{
				int x = read(), y = read();
				while(top[x] != top[y]){
					if(dep[top[x]] < dep[top[y]]) swap(x, y);
					change(1, 1, n, dfn[top[x]], dfn[x]);
					x = fa[top[x]];
				}
				if(dep[x] < dep[y]) swap(x, y);
				change(1, 1, n, dfn[son[y]], dfn[x]);
				break;
			}
			case 'S' :{
				int x = read(), y = read();
				int ans = 0;
				while(top[x] != top[y]){
					if(dep[top[x]] < dep[top[y]]) swap(x, y);
					ans += getsum(1, 1, n, dfn[top[x]], dfn[x]);
					x = fa[top[x]];
				}
				if(dep[x] < dep[y]) swap(x, y);
				ans += getsum(1, 1, n, dfn[son[y]], dfn[x]);
				printf("%d\n", ans);
				break;
			}
			case 'M' :{
				int x = read(), y = read();
				int ans = 1000000;
				while(top[x] != top[y]){
					if(dep[top[x]] < dep[top[y]]) swap(x, y);
					ans = min(ans, getmin(1, 1, n, dfn[top[x]], dfn[x]));
					x = fa[top[x]];
				}
				if(dep[x] < dep[y]) swap(x, y);
				ans = min(ans, getmin(1, 1, n, dfn[son[y]], dfn[x]));
				printf("%d\n", ans);
				break;
			}
			case 'Q' :{
				int x = read(), y = read();
				if(x == y){
					printf("0\n");
					break;
				}
				int ans = 0;
				while(top[x] != top[y]){
					if(dep[top[x]] < dep[top[y]]) swap(x, y);
					ans = max(ans, getmax(1, 1, n, dfn[top[x]], dfn[x]));
					x = fa[top[x]];
				}
				if(dep[x] < dep[y]) swap(x, y);
				ans = max(ans, getmax(1, 1, n, dfn[son[y]], dfn[x]));
				printf("%d\n", ans);
				break;
			}
			case 'D' :{
				return 0;
				break;
			}
		}
	}
	return 0;
}