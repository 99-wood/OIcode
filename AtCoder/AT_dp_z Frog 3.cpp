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
const int MAXN = 2e5 + 10;
const int MOD  = 1e9 + 7;
int n;
ll C;
ll h[MAXN];
ll f[MAXN];
double Y(int i){
	return f[i] + h[i] * h[i];
}
double X(int i){
	return h[i];
}
int q[MAXN], head, tail;
double slope(int a, int b){
	return (Y(a) - Y(b)) / (X(a) - X(b));
}
int main(){
	scanf("%d%lld", &n, &C);
	rep(i, 1, n) h[i] = read();
	q[1] = head = tail = 1;
	rep(i, 2, n){
		while(tail > head && slope(q[head], q[head + 1]) <= h[i] * 2) head++;
		int j = q[head];
		f[i] = f[j] + (h[i] - h[j]) * (h[i] - h[j]) + C;
		while(tail > head && slope(q[tail - 1], q[tail]) >= slope(q[tail], i)) tail--;
		q[++tail] = i;
	}
	printf("%lld", f[n]);
	return 0;
}
