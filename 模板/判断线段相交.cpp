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
#define ls tree[p].l
#define rs tree[p].r
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
const int MAXN = 1e4 + 10;
struct point{
	double x, y;
	point():x(), y(){
	}
	point(double x, double y):x(x), y(y){
	}
	struct point operator - (struct point b){
		return point(x - b.x, y - b.y);
	}
	struct point operator + (struct point b){
		return point(x + b.x, y + b.y);
	}
	int operator * (struct point b){
		return x * b.x + y * b.y;
	}
	struct point operator * (int b){
		return point(x * b, y * b);
	}
	void scan(){
		scanf("%lf%lf", &x, &y);
	}
};
#define vect point
double dis(struct point a, struct point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double outer(vect a, vect b){
	return a.x * b.y - a.y * b.x;
}
int main(){
	int q = read();
	while(q--){
		point p1, p2, p3, p4;
		p1.scan();
		p2.scan();
		p3.scan();
		p4.scan();
		if(p1.x > p2.x) swap(p1, p2);
		if(p3.x > p4.x) swap(p3, p4);
		if(min(p1.x,p2.x) <= max(p3.x,p4.x) &&
			min(p3.x,p4.x) <= max(p1.x,p2.x) &&
			min(p1.y,p2.y) <= max(p3.y,p4.y) &&
			min(p3.y,p4.y) <= max(p1.y,p2.y)){
			if(outer(p2 - p1, p3 - p1) * outer(p2 - p1, p4 - p1) <= 0 && outer(p4 - p3, p1 - p3) * outer(p4 - p3, p2 - p3) <= 0){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
		else{
			printf("0\n");
		}
	}
	return 0;
}
