#include<iostream>
#include<cstdio>
#include<cctype>
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

int read() {
    int r = 0, f = 0;
    char c;
    while (!isdigit(c = getchar())) f |= (c == '-');
    while (isdigit(c)) r = (r << 1) + (r << 3) + (c ^ 48), c = getchar();
    return f ? -r : r;
}
const int MOD = 1e9 + 7;
const int MAXN = 5010;
#define inv(a) ksm(a, MOD - 2)
int ksm(int a, int b){
	int now = a;
	int ans = 1;
	while(b){
		if(b & 1){
			ans = 1LL * ans * now % MOD;
		}
		now = 1LL * now * now % MOD;
		b >>= 1;
	}
	return ans;
}
int f[2][MAXN][MAXN];
int P[MAXN];
int ppow[MAXN];
int main(){
//	freopen("fire.in", "r", stdin);
//	freopen("fire.out", "w", stdout);
	int n = read(), r = read(), h = read();
	int p = 1LL * h * inv(r + h) % MOD;
	f[(n + 1) & 1][0][0] = 1;
	int inv100 = inv(100);
	ppow[0] = 1;
	rep(i, 1, n){
		P[i] = 1LL * read() * inv100 % MOD;
		ppow[i] = 1LL * ppow[i - 1] * p % MOD;
	}
	int A = read(), B = read();
	drep(i, n, 1){
		rep(a, 0, n){
			rep(b, 0, n - a){
				f[i & 1][a][b] = 0;
			}
		}
		rep(a, 0, n){
			rep(b, 0, n - a){
				if(!f[(i + 1) & 1][a][b]) continue;
				f[i & 1][a + 1][0] += 1LL * P[i] * f[(i + 1) & 1][a][b] % MOD * ppow[b] % MOD;
				f[i & 1][a + 1][0] %= MOD;
				f[i & 1][a][b + 1] += 1LL * (1 - P[i] + MOD) % MOD * f[(i + 1) & 1][a][b] % MOD;
				f[i & 1][a][b + 1] %= MOD;
				rep(x, 1, b){
					f[i & 1][a][x] += 1LL * P[i] * f[(i + 1) & 1][a][b] % MOD * ppow[b - x] % MOD * (1 - p + MOD) % MOD;
					f[i & 1][a][x] %= MOD;
				}
			}
		}
	}
	printf("%d", f[1][A][B]);
	return 0;
}