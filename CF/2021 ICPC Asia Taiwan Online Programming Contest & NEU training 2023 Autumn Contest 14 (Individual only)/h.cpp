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
const int MAXN = 4e5;
const int INF = 0x3f3f3f3f;
int head[MAXN], nxt[MAXN], to[MAXN], w[MAXN], now[MAXN], cnt[MAXN], dep[MAXN], end1 = 0;
int head_[MAXN], nxt_[MAXN], to_[MAXN], w_[MAXN], end1_;
void add(int x, int y, int ww){
	to[end1] = y;
	w[end1] = ww;
	nxt[end1] = head[x];
	head[x] = end1;
	end1++;
	return;
}
ll maxflow;
int dfs(int p, int flow){
	if(p == t){
		maxflow += flow;
		return flow;
	}
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
		if(!cnt[dep[p]]) dep[s] = t;
		cnt[++dep[p]]++;
		now[p] = head[p];
	}
	return re;
}
void ISAP(){
	maxflow = 0;
	cnt[0] = siz;
	rep(i, s, t){
		now[i] = head[i];
		dep[i] = 0;
	}
	while(dep[s] < t) dfs(s, INF);
}
void cop(){
	end1_ = end1;
	rep(i, s, t) head_[i] = head[i];
	frep(i, 0, end1_){
		to_[i] = to[i];
		nxt_[i] = nxt[i];
		w_[i] = w[i];
	}
	return;
}
void pas(){
	end1 = end1_;
	rep(i, s, t) head[i] = head_[i];
	frep(i, 0, end1){
		to[i] = to_[i];
		nxt[i] = nxt_[i];
		w[i] = w_[i];
	}
	return;
}
int a[MAXN];
struct req{
	int x, y, i, j, k;
}q[10];
int n, m;
#define trans(a, b) (b * n + a)
int main(){
	memset(head, -1, sizeof(head));
	n = read(), m = read();
	s = 0;
	t = 16 * n + 1;
	siz = t + 1;
	rep(i, 1, m){
		int x = read() + 1, y = read() + 1;
		frep(j, 0, 16){
			add(trans(x, j), trans(y, j), 1);
			add(trans(y, j), trans(x, j), 1);	
		}
	}
	rep(i, 1, n){
		a[i] = read();
		if(a[i] == -1){
			continue;
		}
		else{
			frep(j, 0, 16){
				if((a[i] >> j) & 1){
					add(trans(i, j), t, INF);
					add(t, trans(i, j), 0);
				}
				else{
					add(s, trans(i, j), INF);
					add(trans(i, j), s, 0);
				}
			}
		}
	}
	cop();
	int rq = read();
	rep(i, 1, rq){
		q[i].k = read();
		q[i].x = read() + 1;
		q[i].i = read();
		q[i].y = read() + 1;
		q[i].j = read();
	}
	ll ans = INF;
	frep(k, 0, 1 << rq){
		pas();
		rep(i, 1, rq){
			if(q[i].k){
				if(k & (1 << (i - 1))){
					//x := 1
					add(s, trans(q[i].y, q[i].j), INF);
					add(trans(q[i].y, q[i].j), s, 0);
					add(trans(q[i].x, q[i].i), t, INF);
					add(t, trans(q[i].x, q[i].i), 0);
				}
				else{
					add(s, trans(q[i].x, q[i].i), INF);
					add(trans(q[i].x, q[i].i), s, 0);
					add(trans(q[i].y, q[i].j), t, INF);
					add(t, trans(q[i].y, q[i].j), 0);
				}
			}
			else{
				add(trans(q[i].x, q[i].i), trans(q[i].y, q[i].j), INF);
				add(trans(q[i].y, q[i].j), trans(q[i].x, q[i].i), INF);
			}
		}
		ISAP();
		ans = min(ans, maxflow);
	}
	printf((ans == INF ? "-1" : "%lld"), ans);
	return 0;
}