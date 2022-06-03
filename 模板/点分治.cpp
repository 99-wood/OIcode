#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
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
const int MAXN = 10010;
int n, m;
int to[MAXN << 1], nxt[MAXN << 1], head[MAXN], d[MAXN << 1], siz[MAXN], endd = -1;
void add(int x, int y, int w){
	nxt[++endd] = head[x];
	head[x] = endd;
	to[endd] = y;
	d[endd] = w;
	return;
}
int b[10000010], ans[MAXN];
int ask[MAXN];
int mx[MAXN], root, sum;
void findrt(int p, int fa){
	mx[p] = 0;
	siz[p] = 1;
	for(int i = head[p]; i != -1; i = nxt[i]){
		int x = to[i];
		if(d[i] == -1 || x == fa) continue;
		findrt(x, p);
		siz[p] += siz[x];
		mx[p] = max(mx[p], siz[x]);
	}
	mx[p] = max(mx[p], sum - siz[p]);
	if(mx[p] < mx[root]) root = p;
	return;
}
void finddis(int p, int fa, int dis, int tag){
	if(dis > 1e7) return;
	rep(i, 1, m){
		if(ask[i] - dis >= 0 && b[ask[i] - dis] < tag)
			ans[i] = true;
	}
	for(int i = head[p]; i != -1; i = nxt[i]){
		int x = to[i];
		if(d[i] == -1 || x == fa) continue;
		finddis(x, p, dis + d[i], tag);
	}
	b[dis] = min(b[dis], tag);
	return;
}
void clean(int p, int fa, int dis){
	if(dis > 1e7) return;
	b[dis] = 0x7f7f7f7f;
	for(int i = head[p]; i != -1; i = nxt[i]){
		int x = to[i];
		if(d[i] == -1 || x == fa) continue;
		clean(x, p, dis + d[i]);
	}
	return;
}
void solve(int p){
	b[0] = 0;
	int now = 0;
	for(int i = head[p]; i != -1; i = nxt[i]){
		int x = to[i];
		if(d[i] == -1) continue;
		finddis(x, p, d[i], ++now);
	}
	for(int i = head[p]; i != -1; i = nxt[i]){
		int x = to[i];
		if(d[i] == -1) continue;
		clean(x, p, d[i]);
	}
	for(int i = head[p]; i != -1; i = nxt[i]){
		int x = to[i];
		if(d[i] == -1) continue;
		root = 0;
		d[i ^ 1] = -1;
		sum = siz[x];
		findrt(x, 0);
		solve(root);
	}
	return;
}
int main(){
	memset(head, -1, sizeof(head));
	memset(b, 0x7f, sizeof(b));
	memset(mx, 0x7f, sizeof(mx));
	n = read(), m = read();
	frep(i, 1, n){
		int x = read(), y = read(), w = read();
		add(x, y, w);
		add(y, x, w);
	}
	rep(i, 1, m) ask[i] = read();
	sum = n;
	mx[0] = 0x7f7f7f7f;
	findrt(1, 0);
	solve(root);
	rep(i, 1, m) printf(ans[i] ? "AYE\n" : "NAY\n");
	return 0;
}