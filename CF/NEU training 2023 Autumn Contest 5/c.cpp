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
const int MAXN = 2e5;
int a[20];
bool check(int no){
	int sum = 0;
	rep(i, 0, 9){
		sum += a[i];
	}
	rep(i, 0, 9){
		if(a[i] > (sum >> 1) + (sum & 1)){
			return false;
		}
		if(a[i] == (sum >> 1) + (sum & 1) && (sum & 1) && i == no){
			return false;
		}
	}
	return true;
}
int main(){
	int t = read();
	while(t--){
		int sum = 0;
		rep(i, 0, 9){
			a[i] = read();
			sum += a[i];
		}
		if(sum == 1 && a[0] == 1){
			printf("0\n");
			continue;
		}
		if(!check(0)){
			printf("-1\n");
			continue;
		}
		int last = 0;
		while(sum--){
			rep(i, 0, 9){
				if(i == last) continue;
				if(a[i]){
					--a[i];
					if(check(i)){
						printf("%d", i);
						last = i;
						break;
					}
					else ++a[i];
				}
			}
		}
		printf("\n");
	}
	return 0;
}