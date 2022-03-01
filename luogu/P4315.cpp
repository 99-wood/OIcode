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
const int MAXN = 100010;
vector<int> tree[MAXN];
int tim = 0;
int siz[MAXN], id[MAXN], dfn[MAXN], son[MAXN], fa[MAXN], top[MAXN], dep[MAXN];
int w[MAXN];
void dfs1(int p, int f){
	siz[p] = 1;
	fa[p] = f;
	int maxx = 0;
	frep(i,0,tree[p].size()){
		int x = tree[p][i];
		if(x == fa[p]) continue;
		dfs1(x,p);
		siz[p] += siz[x];
		if(siz[x] > maxx){
			son[p] = x;
			maxx = siz[x];
		}
	}
	return;
}
void dfs2(int p){
	dfn[p] = ++tim;
	id[dfn[p]] = p;
	dep[p] = dep[fa[p]] + 1;
	if(son[p]){
		top[son[p]] = top[p];
		dfs2(son[p]);
	}
	frep(i,0,tree[p].size()){
		int x = tree[p][i];
		if(x == fa[p] || x == son[p]) continue;
		dfs2(x);
	}
	return;
}

int a[MAXN << 2], b[MAXN << 2], c[MAXN << 2]; //jia genggai
void build(int p, int l, int r){
	if(l == r){
		a[p] = w[id[l]];
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	a[p] = max(a[ls], a[rs]);
	return;
}
void pushdown(int p, int l, int r){
	if(c[p] != -1){
		a[ls] = a[rs] = c[p];
		b[ls] = b[rs] = 0;
		c[ls] = c[rs] = c[p];
		c[p] = -1;
	}
	else{
		a[ls] += b[p];
		a[rs] += b[p];
		if(c[ls] != -1) c[ls] += b[p];
		else b[ls] += b[p];
		if(c[rs] != -1) c[rs] += b[p];
		else b[rs] += b[p];
		b[p] = 0;	
	}
	return;
}
void modify(int p, int l, int r, int x, int y, int w){
	if(x <= l && y >= r){
		if(c[p] != -1){
			c[p] += w;
			a[p] = c[p];
		}
		else{
			b[p] += w;
			a[p] += w;	
		}
		return;
	}
	if(x > r || y < l) return;
	pushdown(p, l, r);
	modify(ls, l, mid, x, y, w);
	modify(rs, mid + 1, r, x, y, w);
	a[p] = max(a[ls], a[rs]);
	return;
}
void change(int p, int l, int r, int x, int y, int w){
	if(x <= l && y >= r){
		b[p] = 0;
		a[p] = c[p] = w;
		return;
	}
	if(x > r || y < l) return;
	pushdown(p, l, r);
	change(ls, l, mid, x, y, w);
	change(rs, mid + 1, r, x, y, w);
	a[p] = max(a[ls], a[rs]);
	return;
}
int getmax(int p, int l, int r, int x, int y){
	if(x <= l && y >= r){
		return a[p];
	}
	if(x > r || y < l) return 0;
	pushdown(p, l, r);
	return max(getmax(ls, l, mid, x, y), getmax(rs, mid + 1, r, x, y));
}
struct L{
	int x, y, z;
}line[MAXN];
int main(){
	memset(c, -1, sizeof(c));
	int n = read();
	rep(i,1,n){
		top[i] = i;
	}
	frep(i,1,n){
		line[i].x = read(), line[i].y = read(), line[i].z = read();
		tree[line[i].x].push_back(line[i].y);
		tree[line[i].y].push_back(line[i].x);
	}
	dfs1(1,0);
	dfs2(1);
	frep(i,1,n){
		w[dep[line[i].x] > dep[line[i].y] ? line[i].x : line[i].y] = line[i].z;
	}
	build(1, 1, n);
	while(true){
		bool flag = false;
		char op[10];
		scanf("\n%s", op);
		switch(op[0] + op[1]){
			case 'A' + 'd' :{
				int x = read(), y = read(), w = read();
				while(top[x] != top[y]){
					if(dep[top[x]] < dep[top[y]]) swap(x, y);
					modify(1, 1, n, dfn[top[x]], dfn[x], w);
					x = fa[top[x]];
				}
				if(dep[x] < dep[y]) swap(x, y);
				modify(1, 1, n, dfn[son[y]], dfn[x], w);
				break;
			}
			case 'C' + 'h' :{
				int x = read(), w = read();
				change(1, 1, n, dfn[dep[line[x].x] > dep[line[x].y] ? line[x].x : line[x].y], dfn[dep[line[x].x] > dep[line[x].y] ? line[x].x : line[x].y], w);
				break;
			}
			case 'C' + 'o' :{
				int x = read(), y = read(), w = read();
				while(top[x] != top[y]){
					if(dep[top[x]] < dep[top[y]]) swap(x, y);
					change(1, 1, n, dfn[top[x]], dfn[x], w);
					x = fa[top[x]];
				}
				if(dep[x] < dep[y]) swap(x, y);
				change(1, 1, n, dfn[son[y]], dfn[x], w);
				break;
			}
			case 'M' + 'a' :{
				int x = read(), y = read();
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
			case 'S' + 't' :{
				flag = true;
				break;
			}
		}
		if(flag) break;
	}
	return 0;
}