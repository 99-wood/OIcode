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
#define drep(i,a,b) for(int i=a;i>=(b);--i)v
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
const int MAXN = 5e5;
int x[MAXN], y[MAXN], endd;
void add(int a, int b){
	x[endd] = a;
	y[endd] = b;
	++endd;
	return;
}
void line1(int a, int b, int h){
	add(a, b);
	rep(i, a + 1, a + h - 1){
		add(i, b + 1);
		add(i, b);
	}
	add(a, b + 1);
	return;
}
void line2(int a, int b, int h){
	add(a, b);
	drep(i, a - 1, a - h + 1){
		add(i, b + 1);
		add(i, b);
	}
	add(a, b + 1);
	return;
}
void line3(int a, int b, int h){
	add(a, b);
	drep(i, b, b - h - 1){
		add(a + 1, i);
		add(a, i);
	}
	add(a + 1, b);
	return;
}
void line4(int a, int b, int h){
	add(a, b);
	drep(i, b - 1, b - h + 1){
		add(a + 1, i);
		add(a, i);
	}
	add(a + 1, b);
	return;
}
int main(){
	int t = read();
	while(t--){
		bool flag = false;
		int n = read(), m = read();
		endd = 0;
		if(n == 2){
			add(1, 1);
			rep(i, 2, m){
				add(2, i);
				add(1, i);
			}
			add(2, 1);
		}
		else if((n & 1) && (m & 1)){
			int cnt = 0;
			for(int i = 1; m - i <= 2; i += 2){
				if(cnt & 1) line2(n, i, n);
				else line1(1, i, n);
				++cnt;
			}
			int d = m - 2;
			if(((i - 1) >> 1) & 1)
		}
		else{
			if(!(n & 1)) swap(n, m);

		}
	}
	return 0;
}