#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
//priority_queue<int,vector<int>,greater<int> > q;
int mylog(int a){
	int ans=0;
	if(a&0xffff0000){ans+=16;a>>=16;}
	if(a&0x0000ff00){ans+=8;a>>=8;}
	if(a&0x000000f0){ans+=4;a>>=4;}
	if(a&0x0000000c){ans+=2;a>>=2;}
	if(a&0x00000002){ans+=1;a>>=1;}
	return ans;
}
ll read(){
	register ll a=0,b=1;
	register char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')b=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return a*b;
}
int num[100010];
int cut[100010];
int B,cx;
struct Query{
	int l,r,id,ans;
	bool operator < (const struct Query &b) const {
        return l/B==b.l/B?r<b.r:l<b.l;
    }
}ask[100010];
void add(int a){
	cx+=(++cut[a])==1?1:0;
}
void del(int a){
	cx-=(--cut[a])==0?1:0;
}
bool cmp(struct Query a,struct Query b){
	return a.id<b.id;
}
int main(){
	int n=read();
	int q=read();
	rep(i,1,n){
		num[i]=read();
	}
	B=n/sqrt(q);
	rep(i,1,q){
		ask[i].l=read(),ask[i].r=read();
		ask[i].id=i;
	}
	sort(ask+1,ask+1+q);
	int l=1,r=1;
	cx=1;
	cut[num[1]]=1;
	rep(i,1,q){
		while(l>ask[i].l)add(num[--l]);
		while(r<ask[i].r)add(num[++r]);
		while(l<ask[i].l)del(num[l++]);
		while(r>ask[i].r)del(num[r--]);
		ask[i].ans=cx;
	}
	sort(ask+1,ask+1+q,cmp);
	rep(i,1,q){
		printf(ask[i].ans==(ask[i].r-ask[i].l+1)?"Yes\n":"No\n");
	}
	return 0;
	
}
/*
3 6
1 2 1
*/
