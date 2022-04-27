#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define frep(i,a,b) for(int i=(a);i<(b);++i)
#define drep(i,a,b) for(int i=(a);i>=(b);--i)
#define fdrep(i,a,b) for(int i=(a);i>(b);--i)
using namespace std;
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
#define Qmin priority_queue<int,vector<int> ,less<int> >
#define Qmax priority_queue<int,vector<int> ,greater<int> >
int mylog(int a){
	int ans=0;
	if(a&0xffff0000){ans+=16;a>>=16;}
	if(a&0x0000ff00){ans+=8;a>>=8;}
	if(a&0x000000f0){ans+=4;a>>=4;}
	if(a&0x0000000c){ans+=2;a>>=2;}
	if(a&0x00000002){ans+=1;a>>=1;}
	return ans;
}
ll mapp[1000][1000];
ll flow[1000];
bool vis[1000];
int deep[1000];
int cut[1000];
queue<int>q;
ll m,n,s,t;
ll ans=0;
ll dfs(int p,bool &flag){
//	cout<<p<<" ";
//	printf("%d ",p);
	if(p==t){
		flag=true;
		ans+=flow[p];
		return flow[p];
	}
	if(deep[p]>=deep[t])return 0;
	ll reduce=0;
	if(cut[p]==0)cut[p]=1;
	rep(i,cut[p],n){
		if(deep[i]!=deep[p]+1)continue;
		flow[i]=min(flow[p],mapp[p][i]);
		ll re=dfs(i,flag);
		reduce+=re;
		mapp[i][p]+=re;
		mapp[p][i]-=re;
		flow[p]-=re;
		cut[p]=i;
		if(flow[p]==0)break;
	}
	return reduce;
}
int main(){
	n=read(),m=read(),s=read(),t=read();
	rep(i,1,m){
		ll u=read(),v=read(),w=read();
		mapp[u][v]+=w;
	}
	bool flag=false;
	do{
		flag=false;
		memset(vis,false,sizeof(vis));
//		memset(flow,0,sizeof(flow));
		memset(deep,0,sizeof(deep));
		memset(cut,0,sizeof(cut));
		while(!q.empty()){
			q.pop();
		}
		q.push(s);
		deep[s]=0;
		vis[s]=true;
		while(!q.empty()){
			int p=q.front();
			q.pop();
			rep(i,1,n){
				if(vis[i]||mapp[p][i]==0)continue;
				vis[i]=true;
				q.push(i);
				deep[i]=deep[p]+1;
			}
		}
		if(deep[t]==0)break;
		flow[s]=1e16;
		dfs(s,flag);
	}while(flag);
	printf("%lld",ans);
	return 0;
}
/*
4 5 2 3
2 1 100
1 3 100
1 4 1
2 4 100
4 3 100
*/
//dinicºúÓÅ»¯ 
