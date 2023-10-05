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
const int MAXN = 1e6;
int a[MAXN];
int p[MAXN];
int tmp[MAXN];
ll ans;
#define mid ((l + r) >> 1)
void solve(int l, int r){
	if(l == r) return;
	solve(l, mid);
	solve(mid + 1, r);
	int i = l, j = mid + 1;
	int k = l;
	while(i <= mid && j <= r){
		if(p[i] < p[j]) tmp[k++] = p[i++];
		else{
			ans += (mid - i + 1);
			tmp[k++] = p[j++];
		}
	}
	while(i <= mid) tmp[k++] = p[i++];
	while(j <= r) tmp[k++] = p[j++];
	k = l;
	while(k <= r){
		p[k] = tmp[k];
		k++;
	}
	return;
}
int main(){
	int n = read();
	rep(i, 1, n){
		a[i] = read();
		p[a[i]] = i;
	}
	solve(1, n);
	printf("%lld", ans);
	return 0;
}