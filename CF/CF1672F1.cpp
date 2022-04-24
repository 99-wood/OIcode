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
const int MAXN = 3e5;
int a[MAXN];
int cnt[MAXN];
int tail[MAXN], endd;
int to[MAXN];
struct node{
	int p, w;
}tmp[MAXN];
bool cmp(struct node a, struct node b){
	return a.w < b.w;
}
int main(){
	int t = read();
	while(t--){
		int n = read();
		rep(i, 1, n){
			a[i] = read();
			cnt[a[i]] = 0;
		}
		int now, maxx = 0;
		rep(i, 1, n){
			++cnt[a[i]];
			if(cnt[a[i]] > maxx){
				maxx = cnt[a[i]];
				now = a[i];
			}
		}
		endd = 0;
		rep(i, 1, n){
			if(a[i] == now){
				tail[++endd] = i;
			}
			tmp[i].w = a[i];
			tmp[i].p = i;
		}
		sort(tmp + 1, tmp + 1 + n, cmp);
		int p = 1;
		rep(i, 1, n){
			if(tmp[i].w == now){
				continue;
			}
			to[tmp[i].p] = tail[p];
			tail[p] = tmp[i].p;
			p = (p + 1) % (maxx + 1);
			if(!p) p = 1;
		}
		endd = 0;
		rep(i, 1, n){
			if(a[i] == now) to[i] = tail[++endd];
		}
		rep(i, 1, n){
			printf("%d ", a[to[i]]);
		}
		printf("\n");
	}
	return 0;
}