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
const int MAXN = 510;
int f[MAXN][MAXN][10];
char str[MAXN];
int s[MAXN];
int main(){
	scanf("%s", str + 1);
	int m = read();
	int n = strlen(str + 1);
	rep(i, 1, n){
		//colors, red (R), green (G), blue (B), cyan (C), magenta (M), yellow(Y), and key (K),
		if(str[i] == 'R') s[i] = 1;
		if(str[i] == 'G') s[i] = 2;
		if(str[i] == 'B') s[i] = 3;
		if(str[i] == 'C') s[i] = 4;
		if(str[i] == 'M') s[i] = 5;
		if(str[i] == 'Y') s[i] = 6;
		if(str[i] == 'K') s[i] = 7;
	}
	memset(f, -1, sizeof(f));
	rep(i, 1, n) f[i][i][s[i]] = 1;
	rep(k, 2, n){
		rep(l, 1, n - k + 1){
			int r = l + k - 1;
			rep(i, 1, 7){
				rep(p, l, r - 1){
					rep(j, 1, 7){
						if(i == j){
							if(f[l][p][i] == -1 || f[p + 1][r][i] == -1) continue;
							f[l][r][i] = max(f[l][r][i], f[l][p][i] + f[p + 1][r][i]);
						}
						else{
							if(f[l][p][j] >= m) f[l][r][i] = max(f[l][r][i], f[p + 1][r][i]);
							if(f[p + 1][r][j] >= m) f[l][r][i] = max(f[l][r][i], f[l][p][i]);
						}
					}
				}
			}
			int mx = -1;
			rep(i, 1, 7) mx = max(mx, f[l][r][i]);
			if(mx >= m){
				rep(i, 1, 7) f[l][r][i] = max(f[l][r][i], 0);
			}
		}
	}
	rep(i, 1, 7){
		if(f[1][n][i] >= m){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
