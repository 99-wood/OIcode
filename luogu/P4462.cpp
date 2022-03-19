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
int B, ans, k;
int a[MAXN];
int sum[MAXN];
int cnt[MAXN << 1];
struct node{
	int id, x, y, res;
}ask[MAXN];
bool cmp1(struct node a, struct node b){
	return a.x / B == b.x / B ? ((a.x / B) & 1) ^ (a.y < b.y) : a.x < b.x;
}
bool cmp2(struct node a, struct node b){
	return a.id < b.id;
}
void add(int a){
	ans += cnt[a ^ k];
	++cnt[a];
	return;
}
void del(int a){
	if((a ^ k) == a) ++ans;
	ans -= cnt[a ^ k];
	--cnt[a];
	return;
}
int main(){
	int n = read(), m = read();
	k = read();
	B = n / sqrt(n);
	rep(i, 1, n) a[i] = read(), sum[i] = sum[i - 1] ^ a[i];
	rep(i, 1, m) ask[i].id = i, ask[i].x = read(), ask[i].y = read();
	sort(ask + 1, ask + 1 + n, cmp1);
	int l = 0, r = 1;
	++cnt[sum[1]];
	++cnt[0];
	ans += (sum[1] == k);
	int now = 1;
	while(now <= m){
		while(r < ask[now].y) add(sum[++r]);
		while(l > ask[now].x - 1) add(sum[--l]);
		while(r > ask[now].y) del(sum[r--]);
		while(l < ask[now].x - 1) del(sum[l++]);
		ask[now].res = ans;
		++now;
	}
	sort(ask + 1, ask + 1 + n, cmp2);
	rep(i, 1, m){
		printf("%d\n", ask[i].res);
	}
	return 0;
}