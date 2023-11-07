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
const int MAXN = 300010;
char s[MAXN];
int check(int n, int x, int y){
	int cnt1 = 0, cnt2 = 0;
	int a = 0, b = 0;
	rep(i, 1, n){
		cnt1 += s[i] == 'A';
		cnt2 += s[i] == 'B';
		if(cnt1 == x){
			cnt1 = cnt2 = 0;
			++a;
			if(a == y && i == n) return 1;
		}
		if(cnt2 == x){
			cnt1 = cnt2 = 0;
			++b;
			if(b == y && i == n) return -1;
		}
	}
	return 0;
}
int main(){
	int t = read();
	while(t--){
		int n = read();
		scanf("%s", s + 1);
		int cnt1 = 0, cnt2 = 0;
		bool a = false, b = false;
		rep(x, 1, 20){
			rep(y, 1, 20){
				int ans = check(n, x, y);
				if(ans == 1) a = true;
				else if(ans == -1) b = true;
			}
		}
		if(a && b) printf("?\n");
		else if(a) printf("A\n");
		else printf("B\n");
	}
	return 0;
}
