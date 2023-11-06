#include<bits/stdc++.h>
using namespace std;
const int maxn=4040;
#define ll long long
struct mint
{
	ll a,b;
}s[maxn];
bool cmp(mint x,mint y)
{
	if(x.b!=y.b) return x.b>y.b;
	return x.a>y.a;
}
bool cmp2(mint x,mint y)
{
	return x.a<y.a;
}
int n;
int main()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;++i) scanf("%lld%lld",&s[i].a,&s[i].b);
	sort(s+1,s+n+1,cmp);
	int tot=0;
	ll k_sum=0;
	while(tot!=n)
	{
		sort(s+tot+1,s+n+1,cmp);
		++tot;
		ll k_sum+=s[1].b;
		++ans;
		s[1].a=s[1].b=0;
		while(1)
		{
			sort(s+tot+1,s+n+1,cmp2);
			bool jud=0;
			for(int i=tot;i<=n;++i)
			{
				if(s[i].a<=k_sum)
				{
					++tot;
					k_sum+=s[i].b;
					s[i].a=s[i].b=0;
					jud=1;
				}
			}
			if(!jud) break;
		}
	}
	printf("%d",ans);
	return 0;
}
