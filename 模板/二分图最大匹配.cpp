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
const int MAXN = 1100;
const int MAXM = 5e5;
const int INF = (~(1 << 31));
int n, m, s, t;
int nxt[MAXM], to[MAXM], w[MAXM], head[MAXN], now[MAXN], endd = -1;
void add(int x, int y, int v){
	++endd;
	nxt[endd] = head[x];
	to[endd] = y;
	w[endd] = v;
	head[x] = endd;
	now[x] = endd;
	return;
}
int dep[MAXN], cnt[MAXN];
ll maxflow;
int dfs(int p, int flow){
	if(p == t){
		maxflow += flow;
		return flow;
	}
	int re = 0;
	for(; now[p] != -1; now[p] = nxt[now[p]]){
		int x = to[now[p]];
		if(!w[now[p]] || dep[x] != dep[p] - 1) continue;
		int use = dfs(x, min(w[now[p]], flow));
		w[now[p]] -= use;
		w[now[p] ^ 1] += use;
		re += use;
		flow -= use;
		if(!flow) break;
	}
	if(flow){
		cnt[dep[p]]--;
		if(!cnt[dep[p]]) dep[s] = n;
		dep[p]++;
		cnt[dep[p]]++;
		now[p] = head[p];
	}
	return re;
}
void ISAP(){
	while(dep[s] < n) dfs(s, INF);
}
int main(){
	memset(head, -1, sizeof(head));
	int x = read(), y = read();
	n = x + y + 2, m = read(), s = 1, t = x + y + 1 + 1;
	cnt[0] = n;
	s = 0, t = n + 1;
	rep(i, 1, m){
		int u = read() + 1, v = read() + x + 1;
		add(u, v, 1);
		add(v, u, 0);
	}
	rep(i, 2, x + 1){
		add(s, i, 1);
		add(i, s, 0);
	}
	rep(i, x + 1 + 1, x + y + 1){
		add(i, t, 1);
		add(t, i, 0);
	}
	ISAP();
	printf("%lld",maxflow);
	return 0;
}
