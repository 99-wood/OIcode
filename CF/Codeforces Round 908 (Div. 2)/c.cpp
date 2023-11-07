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
const int MAXN = 4e5 + 10;
int a[MAXN], pos[MAXN];
int nxt[MAXN], dfn[MAXN];
int o[MAXN];
int endd = 0;
int dfs(int p){
	if(o[p] != -1) return 0x3f3f3f3f;
	if(dfn[p]) return dfn[p];
	dfn[p] = ++endd;
	if(nxt[p] != -1){
		int res = dfs(nxt[p]);
		if(res <= dfn[p]){
			o[p] = endd - res + 1;
		}
		return res;
	}
	return 0x3f3f3f3f;
}
int walk(int p, int k){
	if(o[p] != -1) k = k % o[p];
	if(!k) return p;
	if(nxt[p] == -1) return -1;
	return walk(nxt[p], k - 1);
}
int main(){
	int t = read();
	while(t--){
		int n = read(), k =read();
		rep(i, 1, n){
			a[i] = read();
		}
		rep(i, 1, n - 1) a[i + n] = a[i];
		int m = (n << 1) - 1;
		rep(i, n, m){
			o[i] = -1;
			dfn[i] = 0;
			nxt[i] = -1;
			if(a[i] > n) continue;
			int to = (((i - n) + n - a[i]) % n) + n;
			if(a[to - n + 1 + a[i] - 1] == a[i]){
				nxt[i] = to;
			}
		}
		rep(i, n, m){
			if(!dfn[i]) dfs(i);
		}
		int ans = walk(n, k);
		printf(ans == -1 ? "No\n" : "Yes\n");
	}
	return 0;
}
