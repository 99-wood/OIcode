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
#define tmp(a, b) (tmp[a] >> (n - (b)) & 1)
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

struct node{
	int p;
	ll w;
	node(int p, ll w) : p(p), w(w){}
	node() : p(), w(){}
};
bool cmp(struct node a, struct node b){
	return a.w < b.w;
}
const int MAXN = 300010;
int n, m;
ll ans = 1e18;
int fa[MAXN][50];
ll dep[MAXN];
int pos[MAXN];
bool cnt[MAXN];
int endd, endd_, minn[MAXN];
struct node lib[MAXN], req[MAXN];
bool vis[MAXN];
vector<struct node> tree[MAXN];
struct node now[MAXN];
void inil(int p, int f){
	fa[p][0] = f;
	for(int k = 0; fa[fa[p][k]][k]; ++k){
		fa[p][k + 1] = fa[fa[p][k]][k];
	}
	frep(i, 0, tree[p].size()){
		struct node x = tree[p][i];
		if(x.p == fa[p][0]) continue;
		dep[x.p] = dep[p] + x.w;
		inil(x.p, p);
	}
	return;
}
struct node findfa(int p, ll w){
	for(int k = 45; k >= 0; --k){
		if(fa[p][k] == 1 || fa[p][k] == 0 || w - (dep[p] - dep[fa[p][k]]) < 0) continue;
		w -= (dep[p] - dep[fa[p][k]]);
		p = fa[p][k];
	}
	return node(p, w);
}
bool dfs(int p){
	if(cnt[p]) return true;
	if(fa[p][0] == 1 && tree[p].size() == 1){
		req[++endd] = node(p, dep[p]);
		return false;
	}
	if(tree[p].size() == 1 && p != 1) return false;
	if(fa[p][0] == 1){
		frep(i, 0, tree[p].size()){
			struct node x = tree[p][i];
			if(x.p == fa[p][0]) continue;
			if(!dfs(x.p)){
				req[++endd] = node(p, dep[p]);
				return false;
			}
		}
		return true;
	}
	else{
		frep(i, 0, tree[p].size()){
			struct node x = tree[p][i];
			if(x.p == fa[p][0]) continue;
			if(!dfs(x.p) && p != 1) return false;
		}
		return true;
	}
}
bool check(ll w){
	memset(cnt, 0, sizeof(cnt));
	memset(vis, 0, sizeof(vis));
	memset(minn, 0, sizeof(minn));
	endd_ = 0;
	endd = 0;
	rep(i, 1, m){
		now[i] = findfa(pos[i], w);
		if(now[i].w - dep[now[i].p] > 0){
			if(!minn[now[i].p] || now[minn[now[i].p]].w > now[i].w) minn[now[i].p] = i;
			lib[++endd_] = node(i, now[i].w - dep[now[i].p]);
		}
		else{
			cnt[now[i].p] = true;
		}
	}
	dfs(1);
	sort(lib + 1, lib + 1 + endd_, cmp);
	sort(req + 1, req + 1 + endd, cmp);
	while(endd){
		if(!minn[req[endd].p] || vis[minn[req[endd].p]]){
			while(vis[lib[endd_].p]) --endd_;
			if(lib[endd_].w >= req[endd].w){
				vis[lib[endd_].p] = true;
				--endd_;
			}
			else return false;
		}
		else{
			vis[minn[req[endd].p]] = true;
		}
		--endd;
	}
	return true;
}
void solve(){
	ll l = 0, r = 1e15;
	while(l <= r){
		ll m = (l + r) >> 1;
		if(check(m)){
			ans = m;
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	return;
}
int main(){
	n = read();
	frep(i, 1, n){
		int x = read(), y = read(), w = read();
		struct node a;
		a.w = w;
		a.p = y;
		tree[x].push_back(a);
		a.p = x;
		tree[y].push_back(a);
	}
	inil(1, 0);
	m = read();
	rep(i, 1, m){
		pos[i] = read();
	}
	solve();
	if(ans == 1e18) printf("-1");
	else printf("%lld", ans);
	return 0;
}