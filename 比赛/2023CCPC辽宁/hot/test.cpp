#include<iostream>
#define maxn 1001
using namespace std;
int n,m,x[maxn],y[maxn],ans,max1,max2;
char s1[maxn],s2[maxn],a[maxn];
bool f[maxn][maxn];
bool jud[maxn];
int main()
{
	scanf("%s",s1+1);
	scanf("%s",a+1);
	n=strlen(s1+1);
	int len=strlen(a+1);
	m=0;
	f[0][0]=1;
	for(int i=1;i<=len;++i)
	{
		if(a[i+1]=='*')
		{
			s2[++m]=a[i];
			jud[m]=1;
			++i;
		}
		else s2[++m]=a[i];
	}
	for(int j=1;j<=m;++j)//s1
	{
		for(int i=1;i<=n;++i)//s2
		{
			if(!jud[j])
			{
				if(s2[j]=='.' || s1[i]==s2[j]) f[i][j]|=f[i-1][j-1];
				if(i==3 && j==2) printf("%d ",f[3][2]);
			}
			else
			{
				if(s2[j]=='.' || s1[i]==s2[j])
				{
					int l=i;
					while((s1[l]==s2[j] || s2[j]=='.') &&l<=n)
					{
						f[l][j]|=f[l-1][j-1];
						++l;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j) printf("%d ",f[i][j]);
		printf("\n\n");
	}
	if(f[n][m]) printf("true");
	else printf("false");
	return 0;
}
