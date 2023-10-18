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
const int MAXN = 1010;
ll f[MAXN][3];//�Ӹ����������Ӹ�����
struct edge{
	int x, w;
	edge():x(), w(){}
	edge(int x, int w):x(x), w(w){}
}input[MAXN];
vector<struct edge> tree[MAXN];
void dfs1(int p, int fa){
	if(tree[p].size() == 1 && tree[p][0].x == fa){
		f[p][0] = f[p][1] = f[p][2] = 0;
		return;
	}
	int sum = 0;
	frep(i, 0, tree[p].size()){
		int x = tree[p][i].x;
		sum += f[x][2] + tree[p][i].w * 2;
	}
	frep(i, 0, tree[p].size()){
		int x = tree[p][i].x;
		
	}
} 
int main(){
	int n = read();
	while(n){
		rep(i, 1, n) tree[i].clear();
		rep(i, 2, n){
			input[i].x = read();
		}
		rep(i, 2, n){
			input[i].w = read();
		}
		rep(i, 2, n){
			tree[i].push_back(input[i]);
			tree[input[i].x].push_back(edge(i, input[i].w));
		}
		dfs1(1, 0);
	}
	return 0;
}
