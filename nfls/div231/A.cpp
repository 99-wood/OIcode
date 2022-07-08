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

int n;
struct T{
	ll m[2][2];
	T(){
		m[0][0] = m[0][1] = m[1][0] = m[1][1] = 0;
		return;
	}
	T(ll a, ll b, ll c, ll d){
		m[0][0] = a;
		m[0][1] = b;
		m[1][0] = c;
		m[1][1] = d;
		return;
	}
	struct T operator * (struct T b){
		struct T tmp;
		tmp.m[0][0] = min(m[0][0] + b.m[0][0], m[1][0] + b.m[0][1]);
		tmp.m[1][0] = min(m[0][0] + b.m[1][0], m[1][0] + b.m[1][1]);
		tmp.m[0][1] = min(m[0][1] + b.m[0][0], m[1][1] + b.m[0][1]);
		tmp.m[1][1] = min(m[0][1] + b.m[1][0], m[1][1] + b.m[1][1]);
		return tmp;
	}
}tree[MAXN << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
void modify(int p, int l, int r, int x, struct T w){
	if(l == r){
		tree[p] = w;
		return;
	}
	if(x <= mid) modify(ls, l, mid, x, w);
	else modify(rs, mid + 1, r, x, w);
	tree[p] = tree[rs] * tree[ls];
	return;
}
struct T query(int p, int l, int r, int x, int y){
	if(x <= l && r <= y) return tree[p];
	if(y <= mid) return query(ls, l, mid, x, y);
	else if(x > mid) return query(rs, mid + 1, r, x, y);
	else return query(rs, mid + 1, r, x, y) * query(ls, l, mid, x, y);
}
vector<int> nxt[MAXN];
ll f[MAXN], g[MAXN], a[MAXN];
int siz[MAXN], dfn[MAXN], id[MAXN], dep[MAXN], top[MAXN], tail[MAXN], son[MAXN], fa[MAXN], end1;
void dfs1(int p, int ff){
	fa[p] = ff;
	siz[p] = 1;
	dep[p] = dep[fa[p]] + 1;
	ll sum = 0;
	for(auto x : nxt[p]){
		if(x == fa[p]) continue;
		dfs1(x, p);
		sum += f[x];
		if(siz[x] > siz[son[p]]) son[p] = x;
		siz[p] += siz[x];
	}
	if(!son[p]) f[p] = a[p];
	else f[p] = min(sum, a[p]);
	return;
}
void dfs2(int p){
	dfn[p] = ++end1;
	id[dfn[p]] = p;
	tail[top[p]] = p;
	if(son[p]){
		top[son[p]] = top[p];
		dfs2(son[p]);
	}
	for(auto x : nxt[p]){
		if(x == fa[p] || x == son[p]) continue;
		dfs2(x);
		g[p] += f[x];
	}
	modify(1, 1, n, dfn[p], T(g[p], a[p], 1e17, 0));
	return;
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n = read();
	rep(i, 1, n) top[i] = i;
	rep(i, 1, n) a[i] = read();
	frep(i, 1, n){
		int x = read(), y = read();
		nxt[x].push_back(y);
		nxt[y].push_back(x);
	}
	dfs1(1, 0);
	dfs2(1);
	int m = read();
	rep(i, 1, m){
		char c;
		scanf("\n%c", &c);
		if(c == 'Q'){
			int p = read();
			struct T tmp = query(1, 1, n, dfn[p], dfn[tail[top[p]]]);
			printf("%lld\n", tmp.m[0][1]);
		}
		else{
			int p = read(), x = read();
			a[p] += x;
			while(p){
				struct T last = query(1, 1, n, dfn[top[p]], dfn[tail[top[p]]]);
				modify(1, 1, n, dfn[p], T(g[p], a[p], 1e17, 0));
				struct T now = query(1, 1, n, dfn[top[p]], dfn[tail[top[p]]]);
				g[fa[top[p]]] += now.m[0][1] - last.m[0][1];
				p = fa[top[p]];
			}
		}
	}
	return 0;
}
