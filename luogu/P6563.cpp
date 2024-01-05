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
//#define mid ((l + r) >> 1)
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
const int MAXN = 8100;
int a[MAXN];
ll f[MAXN][MAXN];
int q[MAXN], head, tail;
int main(){
	int t = read();
	while(t--){
		int n = read();
		rep(i, 1, n) a[i] = read();
		rep(i, 1, n) f[i][i] = 0;
		rep(i, 1, n - 1) f[i][i + 1] = a[i];
		rep(j, 3, n){
			int pos = j - 1;
			head = 0;
			tail = 1;
			q[head] = j - 1;
			drep(i, j - 2, 1){
				while(pos > i && f[pos + 1][j] <= f[i][pos]) --pos;
				while(head < tail && f[q[tail - 1] + 1][j] + a[q[tail - 1]] >= f[i + 1][j] + a[i]) --tail;
				q[tail++] = i;
				while(head < tail && q[head] > pos) ++head;
				f[i][j] = min(f[q[head] + 1][j] + a[q[head]], f[i][pos + 1] + a[pos + 1]);
			}
		}
		printf("%lld\n", f[1][n]);
	}
}
/*
1
30
6386 6503 6622 6743 6866 6991 7118 7247 7378 7511 7646 7783 7922 8063 8206 8351 8498 8647 8798 8951 9106 9263 9422 9583 9746 9911 10078 10247 10418 10591 
*/
