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
const int MAXN = 55;
const int MOD = 1e9 + 7;
struct Matrix{
	int siz;
	int data[MAXN][MAXN];
	Matrix(int siz, int a) : siz(siz){
		rep(i, 1, siz){
			rep(j, 1, siz){
				if(i == j) data[i][j] = a;
				else data[i][j] = 0;
			}
		}
		return;
	}
	struct Matrix operator * (struct Matrix b){
		struct Matrix ans(siz, 0);
		rep(i, 1, siz){
			rep(k, 1, siz){
				rep(j, 1, siz){
					ans.data[i][j] = ((ll)ans.data[i][j] + (ll)data[i][k] * b.data[k][j]) % MOD;
				}
			}
		}
		return ans;
	}
};
int n;
struct Matrix ksm(struct Matrix a, ll k){
	Matrix ans(n, 1), now = a;
	while(k){
		if(k & 1) ans = ans * now;
		now = now * now;
		k >>= 1;
	}
	return ans;
}
int main(){
	n = read();
	ll k;
	scanf("%lld", &k);
	struct Matrix in(n, 0);
	rep(i, 1, n){
		rep(j, 1, n){
			in.data[i][j] = read();
		}
	}
	struct Matrix ans = ksm(in, k);
	ll cnt = 0;
	rep(i, 1, n){
		rep(j, 1, n){
			cnt += ans.data[i][j];
		}
	}
	cnt %= MOD;
	printf("%lld", cnt);
	return 0;
}
