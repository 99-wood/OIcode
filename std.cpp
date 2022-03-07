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
double s = 0.577215664901532;
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
const int MAXN = 800000;
int a[MAXN];
int main(){
	int n = read(), m = read();
	rep(i,1,n){
		a[i] = read();
	}
	rep(i,1,m){
		char c;
		do{
			c = getchar();
		}while(c != 'R' && c != 'Q');
		if(c == 'R'){
			int l = read(), r = read(), b = read();
			if(l > r) swap(l,r);
			rep(j,l,r){
				a[j] = b;
			}
		}
		else{
			int l = read(), r = read(), k = read();
			if(l > r) swap(l,r);
			int maxx = 1, maxy = 1, maxm = 1;
			bool flag = true;
			int x = 1;
			rep(j,l + 1,r){
				x = a[j] == a[j - 1] ? x + 1 : 1;
				if(x > 1){
					if(flag){
						maxx = max(maxx, x);
					}
					if(j == r) maxy = x;
					maxm = max(maxm, x);
				}
				else flag = false;
			}
			if(k){
				printf("%d\n",max(maxm, a[l] == a[r] ? min(maxx + maxy, (r - l + 1)) : 1));
			}
			else{
				printf("%d\n",maxm);
			}
		}
	}
	return 0;
}