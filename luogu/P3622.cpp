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
const int MAXN = 100010;
int dp[MAXN][1 << 6];
int lik[MAXN], fea[MAXN], s[MAXN];
int main(){
	int n = read(), m = read();
	rep(i, 1, m){
		s[i] = read();
		int f = read(), l = read();
		rep(j, 1, f){
			int a = read();
			if(a < s[i]) a += n;
			fea[i] |= (1 << (a - s[i]));
		}
		rep(j, 1, l){
			int a = read();
			if(a < s[i]) a += n;
			lik[i] |= (1 << (a - s[i]));
		}
	}
	int ans = 0;
	frep(ss, 0, 1 << 5){
		memset(dp, -0x3f, sizeof(dp)); //重要
		dp[1][ss] = 0;
		int p = 1;
		while(p <= m && s[p] == 1){
			dp[1][ss] += (bool)((ss & fea[p]) || ((~ss) & lik[p]));
			++p;
		}
		rep(j, 2, n - 4){
			frep(now, 0, 1 << 5){
				int cnt = 0;
				int k = p;
				while(k <= m && s[k] <= j){
					cnt += (bool)((now & fea[k]) || ((~now) & lik[k]));
					++k;
				}
				dp[j][now] = max(dp[j - 1][(now & ((1 << 4) - 1)) << 1], dp[j - 1][(now & ((1 << 4) - 1)) << 1 | 1]) + cnt;
			}
			while(p <= m && s[p] <= j){
				++p;
			}
		}
		frep(now, 0, 1 << 4){
			int cnt = 0;
			int k = p;
			while(k <= m){
				cnt += (bool)(((now | (ss << 4)) & (fea[k] << (s[k] - (n - 3)))) || ((~(now | (ss << 4))) & (lik[k] << (s[k] - (n - 3)))));
				++k;
			}
			ans = max(ans, max(dp[n - 4][now << 1], dp[n - 4][now << 1 | 1]) + cnt);
		}
	}
	printf("%d",ans);
	return 0;
}