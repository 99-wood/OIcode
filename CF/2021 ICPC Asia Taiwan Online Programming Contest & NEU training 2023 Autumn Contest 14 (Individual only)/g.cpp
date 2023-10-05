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
const int MAXN = 1e6;
int head[MAXN], nxt[MAXN], to[MAXN], lab[MAXN], cut[MAXN], end1 = 0;
void add(int x, int y, int w){
	to[end1] = y;
	lab[end1] = w;
	nxt[end1] = head[x];
	head[x] = end1;
	end1++;
	to[end1] = x;
	lab[end1] = w;
	nxt[end1] = head[y];
	head[y] = end1;
	end1++;
	return;
}
ll ans = 0;
int root, maxl;
int siz[MAXN], mor[MAXN], les[MAXN];
void dfs1(int p, int fa, int sum){
	siz[p] = 1;
	int maxx = 0;
	for(int i = head[p]; i != -1; i = nxt[i]){
		if(cut[i] || to[i] == fa) continue;
		dfs1(to[i], p, sum);
		siz[p] += siz[to[i]];
		maxx = max(maxx, siz[to[i]]);
	}
	maxx = max(maxx, sum - siz[p]);
	if(maxx < maxl){
		maxl = maxx;
		root = p;
	}
	return;
}
void dfs2(int p, int fa, int w, int rt){
	for(int i = head[p]; i != -1; i = nxt[i]){
		if(cut[i] || to[i] == fa) continue;
		if(lab[i] > w){
			dfs2(to[i], p, lab[i], rt);
			++mor[rt];
		}
	}
	return;
}
void dfs3(int p, int fa, int w, int rt){
	for(int i = head[p]; i != -1; i = nxt[i]){
		if(cut[i] || to[i] == fa) continue;
		if(lab[i] < w){
			dfs3(to[i], p, lab[i],rt);
			++les[rt];
		}
	}
	return;
}
struct node{
	int w, cnt1, cnt2;
}tmp[MAXN];
void solve(int p, int size){
	maxl = 0x3f3f3f3f;
	dfs1(p, 0, size);
	p = root;
	dfs1(p, 0, size);
	int m = 0;
	for(int i = head[p]; i != -1; i = nxt[i]){
		if(cut[i]) continue;
		++m;
		int pp = to[i];
		mor[pp] = les[pp] = 1;
		dfs2(pp, p, lab[i], pp);
		dfs3(pp, p, lab[i], pp);
		tmp[m].w = lab[i];
		tmp[m].cnt1 = les[pp];
		tmp[m].cnt2 = mor[pp];
		ans += les[pp];
		ans += mor[pp];
	}
	sort(tmp + 1, tmp + 1 + m, [&](struct node a, struct node b){
		return a.w < b.w;
	});
	int cnt = 0, sum = 0, last = -1;
	rep(i, 1, m){
		ans += (ll)tmp[i].cnt2 * sum;
		if(last == tmp[i].w){
			cnt += tmp[i].cnt1;
		}
		else{
			ans += (ll)tmp[i].cnt2 * cnt;
			sum += cnt;
			last = tmp[i].w;
			cnt = tmp[i].cnt1;
		}
	}
	for(int i = head[p]; i != -1; i = nxt[i]){
		if(cut[i]) continue;
		cut[i] = cut[i ^ 1] = true;
		solve(to[i], siz[to[i]]);
	}
	return;
}
int main(){
	memset(head, -1, sizeof(head));
	int n = read();
	frep(i, 1, n){
		int x = read(), y = read(), w = read();
		add(x, y, w);
	}
	solve(1, n);
	printf("%lld", ans);
	return 0;
}