#include<bits/stdc++.h>
using namespace std;
const int maxn=5050;
#define ll long long
ll a[maxn];
int n;
int main()
{
	ll ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=2;i<=n-1;++i)
	{
		ll now=a[i];
		ll maxx1=0;
		int maxp1=0;
		ll maxx2=0;
		int maxp2=0;
		for(int l=i+1;l<=n;++l)
		{
			ll dis=min(a[l],now)*(l-i);
			if(dis>maxx1)
			{
				maxx1=dis;
				maxp1=l;
			}
		}
		for(int l=1;l<=i-1;++l)
		{
			ll dis=min(a[l],now)*(i-l);
			if(dis>maxx2)
			{
				maxx2=dis;
				maxp2=l;
			}
		}
		if(a[maxp1]>a[i] && a[maxp2]>a[i])
		{
			ll t=min(a[maxp1],a[maxp2])*(maxp1-maxp2);
			ans=max(ans,t);
		}
		ans=max(ans,maxx1+maxx2);
	}
	printf("%lld",ans);
	return 0;
}
