#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define LL long long
using namespace std;
LL sum[400040];
LL bj1[400040];
LL bj2[400040];
LL a[100010];
LL mod;
void build(int p,int l,int r){
	bj2[p]=-1;
	if(l==r){
		sum[p]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build((p<<1),l,m);
	build((p<<1)+1,m+1,r);
	sum[p]=sum[p<<1]+sum[(p<<1)+1];
	return;
}
void pushdown(int p,int l,int r){
	int m=(l+r)>>1;
//	if(bj2[p<<1]!=-1){
//		sum[p<<1]*=bj2[p<<1];
//		sum[p<<1]%=mod;
//	}
//	sum[p<<1]+=(((m-l+1)%mod)*bj1[p<<1])%mod;
//	sum[p<<1]%=mod;
//	if(bj2[(p<<1)+1]!=-1){
//		sum[(p<<1)+1]*=bj2[(p<<1)+1];
//		sum[(p<<1)+1]%=mod;
//	}
//	sum[(p<<1)+1]+=(((r-m)%mod)*bj1[(p<<1)+1])%mod;
//	sum[(p<<1)+1]%=mod;
	
	if(bj2[p]!=-1){
		bj1[p<<1]*=bj2[p];
		bj1[p<<1]%=mod;
		bj1[(p<<1)+1]*=bj2[p];
		bj1[(p<<1)+1]%=mod;
		bj2[p<<1]=bj2[p<<1]==-1?bj2[p]:bj2[p<<1]*bj2[p];
		bj2[p<<1]%=mod;
		bj2[(p<<1)+1]=bj2[(p<<1)+1]==-1?bj2[p]:bj2[(p<<1)+1]*bj2[p];
		bj2[(p<<1)+1]%=mod;
		sum[p<<1]*=bj2[p];
		sum[p<<1]%=mod;
		sum[(p<<1)+1]*=bj2[p];
		sum[(p<<1)+1]%=mod;
		bj2[p]=-1;
	}
	bj1[p<<1]+=bj1[p];
	bj1[p<<1]%=mod;
	bj1[(p<<1)+1]+=bj1[p];
	bj1[(p<<1)+1]%=mod;
	sum[p<<1]+=(((m-l+1)%mod)*bj1[p])%mod;
	sum[p<<1]%=mod;
	sum[(p<<1)+1]+=(((r-m)%mod)*bj1[p])%mod;
	sum[(p<<1)+1]%=mod;
	bj1[p]=0;
	return;
}
void upd1(int p,int l,int r,int ll,int rr,LL v){
	if(ll<=l&&r<=rr){
		bj1[p]+=v;
		bj1[p]%=mod;
		LL temp=(r-l+1)*v;
		temp%=mod;
		sum[p]+=temp;
		sum[p]%=mod;
		return;
	}
	if(rr<l||ll>r)return;
	int m=(l+r)>>1;
	pushdown(p,l,r);
	upd1(p<<1,l,m,ll,rr,v);
	upd1((p<<1)+1,m+1,r,ll,rr,v);
	sum[p]=sum[p<<1]+sum[(p<<1)+1];
	sum[p]%=mod;
	return;
}
void upd2(int p,int l,int r,int ll,int rr,LL v){
	if(ll<=l&&r<=rr){
		bj2[p]=bj2[p]==-1?v:bj2[p]*v;
		bj2[p]%=mod;
		bj1[p]*=v;
		bj1[p]%=mod;
		sum[p]*=v;
		sum[p]%=mod;
		return;
	}
	if(rr<l||ll>r)return;
	int m=(l+r)>>1;
	pushdown(p,l,r);
	upd2(p<<1,l,m,ll,rr,v);
	upd2((p<<1)+1,m+1,r,ll,rr,v);
	sum[p]=sum[p<<1]+sum[(p<<1)+1];
	sum[p]%=mod;
	return;
}
LL ask(int p,int l,int r,int ll,int rr){
	if(ll<=l&&r<=rr){
		return sum[p];
	}
	if(rr<l||ll>r)return 0;
	int m=(l+r)>>1;
	pushdown(p,l,r);
	LL ans=0;
	ans+=ask(p<<1,l,m,ll,rr);
	ans%=mod;
	ans+=ask((p<<1)+1,m+1,r,ll,rr);
	ans%=mod;
	return ans;
}
int main(){
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%lld",&mod);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	build(1,1,n);
	while(m--){
		int a;
		scanf("%d",&a);
		if(a==1){
			int l,r;
			LL v;
			scanf("%d%d%lld",&l,&r,&v);
			v%=mod;
			upd2(1,1,n,l,r,v);
		}
		else if(a==2){
			int l,r;
			LL v;
			scanf("%d%d%lld",&l,&r,&v);
			v%=mod;
			upd1(1,1,n,l,r,v);
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",ask(1,1,n,l,r));
		}
	}
	return 0;
}
