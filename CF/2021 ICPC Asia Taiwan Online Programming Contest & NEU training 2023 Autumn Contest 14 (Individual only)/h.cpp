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
#include<bitset>
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
	while(c>='0'&&c<='9'){
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}
int s, t, siz;
const int MAXN = 1e6;
const int INF = 0x3f3f3f3f;
int head[MAXN], nxt[MAXN], to[MAXN], w[MAXN], now[MAXN], cnt[MAXN], dep[MAXN], end1 = 0;
void add(int x, int y, int ww){
	to[end1] = y;
	w[end1] = ww;
	nxt[end1] = head[x];
	head[x] = end1;
	end1++;
	return;
}
int maxflow;
int dfs(int p, int flow){
	int re = 0;
	for(; now[p] != -1; now[p] = nxt[now[p]]){
		int pp = to[now[p]];
		if(!w[now[p]] || dep[pp] != dep[p] - 1) continue;
		int f = dfs(pp, min(flow, w[now[p]]));
		w[now[p]] -= f;
		w[now[p] ^ 1] += f;
		re += f;
		flow -= f;
		if(!flow) break;
	}
	if(flow){
		cnt[dep[p]]--;
		if(!cnt[dep[p]]) dep[s] = siz;
		cnt[++dep[p]]++;
		now[p] = head[p];
	}
	return re;
}
void ISAP(){
	while(dep[s] < siz) dfs(s, INF);
}
int a[MAXN];
int main(){
	memset(head, -1, sizeof(head));
	int n = read(), m = read();
	
	return 0;
}