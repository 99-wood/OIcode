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
const int MAXN = 1000010;
vector<int> nxt[MAXN];
int f[MAXN][3];
void dfs(int p, int fa){
	int cnt = 0;
	frep(i, 0, nxt[p].size()){
		if(nxt[p][i] == fa || nxt[p][i] + p == 1) continue;
		++cnt;
	}
	if(!cnt){
		f[p][1] = 1;
		f[p][3] = 0;
//		printf("%d %d %d %d\n", p, f[p][1], f[p][2], f[p][3]);
		return;
	}
	int sum1 = 0,sum2 = 0;;
	frep(i, 0, nxt[p].size()){
		if(nxt[p][i] == fa || nxt[p][i] + p == 1) continue;
		int x = nxt[p][i];
		dfs(x, p);
		sum1 += min(f[x][1], min(f[x][2], f[x][3]));
		sum2 += min(f[x][1], f[x][2]);
	}
	f[p][1] = 1 + sum1;
	f[p][3] = 0;
	frep(i, 0, nxt[p].size()){
		if(nxt[p][i] == fa || nxt[p][i] + p == 1) continue;
		int x = nxt[p][i];
		f[p][2] = min(f[p][2], f[x][1] + sum2 - min(f[x][1], f[x][2]));
		f[p][3] += f[x][2];
	}
//	printf("%d %d %d %d\n", p, f[p][1], f[p][2], f[p][3]);
	return;
}
int main(){
	int m = read(), n = read();
	n += m;
	rep(i, 1, n){
		int x = read(), y = read();
		nxt[x].push_back(y);
		nxt[y].push_back(x);
	}
	int ans1, ans2;
	memset(f, 0x3f, sizeof(f));
	dfs(0, 0);
	ans1 = min(f[0][2], f[0][1]);
//	cout << endl;
	memset(f, 0x3f, sizeof(f));
	dfs(1, 1);
	ans2 = min(f[1][2], f[1][1]);
	printf("%d", min(ans1, ans2));
	return 0;
}
