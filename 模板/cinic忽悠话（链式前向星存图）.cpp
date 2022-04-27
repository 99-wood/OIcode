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
const int MAXN = 600;
const int MAXM = 1000000;

int n, m, s, t;
int nxt[MAXM], to[MAXM], head[MAXN], c[MAXM], f[MAXN], d[MAXN], endd = -1;
//容量c 流量d
int cnt[MAXN];
//一条弧只能伸展一次
void add(int u, int v, int w){
	nxt[++endd] = head[u];
	head[u] = endd;
	to[endd] = v;
	c[endd] = w;
	
	//加入反向边
	nxt[++endd] = head[v];
	head[v] = endd;
	to[endd] = u;
	c[endd] = 0;
	//反向边为0
	return;
}
int bfs(){
	memset(d,0,sizeof(d));
	queue<int> q;
	q.push(s);
	d[s] = 1;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		cnt[p] = head[p];
		for(int i = head[p]; i != -1; i = nxt[i]){
			int x = to[i];
			if(d[x] || c[i] == 0) continue;
			//不需要vis也可
			d[x] = d[p] + 1;
			q.push(x);
		}
	}
	return d[t];
}
int dfs(int p){
	if(p == t) return f[p];
	if(d[p] >= d[t]) return 0;
	int flow = 0;
	for(int i = cnt[p]; i != -1; i = nxt[i]){
		//当前弧优化
		cnt[p] = nxt[i];
		int x = to[i];
		if(d[x] != d[p] + 1 || !c[i]) continue;
		//避免同层但是不相连情况
		f[x] = min(c[i], f[p]);
		int re = dfs(x);
		flow += re;
		c[i] -= re;
		c[i ^ 1] += re;
		f[p] -= re;
		if(!f[p]) break;
	}
	return flow;
}
int main(){
	memset(head,-1,sizeof(head));
	n = read(), m = read();
	s = 0, t = n + 1;
	rep(i,1,n){
		int a = read();
		if(a){
			add(s,i,1);
		}
		else {
			add(i,t,1);
		}
	}
	rep(i,1,m){
		int u = read(), v = read();
		add(u,v,1);
		add(v,u,1);
	}
	int flow = 0;
	while(bfs()){
		f[s] = 0x3f3f3f3f;
		flow += dfs(s);
	}
	printf("%d",flow);
	return 0;
}