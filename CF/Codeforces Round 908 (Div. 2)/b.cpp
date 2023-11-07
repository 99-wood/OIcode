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
const int MAXN = 510;
int num[MAXN], pos[MAXN];
int cnt[MAXN];
int main(){
	int t = read();
	while(t--){
		memset(cnt, 0, sizeof(cnt));
		int n = read();
		rep(i, 1, n){
			num[i] = read();
			++cnt[num[i]];
			pos[i] = cnt[num[i]];
		}
		int a = 0, b = 0;
		rep(i, 1, 100){
			if(cnt[i] >= 2){
				if(a) b = i;
				else a = i;
			}
		}
		if(!b){
			printf("-1\n");
		}
		else{
			rep(i, 1, n){
				if(num[i] == a){
					if(pos[i] == 1) printf("1 ");
					else printf("2 ");
				}
				else if(num[i] == b){
					if(pos[i] == 1) printf("1 ");
					else printf("3 ");
				}
				else printf("3 ");
			}
			printf("\n");
		}
	}
	return 0;
}
