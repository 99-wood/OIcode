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
#include<random>
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
int n, m, MOD = 1e9 + 7;
int ksm(int a, int b){
	ll now = a % MOD, ans = 1;
	while(b){
		if(b & 1) ans = ans * now % MOD;
		now = now * now % MOD;
		b >>= 1;
	}
	return ans;
}
int inv(int a){
	return ksm(a, MOD - 2);
}
ll f[2][MAXN][MAXN * MAXN];

struct Matrix {
	int a[MAXN + 5][MAXN + 5];
	void identity() {
		for(int i = 0; i <= n; ++i) {
			for(int j = 0; j <= n; ++j) {
				a[i][j] = (i == j);
			}
		}
	}
	Matrix() {
		memset(a, 0, sizeof(a));
	}
};
Matrix operator * (const Matrix& X, const Matrix& Y) {
	Matrix Z;
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= n; ++j) {
			for(int k = 0; k <= n; ++k) {
				Z.a[i][j] = ((ll)Z.a[i][j] + (ll)X.a[i][k] * Y.a[k][j]) % MOD;
			}
		}
	}
	return Z;
}
Matrix mat_pow(Matrix X, int i) {
	Matrix Y; Y.identity();
	while(i) {
		if(i & 1) Y = Y * X;
		X = X * X;
		i >>= 1;
	}
	return Y;
}
int c[MAXN * (MAXN + 1) + 5][MAXN + 5];
void init(int l, int r) {
	Matrix trans;
	trans.a[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		trans.a[i - 1][i] = 1;
		trans.a[i][i] = 1;
	}
	Matrix res = mat_pow(trans, l);
	for(int i = 0; i <= n; ++i) {
		c[0][i] = res.a[0][i];
	}
	for(int i = l + 1; i <= r; ++i) {
		c[i - l][0] = 1;
		for(int j = 1; j <= n; ++j) {
			c[i - l][j] = (c[i - 1 - l][j - 1] + c[i - 1 - l][j]) % MOD;
		}
	}
}
int main(){
//	freopen("tower.in", "r", stdin);
//	freopen("tower.out", "w", stdout);
	n = read(), m = read(), MOD = read();
	f[1][1][0] = 1;
	rep(i, 2, n){
		int now = i & 1, last = now ^ 1;
		rep(j, 1, i - 1){
			rep(k, 0, (i - 1) * i){
				f[now][j + 1][k] += f[last][j][k] * (j + 1) % MOD;
				f[now][j][k + i] += f[last][j][k] * (j << 1) % MOD;
				if(j >= 2)f[now][j - 1][k + (i << 1)] += f[last][j][k] * (j - 1) % MOD;
				f[last][j][k] = 0;
			}
		}
	}
	int now = n & 1;
	ll ans = 0;
	--m;
	int S = n * (n + 1);
	int l = max(m - S + n, n), r = m + n;
	init(l, r);
	rep(k, 0, S){
		ll p = 1;
		ans += f[now][1][k] * c[m - k + n - l][n] % MOD % MOD;
		ans %= MOD;
	}
	printf("%lld", ans);
	return 0;
}