#include<bits/stdc++.h>
#define maxn 1000001
using namespace std;
int fa[maxn],a[maxn];
int c[1010][1010];
int T,n,m;
int find(int x){return x==fa[x]?fa[x]:fa[x]=find(fa[x]); }
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x!=y){
		fa[x]=y;
	}
}
int main(){
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		scanf("%d",&c[i][j]);
	}
	while(T--){
		scanf("%d",&m);int ans=0;
		for(int i=1;i<=m;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)fa[i]=i;
		for(int i=1;i<=m-1;i++){
			if(c[a[find(i)]][a[find(i+1)]]==0){
				merge(find(i),find(i+1));
			}
		}
		for(int i=m-1;i>=1;i--){
			if(c[a[find(i)]][a[find(i+1)]]==0){
				merge(find(i),find(i+1));
			}
		}
		for(int i=1;i<=m;i++)ans^=a[find(i)];
		printf("%d\n",ans);
	}
}
