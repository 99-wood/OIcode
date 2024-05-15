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
	while(c>='0'&&c<='9') {
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}
const int MAXN = 300010;
stack<int> s; 
char str[MAXN];
int r[MAXN];
vector<int> ans;
int main(){
	scanf("%s", str + 1);
	int len = strlen(str + 1);
	int sum = 0;
	rep(i, 1, len){
		if(str[i] == '\\'){
			s.push(i);
		}
		else if(str[i] == '/'){
			if(!s.empty()){
				int p = s.top();
				s.pop();
				r[p] = i;
				sum += i - p;
			}
		}
	}
	for(int i = 1; i <= len; ++i){
		if(r[i]){
			int p = i;
			int S = 0;
			for(; i <= r[p]; ++i){
				if(r[i]) S += r[i] - i;
			}
			--i;
			ans.push_back(S);
		}
	}
	printf("%d\n", sum);
	printf("%d", ans.size());
	for(auto x : ans){
		printf(" %d", x);
	}
	return 0;
}
