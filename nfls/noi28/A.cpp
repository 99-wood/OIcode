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
const int MAXN = 3e6 + 10;
const int MOD = 998244353;
vector<int> nxt[MAXN];
int maxx[MAXN], siz[MAXN];
int root;
int n;
void findrt(int p, int fa){
	siz[p] = 1;
	for(auto x : nxt[p]){
		if(x == fa) continue;
		findrt(x, p);
		maxx[p] = max(maxx[p], siz[x]);
		siz[p] += siz[x];
	}
	maxx[p] = max(maxx[p], n - siz[p]);
	if(maxx[p] < maxx[root]) root = p;
	return;
}
int minn = 0;
void dfs(int p, int fa){
	siz[p] = 1;
	for(auto x : nxt[p]){
		if(x == fa) continue;
		dfs(x, p);
		siz[p] += siz[x];
	}
	if(nxt[p].size() >= 3){
		if(p == root) minn = max(minn, siz[p] - maxx[p]);
		else minn = max(minn, siz[p]);
	}
	return;
}
int c[3010][3010];
int f[3010];
int ans[MAXN];
void print(int p, int fa){
	ans[siz[p]] = f[p];
	if(siz[p] == minn){
		return;
	}
	for(auto x : nxt[p]){
		if(x == fa) continue;
		print(x, p);
	}
	return;
}
void print_(int p, int fa){
	ans[siz[p]] = ((ll)ans[siz[p]] * f[p]) % MOD;
	if(siz[p] == minn){
		return;
	}
	for(auto x : nxt[p]){
		if(x == fa) continue;
		print_(x, p);
	}
	return;
}
void F(int p, int fa){
	f[p] = 1;
	if(nxt[p].size() == 1){
		return;
	}
	if(p == root){
		for(auto x : nxt[p]){
			if(x == fa) continue;
			F(x, p);
		}
		int mx = 0, pp;
		for(auto x : nxt[p]){
			if(x == fa) continue;
			if(siz[x] > mx){
				mx = siz[p];
				pp = x;
			}
		}
		print(pp, p);
		for(auto x : nxt[p]){
			if(x == fa || x == pp) continue;
			print_(x, p);
		}
		return;
	}
	if(nxt[p].size() == 2){
		for(auto x : nxt[p]){
			if(x == fa) continue;
			F(x, p);
			f[p] = f[x];
		}
		return;
	}
	for(auto x : nxt[p]){
		if(x == fa) continue;
		F(x, p);
		f[p] = ((ll)f[p] * c[siz[p] - 1][siz[x]] % MOD * f[x]) % MOD;
	}
	return;
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n = read();
	if(n == 2){
		printf("2\n");
		return 0;
	}
	bool flag = true;
	frep(i, 1, n){
		int x = read(), y = read();
		nxt[x].push_back(y);
		nxt[y].push_back(x);
		if(y != x + 1) flag = false;
	}
	if(flag){
		rep(i, 2, n >> 1){
			printf("2\n");
		}
		return 0;
	}
	c[1][0] = 1;
	c[1][1] = 1;
	rep(i, 2, 3000){
		c[i][0] = 1;
		rep(j, 1, i){
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
	maxx[0] = 0x3f3f3f3f;
	findrt(1, 0);
	dfs(root, 0);
	rep(i, 2, minn - 1){
		printf("0\n");
	}
	F(root, 0);
	rep(i, minn, n >> 1){
		printf("%d\n", ans[i]);
	}
	return 0;
}