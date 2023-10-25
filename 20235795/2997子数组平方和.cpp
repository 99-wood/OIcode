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
#include<bitset> 
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define mid ((l + r) >> 1)
#define ls tree[p].l
#define rs tree[p].r
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
const int MAXN = 3100;
ll f[MAXN], g[MAXN];
ll a[MAXN], sum[MAXN];
double Y(int i){
	return sum[i] * sum[i] + f[i];
}
double X(int i){
	return sum[i];
}
double slope(int a, int b){
	return (Y(a) - Y(b)) / (X(a) - X(b));
}
int q[MAXN], head, tail;
int main(){
	int n = read(), k = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n) sum[i] = sum[i - 1] + a[i];
	rep(i, 1, n) f[i] = sum[i] * sum[i];
	rep(r, 2, k){
		q[head = tail = 1] = (r - 1);
		rep(i, r, n){
			int k = 2 * sum[i];
			while(head > tail && slope(q[tail], q[tail + 1]) <= k) ++tail;
			int j = q[tail];
			g[i] = f[j] + (sum[i] - sum[j]) * (sum[i] - sum[j]);
			while(head > tail && slope(q[head - 1], q[head]) >= slope(q[head], i)) --head;
			q[++head] = i;
		}
		rep(i, 1, n) f[i] = g[i];
	}
	printf("%lld", f[n]);
	return 0;
}
