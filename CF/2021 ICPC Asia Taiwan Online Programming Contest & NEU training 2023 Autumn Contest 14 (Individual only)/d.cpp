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
	while(c>='0'&&c<='9'){
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}
const int MAXN = 310;
double f[MAXN];
double g[MAXN];
int main(){
	int n = read();
	f[1] = 1.0/(n - 1);
	g[1] = 0;
	rep(i, 2, n){
//		f[i] = f[i - 1] * (1 - ((1 - g[i - 1]) / (n - i + 1))) / (n - 1);
//		g[i] = f[i - 1] * (1 - g[i - 1]) / (n - i + 1);
		f[i] = f[i - 1] + f[i - 1] * 1 / (n - (i - 1));
		g[i] = g[i - 1] + f[i - 1] * 1 / (n - i + 1);
	}
	printf("%.10lf\n", f[n - 1]);
	return 0;
}