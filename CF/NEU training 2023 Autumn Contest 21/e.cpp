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
#include<windows.h> 
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls (p << 1)
#define rs (p << 1 | 1)
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
const int MAXN = 1000010;
int n, m;
vector<int> nxt[MAXN];
int f[MAXN][3];
void dfs(int p, int fa){
	int cnt = 0;
	frep(i, 0, nxt[p].size()){
		if(nxt[p][i] == fa || nxt[p][i] < m) continue;
		++cnt;
	}
	if(!cnt){
		f[p][1] = 1;
		f[p][3] = 0;
		return;
	}
	int sum1 = 0,sum2 = 0;;
	frep(i, 0, nxt[p].size()){
		if(nxt[p][i] == fa || nxt[p][i] < m) continue;
		int x = nxt[p][i];
		dfs(x, p);
		sum1 += min(f[x][1], min(f[x][2], f[x][3]));
		sum2 += min(f[x][1], f[x][2]);
	}
	f[p][1] = 1 + sum1;
	f[p][3] = 0;
	frep(i, 0, nxt[p].size()){
		if(nxt[p][i] == fa || nxt[p][i] < m) continue;
		int x = nxt[p][i];
		f[p][2] = min(f[p][2], f[x][1] + sum2 - min(f[x][1], f[x][2]));
		f[p][3] += f[x][2];
	}
	return;
}
ll g[MAXN][3];
int rt = 0;
int last;
void dfs_(int p, int fa){
	last = p;
	if(p != fa){
		g[p][1] = f[p][1] + min(g[fa][1], min(g[fa][2], g[fa][3]));
		g[p][2] = min(f[p][2] + min(g[fa][1], g[fa][2]), f[p][3] + g[fa][1]);
		g[p][3] = f[p][3] + min(g[fa][1], g[fa][2]);
	}
	frep(i, 0, nxt[p].size()){
		if(nxt[p][i] == fa || nxt[p][i] >= m || nxt[p][i] == rt) continue;
		dfs_(nxt[p][i], p);
		break;
	}
	return;
}
int main(){
	memset(f, 0x3f, sizeof(f));
	m = read(), n = read();
	n += m;
	rep(i, 1, n){
		int x = read(), y = read();
		nxt[x].push_back(y);
		nxt[y].push_back(x);
	}
	rep(p, 0, m - 1){
		dfs(p, p);
	}
	ll ans = 0x3f3f3f3f;
	rt = 0;
	rep(i, 0, n){
		rep(j, 1, 3){
			g[i][j] = 0x3f3f3f3f;
		}
	}
	g[0][1] = f[0][1];
	g[0][2] = 0x3f3f3f3f;
	g[0][3] = 0x3f3f3f3f;
	dfs_(0, 0);
	ans = min(ans, min(g[last][1], min(g[last][2], g[last][3])));
	rep(i, 0, n){
		rep(j, 1, 3){
			g[i][j] = 0x3f3f3f3f;
		}
	}
	g[0][1] = 0x3f3f3f3f;
	g[0][2] = f[0][2];
	g[0][3] = 0x3f3f3f3f;
	dfs_(0, 0);
	ans = min(ans, min(g[last][1], g[last][2]));
	rep(i, 0, n){
		rep(j, 1, 3){
			g[i][j] = 0x3f3f3f3f;
		}
	}
	g[0][1] = 0x3f3f3f3f;
	g[0][2] = 0x3f3f3f3f;
	g[0][3] = f[0][3];
	dfs_(0, 0);
	ans = min(ans, min(g[last][1], g[last][2]));
	int pp;
	frep(i, 0, nxt[0].size()){
		if(nxt[0][i] == last || nxt[0][i] >= m || nxt[0][i] == rt) continue;
		pp = nxt[0][i];
		break;
	}
	rep(i, 0, n){
		rep(j, 1, 3){
			g[i][j] = 0x3f3f3f3f;
		}
	}
	g[pp][1] = 0x3f3f3f3f;
	g[pp][2] = 0x3f3f3f3f;
	g[pp][3] = f[pp][3] + f[0][3];
	dfs_(pp, pp);
	ans = min(ans, g[last][1]);
	printf("%lld", ans);
	return 0;
}
