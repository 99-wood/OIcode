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
	while(c>='0'&&c<='9'){
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}
const int MAXN = 2e5;
const int INF = 0x3f3f3f3f;
struct Matrix{
	int c[2][2];
	struct Matrix operator * (Matrix b){
		Matrix tmp;
		tmp.c[0][0] = max(c[0][0] + b.c[0][0], c[0][1] + b.c[1][0]);
		tmp.c[0][1] = max(c[0][0] + b.c[0][1], c[0][1] + b.c[1][1]);
		tmp.c[1][0] = max(c[1][0] + b.c[0][0], c[1][1] + b.c[1][0]);
		tmp.c[1][1] = max(c[1][0] + b.c[0][1], c[1][1] + b.c[1][1]);
		return tmp;
	}
};

vector<int> nxt[MAXN];
int a[MAXN], f[MAXN][2];
struct Matrix tree[MAXN], g[MAXN];
int siz[MAXN], dfn[MAXN], id[MAXN], dep[MAXN], top[MAXN], tail[MAXN], son[MAXN], fa[MAXN], end1;
void dfs1(int p, int ff){
	fa[p] = ff;
	siz[p] = 1;
	dep[p] = dep[fa[p]] + 1;
	f[p][1] = a[p];
	int maxx = 0;
	for(auto x : nxt[p]){
		if(x == fa[p]) continue;
		dfs1(x, p);
		siz[p] += siz[x];
		if(siz[x] > maxx){
			maxx = siz[x];
			son[p] = x;
		}
		f[p][1] += f[x][0];
		f[p][0] += max(f[x][0], f[x][1]);
	}
	return;
}
void dfs2(int p){
	dfn[p] = ++end1;
	id[end1] = p;
	if(!top[p]) top[p] = p;
	tail[p] = p;
	g[p].c[0][1] = a[p];
	g[p].c[1][1] = -INF;
	if(son[p]){
		top[son[p]] = top[p];
		dfs2(son[p]);
		tail[p] = tail[son[p]];
	}
	else return;
	for(auto x : nxt[p]){
		if(x == son[p] || x == fa[p]) continue;
		dfs2(x);
		g[p].c[0][0] += max(f[x][0], f[x][1]);
		g[p].c[0][1] += f[x][0];
	}
	g[p].c[1][0] = g[p].c[0][0];
	return;
}
void build(int p, int l, int r){
	if(l == r){
		tree[p] = g[id[l]];
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	tree[p] = tree[rs] * tree[ls];
	return;
}
void modify(int p, int l, int r, int x){
	if(l == r){
		tree[p] = g[x];
		return;
	}
	if(dfn[x] <= mid) modify(ls, l, mid, x);
	else modify(rs, mid + 1, r, x);
	tree[p] = tree[rs] * tree[ls];
	return;
}
struct Matrix query(int p, int l, int r, int x, int y){
	if(x <= l && r <= y) return tree[p];
	if(y <= mid) return query(ls, l, mid, x, y);
	else if(x > mid) return query(rs, mid + 1, r, x, y);
	else return query(rs, mid + 1, r, x, y) * query(ls, l, mid, x, y);
}
int main(){
	int n = read(), m = read();
	rep(i, 1, n) a[i] = read();
	frep(i, 1, n){
		int x = read(), y = read();
		nxt[x].push_back(y);
		nxt[y].push_back(x);
	}
	dfs1(1, 0);
	dfs2(1);
	build(1, 1, n);
	rep(i, 1, m){
		int x = read(), w = read();
		g[x].c[0][1] += w - a[x];
		a[x] = w;
		while(x){
			struct Matrix last, now;
			last = query(1, 1, n, dfn[top[x]], dfn[tail[top[x]]]);
			modify(1, 1, n, x);
			now = query(1, 1, n, dfn[top[x]], dfn[tail[top[x]]]);
			x = fa[top[x]];
			g[x].c[0][1] += now.c[0][0] - last.c[0][0];
			g[x].c[0][0] += max(now.c[0][0], now.c[0][1]) - max(last.c[0][0], last.c[0][1]);
			g[x].c[1][0] = g[x].c[0][0];
		}
		Matrix ans = query(1, 1, n, 1, dfn[tail[1]]);
		printf("%d\n", max(ans.c[0][0], ans.c[0][1]));
	}
	return 0;
}