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
const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;
int num[MAXN];
int f[MAXN][200];
int g[MAXN][200];
int main(){
	int n = 0;
	char c = getchar();
	while(c >= '0' && c <= '9'){
		num[++n] = c - '0';
		c = getchar();
	}
	rep(i, 1, n >> 1){
		swap(num[i], num[n - i + 1]);
	}
	int m = read();
	f[0][0] = 1;
	g[0][0] = 1;
	rep(i, 1, n){
		rep(j, 0, m - 1){
			rep(k, 0, 9){
				f[i][(j + k) % m] = (f[i][(j + k) % m] + f[i - 1][j]) % MOD;
			}
		}
		rep(j, 0, m - 1){
			frep(k, 0, num[i]){
				g[i][(j + k) % m] = (g[i][(j + k) % m] + f[i - 1][j]) % MOD;
			}
			g[i][(j + num[i]) % m] = (g[i][(j + num[i]) % m] + g[i - 1][j]) % MOD;
		}
	}
	printf("%d", (g[n][0] - 1 + MOD) % MOD);
	return 0;
}
