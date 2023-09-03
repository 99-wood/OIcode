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
const int MAXN = 110;
bool a[MAXN];
int dp[2][MAXN][MAXN*MAXN];
int main(){
	char c;
	int n = 0, cnt = 0;
	while(c = getchar()){
		if(c < '0' || c > '1') break;
		a[++n] = c - '0';
		cnt += c - '0';
	}
	rep(i, 1, n){
		memset(dp[i & 1], 0x3f, sizeof(dp[i & 1]));
		rep(j, 0, i){
			rep(k, i - j, j * (i - j)){
				dp[i & 1][j][k] = min(dp[i & 1][j][k], dp[~i & 1][j - 1][k - (i - j)] + (!a[i]));
			}
		}
		rep(j, 0, i - 1){
			rep(k, 0, j * (i - j - 1)){
				dp[i & 1][j][k] = min(dp[i & 1][j][k], dp[~i & 1][j][k] + a[i]);
			}
		}
	}
	printf("%d", dp[n & 1][cnt][cnt * (n - cnt) / 2] >> 1);
	return 0;
}