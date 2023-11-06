#include<bits/stdc++.h>
#define maxn 1001001
using namespace std;
bool f[maxn][3];
int a,b,n,cntA,cntB,T;
int A[maxn],B[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&n);
		f[0][0]=0;f[0][1]=0;cntA=0;cntB=0;
		for(int i=0;a*a*i*i+a*i+1<=n;i++)A[++cntA]=a*a*i*i+a*i+1;
		for(int i=0;b*b*i*i+b*i+1<=n;i++)B[++cntB]=b*b*i*i+b*i+1;
		for(int i=1;i<=n;i++){
			f[i][0]=f[i][1]=0;bool sum1=1,sum2=1;
			for(int j=1;j<=cntA;j++){
				if(i-A[j]<0)break;
				sum1=sum1&f[i-A[j]][1];
				if(sum1==0)break;
			}if(sum1==0)f[i][0]=1;
			for(int j=1;j<=cntB;j++){
				if(i-B[j]<0)break;
				sum2=sum2&f[i-B[j]][0];
				if(sum2==0)break;
			}if(sum2==0)f[i][1]=1;
		}
		for(int i=1;i<=n;i++)cout<<f[i][0]<<endl;
		if(f[n][0])printf("Alice\n");else printf("Bob\n");
	}
	return 0;
}
