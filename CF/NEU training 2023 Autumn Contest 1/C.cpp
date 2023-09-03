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
const int MAXSIZE = (1 << 18);
const int MAXN = 18;
int dp1[MAXSIZE][MAXN][MAXN];
int dp2[MAXSIZE];
int a[MAXN][MAXN];
int main(){
	memset(dp1, 0x3f, sizeof(dp1));
	memset(dp2, 0x3f, sizeof(dp2));
	int n = read(), ans = 0;
	frep(i, 0, n){
		frep(j, 0, n){
			a[i][j] = read();
		}
		dp2[1 << i] = dp1[1 << i][i][i] = 0;
	}
	frep(i, 0, n){
		frep(j, 0, n){
			if(a[i][j] == -1) a[i][j] = 0x3f3f3f3f;
			else{
				int tmp = min(a[i][j], a[j][i]);
				a[i][j] -= tmp;
				a[j][i] -= tmp;
				ans += tmp;
			}
		}
	}
	rep(i, 1, (1 << n) - 1){
		frep(s, 0, n){
			if(!((1 << s) & i)) continue;
			frep(t, 0, n){
				if(!((1 << t) & i)) continue;
				dp1[i][s][t] = min(dp1[i][s][t], dp2[i]);
				frep(tt, 0, n){
					if((1 << tt) & i) continue;
					dp1[i | (1 << tt)][s][tt] = min(dp1[i | (1 << tt)][s][tt], dp1[i][s][t] + a[t][tt]);
					if(s != t && a[t][tt] != 0x3f3f3f3f) dp2[i | (1 << tt)] = min(dp2[i | (1 << tt)], dp1[i | (1 << tt)][s][tt] + a[tt][s]);
				}
			}
		}
	}
	ans += dp2[(1 << n) - 1];
	printf("%d", ans >= 0x3f3f3f3f ? -1 : ans);
	return 0;
}