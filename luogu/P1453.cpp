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
const int MAXN = 200010;
int r1, r2;
int a[MAXN];
vector<int> to[MAXN];
int dp[MAXN][2];
int vis[MAXN];
void findrt(int p, int fa){
	if(vis[p]){
		r1 = p;
		r2 = fa;
		return;
	}
	vis[p] = true;
	frep(i, 0, to[p].size()){
		int x = to[p][i];
		if(x == fa) continue;
		findrt(x, p);
	}
	return;
}
void dfs(int p, int fa){
	dp[p][0] = 0, dp[p][1] = a[p];
	frep(i, 0, to[p].size()){
		int x = to[p][i];
		if(x == fa || (p == r1 && x == r2) || (p == r2 && x == r1)) continue;
		dfs(x, p);
		dp[p][1] += dp[x][0];
		dp[p][0] += max(dp[x][0], dp[x][1]);
	}
	return;
}
int main(){
	int n = read();
	rep(i, 1, n){
		a[i] = read();
	}
	rep(i, 1, n){
		int x = read(), y = read();
		++x, ++y;
		to[x].push_back(y);
		to[y].push_back(x);
	}
	findrt(1, 0);
	int res1, res2;
	double k;
	scanf("%lf", &k);
	dfs(r1, 0); res1 = dp[r1][0];
	dfs(r2, 0); res2 = dp[r2][0];
	printf("%.1lf", (double)max(res1, res2) * k);
	return 0;
}