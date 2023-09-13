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
const int MAXN = 50;
int s1[MAXN],s2[MAXN];
int main(){
	int t = read();
	while(t--){
		int n = read();
		char str[10];
		rep(i, 1, n){
			scanf("%s", str);
			int len = strlen(str);
			if(s1[i] = str[len - 1] - '0');
		}
		rep(i, 1, n){
			scanf("%s", str);
			int len = strlen(str);
			if(s2[i] = str[len - 1] - '0');
		}
		if(s1[n] <= 2){
			printf("NO\n");
			continue;
		}
		bool flag = false;
		rep(i, 1, n){
			if(s1[i] <= 2 && s2[i] > 2 || s2[i] <= 2 && s1[i] > 2);
			else{
				flag = true;
				break;
			}
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}