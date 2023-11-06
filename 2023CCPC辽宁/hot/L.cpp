#include<bits/stdc++.h>
#define L(node) (node<<1)
#define R(node) (node<<1|1)
#define maxn 410001
using namespace std;
struct kkk{
	int l,r,id;
	long long ans;
}q[maxn];
int n,m,block,blocknum;
long long sum1[maxn],sum2[maxn];
int blo[maxn],a[maxn],maxx;
int L,R;long long ans;
bool cmp(kkk a,kkk b){
	if(blo[a.l]!=blo[b.l])return a.l<b.l;
	else return (blo[a.l]&1)?a.r<b.r:a.r>b.r;
}
bool cmpid(kkk x,kkk y){return x.id<y.id;}
void modify(int node,int begin,int end,int x,long long val){
	if(begin==end){
		sum1[node]+=begin*val;
		sum2[node]+=val;
		return ;
	} int mid=(begin+end)>>1;
	if(x<=mid)modify(L(node),begin,mid,x,val);
	else      modify(R(node),mid+1,end,x,val);
	sum1[node]=sum1[L(node)]+sum1[R(node)];
	sum2[node]=sum2[L(node)]+sum2[R(node)];
}
long long query1(int node,int begin,int end,int x,int y){
	if(begin>=x&&end<=y){
		return sum1[node];
	} int mid=(begin+end)>>1;long long ans=0;
	if(x<=mid)ans+=query1(L(node),begin,mid,x,y);
	if(y>mid) ans+=query1(R(node),mid+1,end,x,y);
	return ans;
}
long long query2(int node,int begin,int end,int x,int y){
	if(begin>=x&&end<=y){
		return sum2[node];
	} int mid=(begin+end)>>1;long long ans=0;
	if(x<=mid)ans+=query2(L(node),begin,mid,x,y);
	if(y>mid) ans+=query2(R(node),mid+1,end,x,y);
	return ans;
}
void add(int x){
	int q=query1(1,1,maxx,a[x]+1,maxx),p=query1(1,1,maxx,1,a[x]);
	int t=query2(1,1,maxx,a[x]+1,maxx),y=query2(1,1,maxx,1,a[x]);
	ans+=2*q;ans-=p*2;
	ans-=2*t*a[x];ans+=2*y*a[x];
	modify(1,1,maxx,a[x],1);
}
void del(int x){
	modify(1,1,maxx,a[x],-1);
	int q=query1(1,1,maxx,a[x]+1,maxx),p=query1(1,1,maxx,1,a[x]);
	int t=query2(1,1,maxx,a[x]+1,maxx),y=query2(1,1,maxx,1,a[x]);
	ans-=2*q;ans+=p*2;
	ans+=2*t*a[x];ans-=2*y*a[x];
}
signed main(){
	scanf("%d%d",&n,&m);block=pow(m,2.0/3);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),maxx=max(maxx,a[i]);maxx++;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++)blo[i]=(i-1)/block+1;blocknum=blo[m];
	L=1;R=0;
	for(int i=1;i<=m;i++){
		int l=q[i].l,r=q[i].r;
		while(l<L) add(--L);
		while(r>R) add(++R);
		while(l>L) del(L++);
		while(r<R) del(R--);
		q[i].ans=ans;
	}
	sort(q+1,q+m+1,cmpid);
	for(int i=1;i<=m;i++)printf("%lld\n",q[i].ans);
	return 0;
}
