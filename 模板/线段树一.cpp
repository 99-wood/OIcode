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
LL sum[4000040];
LL bj[4000040];
LL a[1000010];
void build(int p,int l,int r){
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
void upd(int p,int l,int r,int ll,int rr,LL v){
	if(ll<=l&&r<=rr){
		bj[p]+=v;
		sum[p]+=(r-l+1)*v;
		return;
	}
	if(rr<l||ll>r)return;
	int m=(l+r)>>1;
	bj[p<<1]+=bj[p];
	sum[p<<1]+=bj[p]*(m-l+1);
	bj[(p<<1)+1]+=bj[p];
	sum[(p<<1)+1]+=bj[p]*(r-(m+1)+1);
	bj[p]=0;
	upd(p<<1,l,m,ll,rr,v);
	upd((p<<1)+1,m+1,r,ll,rr,v);
	sum[p]=sum[p<<1]+sum[(p<<1)+1];
	return;
}
LL ask(int p,int l,int r,int ll,int rr){
	if(ll<=l&&r<=rr){
		return sum[p];
	}
	if(rr<l||ll>r)return 0;
	int m=(l+r)>>1;
	bj[p<<1]+=bj[p];
	sum[p<<1]+=bj[p]*(m-l+1);
	bj[(p<<1)+1]+=bj[p];
	sum[(p<<1)+1]+=bj[p]*(r-(m+1)+1);
	bj[p]=0;
	LL ans=0;
	ans+=ask(p<<1,l,m,ll,rr);
	ans+=ask((p<<1)+1,m+1,r,ll,rr);
	return ans;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
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
			upd(1,1,n,l,r,v);
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",ask(1,1,n,l,r));
		}
	}
	return 0;
}
