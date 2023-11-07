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
#include<windows.h> 
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls (p << 1)
#define rs (p << 1 | 1)
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
const int MAXN = 5e5 + 10;
int a[MAXN], b[MAXN];
int s[MAXN], head, tail;
int to[MAXN];
int out[MAXN], endd;
int main(){
	int t = read();
	while(t--){
		int n = read(), m = read();
		rep(i, 1, n) a[i] = read();
		rep(i, 1, m) b[i] = read();
		sort(b + 1, b + m + 1, [&](int a, int b){
			return a < b;
		});
		head = 0;
		tail = -1;
		rep(i, 1, n){
			while(tail >= head && a[s[tail]] <= a[i]) --tail;
			s[++tail] = i;
		}
		rep(i, 1, m){
			while(tail >= head && a[s[tail]] < b[i]) --tail;
			if(tail >= head) to[i] = s[tail];
			else to[i] = 0;
		}
		int i = 1, j = m;
		for(; j >= 1 && to[j] == 0; --j) printf("%d ", b[j]);
		while(i <= n && j >= 1){
			printf("%d ", a[i]);
			while(j >= 1 && to[j] == i){
				printf("%d ", b[j--]);
			}
			++i;
		}
		for(; i <= n; ++i) printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}
