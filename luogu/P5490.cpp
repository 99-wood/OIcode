#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
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
const int MAXN = 100010;
int hight[MAXN << 1];
int a[MAXN << 4], res[MAXN << 4];
struct node{
	int x, y1, y2;
	int op;
}opr[MAXN << 1];
bool cmp(struct node a, struct node b){
	return a.x < b.x;
}
void modify(int p, int l, int r, int x, int y, int w){
	if(x <= l && r <= y){
		a[p] += w;
		if(a[p]) res[p] = (hight[r + 1] - hight[l]);
		else res[p] = res[ls] + res[rs];
		return;
	}
	if(x <= mid) modify(ls, l, mid, x, y, w);
	if(y >= mid + 1) modify(rs, mid + 1, r, x, y, w);
	if(!a[p]) res[p] = res[ls] + res[rs];
	return;
}
int main(){
	int n = read();
	rep(i, 1, n){
		int x1 = read(), y1 = read(), x2 = read(), y2 = read();
		opr[i].op = 1;
		opr[i].x = x1;
		opr[i].y1 = y1;
		opr[i].y2 = y2;
		opr[n + i].op = -1;
		opr[n + i].x = x2;
		opr[n + i].y1 = y1;
		opr[n + i].y2 = y2;
		hight[i] = y1;
		hight[n + i] = y2;
	}
	sort(hight + 1, hight + n * 2 + 1);
	int len = unique(hight + 1, hight + n * 2 + 1) - (hight + 1);
	sort(opr + 1, opr + n * 2 + 1, cmp);
	int last = 0, l = 0;
	ll ans = 0;
	rep(i, 1, n * 2){
		ans += (ll)(opr[i].x - last) * l;
		modify(1, 1, len, lower_bound(hight + 1, hight + 1 + len - 1, opr[i].y1) - hight, lower_bound(hight + 1, hight + 1 + len, opr[i].y2) - hight - 1, opr[i].op);
		last = opr[i].x;
		l = res[1];
	}
	printf("%lld", ans);
	return 0;
}
