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
const int MAXN = 1e5 + 10;
double a[MAXN];
struct node{
	double sum, sum2, add;
	node(double sum, double sum2, double add) : sum(sum), sum2(sum2), add(add){}
	node() : sum(), sum2(), add(){}
}tree[MAXN << 2];
struct node operator + (struct node a, struct node b){
	a.sum += b.sum;
	a.sum2 += b.sum2;
	a.add += b.add;
	return a;
}
void build(int p, int l, int r){
	if(l == r){
		tree[p].sum = a[l];
		tree[p].sum2 = a[l] * a[l];
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	tree[p].sum = tree[ls].sum + tree[rs].sum;
	tree[p].sum2 = tree[ls].sum2 + tree[rs].sum2;
	return;
}
void pushdown(int p, int l, int r){
	tree[ls].add += tree[p].add;
	tree[ls].sum2 += 2 * tree[p].add * tree[ls].sum + tree[p].add * tree[p].add * (mid - l + 1);
	tree[ls].sum += tree[p].add * (mid - l + 1);

	tree[rs].add += tree[p].add;
	tree[rs].sum2 += 2 * tree[p].add * tree[rs].sum + tree[p].add * tree[p].add * (r - mid);
	tree[rs].sum += tree[p].add * (r - mid);

	tree[p].add = 0;
	return;
}
void add(int p, int l, int r, int x, int y, double k){
	if(x <= l && r <= y){
		tree[p].add += k;
		tree[p].sum2 += 2 * k * tree[p].sum + k * k * (r - l + 1);
		tree[p].sum += k * (r - l + 1);
		return;
	}
	if(r < x || l > y) return;
	pushdown(p, l, r);
	add(ls, l, mid, x, y, k);
	add(rs, mid + 1, r, x, y, k);
	tree[p].sum = tree[ls].sum + tree[rs].sum;
	tree[p].sum2 = tree[ls].sum2 + tree[rs].sum2;
	return;
}
struct node query(int p, int l, int r, int x, int y){
	if(x <= l && r <= y){
		return tree[p];
	}
	if(r < x || l > y) return node(0, 0, 0);
	pushdown(p, l, r);
	return query(ls, l, mid, x, y) + query(rs, mid + 1, r, x, y);
}
int main(){
	int n = read(), m = read();
	rep(i, 1, n){
		scanf("%lf", &a[i]);
	}
	build(1, 1, n);
	while(m--){
		int op = read();
		if(op == 1){
			int x = read(), y = read();
			double k;
			scanf("%lf", &k);
			add(1, 1, n, x, y, k);
		}
		else if(op == 2){
			int x = read(), y = read();
			int len = y - x + 1;
			struct node ans = query(1, 1, n, x, y);
			printf("%.4lf\n", ans.sum / len);
		}
		else{
			int x = read(), y = read();
			int len = y - x + 1;
			struct node ans = query(1, 1, n, x, y);
			printf("%.4lf\n", (ans.sum2 - ans.sum * ans.sum / len) / len);
		}
	}
	return 0;
}