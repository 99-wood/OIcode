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
const int MAXN = 500010;
vector<int> tree[MAXN];
int tim = 0;
int siz[MAXN], id[MAXN], dfn[MAXN], son[MAXN], fa[MAXN], top[MAXN], dep[MAXN];
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
int a[MAXN], b[MAXN]; //bai hei
void build(int p, int l, int r){
	a[p] = l;
	if(l == r) return;
	build(ls, l, mid);
	build(rs, mid + 1, r);
}
void modify(int p, int l, int r, int x){
	if(l == r){
		swap(a[p], b[p]);
		return;
	}
	if(x <= mid) modify(ls, l, mid, x);
	else modify(rs, mid + 1, r, x);
	a[p] = min(a[ls], a[rs]);
	b[p] = min(b[ls], b[rs]);
	return;
}
int query(int p, int l, int r, int x, int y){
	if(x <= l && y >= r){
		return b[p];
	}
	if(x > r || y < l) return 0x7f7f7f7f;
	return min(query(ls, l, mid, x, y), query(rs, mid + 1, r, x, y));
}
int main(){
	memset(b, 0x7f, sizeof(b));
	int n = read(), m = read();
	rep(i,1,n){
		top[i] = i;
	}
	frep(i,1,n){
		int x = read(), y = read();
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1);
	build(1, 1, n);
	while(m--){
		int op = read();
		switch(op){
			case 0 :{
				int x = read();
				modify(1, 1, n, dfn[x]);
				break;
			}
			case 1 :{
				int x = read();
				bool flag = true;
				int ans = -1;
				while(x){
					int re = query(1, 1, n, dfn[top[x]], dfn[x]);
					if(re != 0x7f7f7f7f) ans = id[re];
					x = fa[top[x]];
				}
				printf("%d\n", ans);
				break;
			}
		}
	}
	return 0;
}