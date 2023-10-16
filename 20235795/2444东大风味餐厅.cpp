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
#define ls (p << 1)
#define rs (p << 1 | 1)
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
const int MAXN = 5010;
vector<int> tree[MAXN];
int fa[MAXN];
int f[MAXN][2];
void upd(int p){
	f[p][0] = f[p][1] = 0;
	frep(i, 0, tree[p].size()){
		int x = tree[p][i];
		f[p][0] += max(f[x][0], f[x][1]);
	}
	frep(i, 0, tree[p].size()){
		int x = tree[p][i];
		f[p][1] = max(f[p][1], 1 + f[p][0] - max(f[x][0], f[x][1]) + f[x][0]);
	}
	if(p) upd(fa[p]);
	return;
}
int main(){
	int n = read(), ans = 0;
	rep(i, 1, n){
		int x = read();
		fa[i] = x;
		tree[x].push_back(i);
		upd(i);
		printf("%d\n", max(f[0][0], f[0][1]));
	}
	return 0;
}
