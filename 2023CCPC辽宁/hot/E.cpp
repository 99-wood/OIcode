#include<bits/stdc++.h>
#define maxn 21000001
using namespace std;
int n,m,mod;
long long mul[maxn],inv[maxn],mul_inv[maxn],ans;
long long C(int n,int m){
	if(n<m)return 0;
	return (mul[n]%mod*((mul_inv[n-m]%mod*mul_inv[m]%mod)%mod)%mod)%mod;
}
long long lucas(int n,int m){
	if(m==0)return 1;
	return C(n%mod,m%mod)*lucas(n/mod,m/mod)%mod;
}
int main(){
	scanf("%d%d%d",&n,&m,&mod);int N=n%mod;mod=19260817;
	int a=(n-m+1)/2;if(m>=a){printf("0");return 0;}
	mul[0]=1;mul_inv[0]=1;inv[1]=1;
	for(int i=1;i<=mod;i++)mul[i]=mul[i-1]*i%mod;
	for(int i=2;i<=mod;i++)inv[i]=(mod-mod/i)%mod*inv[mod%i]%mod;
	for(int i=1;i<=mod;i++)mul_inv[i]=mul_inv[i-1]%mod*inv[i]%mod;
	for(int i=1;i<=a-m;i++)ans+=C(n-m-i,i-1),ans%=mod;
	printf("%d",ans%17);
	return 0;
}
