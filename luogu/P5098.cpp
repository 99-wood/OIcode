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
const int MAXN = 2e5 + 10;
struct Point{
	int x, y;
}p[MAXN];
int main(){
	int n = read();
	rep(i, 1, n) p[i].x = read(), p[i].y = read();
	int mxa = 0, mna = 0x3f3f3f3f, mxb = 0, mnb = 0x3f3f3f3f;
	int ans = 0;
	rep(i, 1, n){
		mxa = max(mxa, p[i].x + p[i].y);
		mna = min(mna, p[i].x + p[i].y);
		mxb = max(mxb, p[i].x - p[i].y);
		mnb = min(mnb, p[i].x - p[i].y);
	}
	printf("%d", max(mxa - mna, mxb - mnb));
	return 0;
}
