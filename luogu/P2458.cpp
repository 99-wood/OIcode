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
#include<set>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define mid ((l + r) >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define tmp(a, b) (tmp[a] >> (n - (b)) & 1)
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
const int MAXN = 2000;
int w[MAXN], dp[MAXN][3];
vector<int> tree[MAXN];
void dfs(int p, int fa){
	dp[p][0] = 0x3f3f3f3f;
	dp[p][1] = w[p];
	dp[p][2] = 0;
	int sum = 0;
	frep(i, 0, tree[p].size()){
		int x = tree[p][i];
		if(x == fa) continue;
		dfs(x, p);
		dp[p][1] += min(dp[x][0], min(dp[x][1], dp[x][2]));
		sum += min(dp[x][0], dp[x][1]);
	}
	frep(i, 0, tree[p].size()){
		int x = tree[p][i];
		if(x == fa) continue;
		dp[p][0] = min(dp[p][0], sum - min(dp[x][0], dp[x][1]) + dp[x][1]);
	}
	frep(i, 0, tree[p].size()){
		int x = tree[p][i];
		if(x == fa) continue;
		dp[p][2] += min(dp[x][0], dp[x][1]);
	}
	return;
}
int main(){
	int n = read();
	rep(i, 1, n){
		int p = read();
		w[p] = read();
		int m = read();
		rep(i, 1, m){
			int x = read();
			tree[p].push_back(x);
			tree[x].push_back(p);
		}
	}
	dfs(1, 0);
	printf("%d", min(dp[1][0], dp[1][1]));
	return 0;
}
