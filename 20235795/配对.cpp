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
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 23;
ll f[MAXN][1 << MAXN];
bool q[MAXN][MAXN];
bool check(int w, int m){
	int cnt = 0;
	while(w){
		w -= (w & -w);
		++cnt;
		if(cnt > m) return false;
	}
	return cnt == m;
}
int main(){
	int n = read();
	rep(i, 1, n){
		rep(j, 1, n){
			q[i][j] = read();
		}
	}
	f[0][0] = 1;
	rep(i, 1, n){
		int now = 0;
		while(now < (1 << n)){
			if(check(now, i - 1)){
				for(int j = 0; j < n; ++j){
					if(now & (1 << j) || !q[i][j + 1]) continue;
					f[i][now | (1 << j)] = (f[i][now | (1 << j)] + f[i - 1][now]) % MOD;
				}
			}
			++now;
		}
	}
	printf("%lld", f[n][(1 << n) - 1]);
	return 0;
}
