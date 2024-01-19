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
const int MAXN = 500;
const int MAXM = 5000;
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
queue<int> q;
ll maxflow;
void bfs(){
	dep[t] = 0;
	++cnt[dep[t]];
	q.push(t);
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int i = head[p]; i != -1; i = nxt[i]){
			int x = to[i];
			if(dep[x] == -1){
				dep[x] = dep[p] + 1;
				cnt[dep[x]]++;
				q.push(x);
			}
		}
	}
	return;
}
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
int a, b;
void ISAP(){
	bfs();
	while(dep[s] < n) dfs(s, INF);
	return;
}
bool vis[MAXN];
void print1(int p){
	if(vis[p]) return;
	vis[p] = true;
	if(p <= a && p != s) printf("%d ", p);
	for(int i = head[p]; i != -1; i = nxt[i]){
		int x = to[i], f = w[i];
		if(!f) continue;
		print1(x);
	}
	return;
}
void print2(int p){
	if(vis[p]) return;
	vis[p] = true;
	if(p > a && p != t) printf("%d ", p - a);
	for(int i = head[p]; i != -1; i = nxt[i]){
		int x = to[i], f = w[i];
		if(!f) continue;
		print2(x);
	}
	return;
}
int main(){
	memset(head, -1, sizeof(head));
	memset(dep, -1, sizeof(dep));
	a = read(), b = read();
	n = a + b + 2;
	s = 0; t = a + b + 1;
	ll sum = 0;
	rep(i, 1, a){
		int w;
		scanf("%d", &w);
		sum += w;
		add(s, i, w);
		add(i, s, 0);
		char tools[10000];
		memset(tools,0,sizeof tools);
		cin.getline(tools,10000);
		int ulen=0,tool;
		while (sscanf(tools+ulen,"%d",&tool)==1)//之前已经用scanf读完了赞助商同意支付该实验的费用
		{//tool是该实验所需仪器的其中一个      
		    add(i, tool + a, INF);
		    add(tool + a, i, 0);
		    if (tool==0) 
		        ulen++;
		    else {
		        while (tool) {
		            tool/=10;
		            ulen++;
		        }
		    }
		    ulen++;
		}
	}
	rep(i, a + 1, a + b){
		int w;
		scanf("%d", &w);
		add(i, t, w);
		add(t, i, 0);
	}
	ISAP();
	print1(s);
	printf("\n");
	memset(vis, false, sizeof(vis));
	print2(s);
	printf("\n%lld", sum - maxflow);
	return 0;
}