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
	while(c>='0'&&c<='9'){
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}
const int MAXN = 20;
int trans(char c[]){
	int len = strlen(c);
	int ans = 0;
	frep(i, 0, len){
		ans *= 10;
		ans += (c[i] - '0');
	}
	return ans;
}
int main(){
	char a[MAXN], b[MAXN];
	scanf("%s", a);
	scanf("%s", b);
	int len1 = strlen(a), len2 = strlen(b);
	frep(i, 0, len1){
		if(a[i] > '9' || a[i] < '0'){
			printf("NaN\n");
			return 0;
		}
	}
	frep(i, 0, len2){
		if(b[i] > '9' || b[i] < '0'){
			printf("NaN\n");
			return 0;
		}
	}
	printf("%d", trans(a) - trans(b));
	return 0;
}