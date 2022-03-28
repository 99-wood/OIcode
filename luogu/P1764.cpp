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
#include<set>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define mid ((l + r) >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define tmp(a, b) (tmp[a] >> (n - (b)) & 1)
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
const int MAXN = 200;
int n;
int a[MAXN];
int tmp[MAXN];
void f(int &a, int p){
	a ^= 1 << (n - p);
}
int check1(){
	int cnt = 0;
	rep(i, 2, n){
		if(!tmp(i - 1, 1)){
			f(tmp[i], 1);
			f(tmp[i], 2);
			f(tmp[i - 1], 1);
			f(tmp[i + 1], 1);
			++cnt;
		}
		rep(j, 2, n){
			if(!tmp(i - 1, j)){
				f(tmp[i], j);
				f(tmp[i], j - 1);
				f(tmp[i], j + 1);
				f(tmp[i - 1], j);
				f(tmp[i + 1], j);
				++cnt;
			}
		}
	}
	if((tmp[n] & ((1 << n) - 1)) != ((1 << n) - 1)) return 0x3f3f3f3f;
	return cnt;
}
int check0(){
	int cnt = 0;
	rep(i, 2, n){
		if(tmp(i - 1, 1)){
			f(tmp[i], 1);
			f(tmp[i], 2);
			f(tmp[i - 1], 1);
			f(tmp[i + 1], 1);
			++cnt;
		}
		rep(j, 2, n){
			if(tmp(i - 1, j)){
				f(tmp[i], j);
				f(tmp[i], j - 1);
				f(tmp[i], j + 1);
				f(tmp[i - 1], j);
				f(tmp[i + 1], j);
				++cnt;
			}
		}
	}
	if(tmp[n] & ((1 << n) - 1)) return 0x3f3f3f3f;
	return cnt;
}
int main(){
	n = read();
	rep(i, 1, n){
		rep(j, 1, n){
			char c;
			scanf("\n%c", &c);
			a[i] = a[i] << 1 | (c == 'b');
		}
	}
	int ans = 0x3f3f3f3f;
	rep(k, 0, (1 << n) - 1){
		int cnt = 0;
		for(int i = 0; k >> i; ++i) cnt += k >> i & 1;
		int kk = (k ^(k << 1) ^ (k >> 1)) & ((1 << n) - 1);
		rep(i, 1, n) tmp[i] = a[i];
		tmp[1] ^= kk;
		tmp[2] ^= k;
		ans = min(ans, cnt + check0());
		rep(i, 1, n) tmp[i] = a[i];
		tmp[1] ^= kk;
		tmp[2] ^= k;
		ans = min(ans, cnt + check1());
	}
	if(ans == 0x3f3f3f3f) printf("Impossible");
	else printf("%d", ans);
	return 0;
}