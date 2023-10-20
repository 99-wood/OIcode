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
const int MAXN = 20010;
int n, m;
int nxt[MAXN], to[MAXN], head[MAXN], w[MAXN], endd = 0;
void add(int x, int y, int ww){
	to[endd] = y;
	w[endd] = ww;
	nxt[endd] = head[x];
	head[x] = endd;
	++endd;
	return;
};
struct node{
	int from, to;
	ll dis;
	node():from(), to(), dis(){}
	node(int from, int to, ll dis):from(from), to(to), dis(dis){}
};
ll dis[MAXN];
bool operator < (node a, node b){
	return a.dis > b.dis;
}
priority_queue<node> q;
bool vis[MAXN];
vector<int> g[MAXN];
vector<int> order;
void dij(){
	dis[1] = 0;
	vis[1] = true;
	order.push_back(1);
	for(int i = head[1]; i != -1; i = nxt[i]){
		int x = to[i];
		q.push(node(1, x, w[i]));
	}
	while(!q.empty()){
		ll minn = 1e17;
		while((!q.empty())){
			struct node now = q.top();
			if(now.dis > minn) break;
			q.pop();
			if(!vis[now.to]){
				vis[now.to] = true;
				minn = now.dis;
				dis[now.to] = now.dis;
				order.push_back(now.to);
				for(int i = head[now.to]; i != -1; i = nxt[i]){
					int x = to[i];
					q.push(node(now.to, x, dis[now.to] + w[i]));
				}
			}
			if(now.dis <= dis[now.to]){
				g[now.to].push_back(now.from);
			}
		}
	}
}
int cnt[MAXN];

int main(){
	memset(head, -1, sizeof(head));
	n = read(), m = read();
	rep(i, 1, n){
		int x = read(), y = read(), ww = read();
		add(x, y, ww);
	}
	dij();
	
	return 0;
}
