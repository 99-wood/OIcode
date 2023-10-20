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
const int MAXN = 100010;
ll a[MAXN];
ll s[MAXN], l[MAXN];
int main(){
	int n = read(), t = read() + 1;
	rep(i, 1, n) a[i] = read();
	s[1] = 1; l[1] = a[1];
	rep(i, 2, n){
		if(a[i] <= l[i - 1]){
			s[i] = s[i - 1] + a[i];
			l[i] = l[i - 1];
		}
		else{
			s[i] = s[i - 1] + l[i - 1];
			l[i] = a[i];
		}
	}
	rep(i, 1, n){
		if(t <= s[i] + l[i] - 1){
			printf("1\n");
		}
		else{
			printf("%lld\n", (t - (s[i] + l[i] - 1)) / l[i] + (((t - (s[i] + l[i] - 1)) % l[i]) ? 1 : 0) + 1);
//			int ans = 
		}
	}
	return 0;
}
