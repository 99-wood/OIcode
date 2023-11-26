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
const int MAXN = 4000010;
const double Pi = acos(-1.0);
struct Complex{
	double x, y;
	Complex(){
	}
	Complex(double x, double y): x(x), y(y){
	}
	struct Complex operator + (struct Complex b){
		return Complex(x + b.x, y + b.y);
	}
	struct Complex operator - (struct Complex b){
		return Complex(x - b.x, y - b.y);
	}
	struct Complex operator * (struct Complex b){
		return Complex(x * b.x - y * b.y, y * b.x + x * b.y);
	}
}a[MAXN], b[MAXN];
int limit = 1, l;
int trans[MAXN];
void FFT(struct Complex *A, int type){
	rep(i, 0, limit - 1) if(i < trans[i]) swap(A[i], A[trans[i]]);
	for(int mid = 1; mid < limit; mid <<= 1){
		struct Complex W(cos(Pi / mid), sin(Pi / mid) * type);
		for(int len = (mid << 1), s = 0; s < limit; s += len){
			struct Complex w(1.0, 0);
			rep(k, 0, mid - 1){
				struct Complex x = A[s + k], y = A[s + k + mid] * w;
				A[s + k] = x + y;
				A[s + k + mid] = x - y;
				w = w * W;
			}
		}
	}
}
char str1[MAXN], str2[MAXN];
int ans[MAXN];
int main(){
	bool flag = false;
	scanf("%s", str1);
	scanf("%s", str2);
	int n = strlen(str1) - 1, m = strlen(str2) - 1;
	if(str1[0] == '-'){
		rep(i, 0, n - 1) str1[i] = str1[i + 1];
		--n;
		flag ^= 1;
	}
	if(str2[0] == '-'){
		rep(i, 0, m - 1) str2[i] = str2[i + 1];
		--m;
		flag ^= 1;
	}
	rep(i, 0, n) a[i].x = str1[n - i] - '0';
	rep(i, 0, m) b[i].x = str2[m - i] - '0';
	while(limit <= n + m){
		limit <<= 1;
		++l;
	}
	rep(i, 0, limit - 1) trans[i] = (trans[i >> 1] >> 1) | ((i & 1) << (l - 1));
	FFT(a, 1);
	FFT(b, 1);
	rep(i, 0, limit - 1) a[i] = a[i] * b[i];
	FFT(a, -1);
	rep(i, 0, limit - 1){
		ans[i] += (int)(a[i].x / limit + 0.5);
		if(ans[i] >= 10){
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
	}
	while(!ans[limit] && limit >= 0) --limit;
	if(limit == -1) printf("0\n");
	else{
		if(flag) printf("-");
		while(limit >= 0) printf("%d", ans[limit--]);
	}
	return 0;
}
