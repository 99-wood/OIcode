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
#define ls tree[p].l
#define rs tree[p].r
#define mid ((l + r) >> 1)
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
const int MAXN = 5010;
const int MAXM = 100010;
const int INF = 0x3f3f3f3f;
int n, m, s, t, d;
int nxt[MAXM], to[MAXM], cap[MAXM], cost[MAXM], head[MAXN], now[MAXN], endd = -1;
void add(int x, int y, int f, int w){
	++endd;
	nxt[endd] = head[x];
	to[endd] = y;
	cap[endd] = f;
	cost[endd] = w;
	head[x] = endd;
	now[x] = endd;
	return;
}
int dis[MAXN];
bool vis[MAXN];
queue<int> q;
int ans;
bool SPFA(){
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	dis[s] = 0;
	q.push(s);
	vis[s] = true;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		vis[p] = false;
		for(int i = head[p]; i != -1; i = nxt[i]){
			int x = to[i];
			if(cap[i] && dis[p] + cost[i] < dis[x]){
				dis[x] = dis[p] + cost[i];
				if(!vis[x]){
					q.push(x);
					vis[x] = true;
				}
			}
		}
	}
	return dis[t] != INF;
}
int dfs(int p, int flow){
	if(p == t) return flow;
	vis[p] = true;
	int re = 0;
	for(int i = now[p]; i != -1 && flow - re; i = nxt[i]){
		int x = to[i];
		if(!vis[x] && cap[i] && dis[x] == dis[p] + cost[i]){
			int f = dfs(x, min(flow - re, cap[i]));
			cap[i] -= f;
			cap[i ^ 1] += f;
			ans += cost[i] * f;
			re += f;
		}
	}
	vis[p] = false;
	return re;
}
void solve(){
	while(SPFA()){
		memcpy(now, head, sizeof(now));
		d += dfs(s, INF);
	}
}
int main(){
//	freopen("P3381_8.in","r",stdin);
	memset(head, -1, sizeof(head));
	n = read(), m = read(), s = read(), t = read();
	rep(i, 1, m){
		int x = read(), y = read(), f = read(), w = read();
		add(x, y, f, w);
		add(y, x, 0, -w);
	}
	solve();
	printf("%d %d", d, ans);
	return 0;
}
