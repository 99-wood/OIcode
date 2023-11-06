#include<bits/stdc++.h>
#define maxn 1101
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
	f[0][0]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(f[i-1][j-1]){
				if(!jud[i]){
					if(s2[i]=='.'||s2[i]==s1[j])f[i][j]=1;
				} else {char c;
					//f[i][j-1]=1;
					if(s2[i]!='.'){c=s2[i];
						int l=j;
						while(1){
							if(l>n)break;
							if(s1[l]!=c)break;
							f[i][l]=1;++l;
						}
					} else {
						int l=j;
						while(1){
							if(l>n)break;
							f[i][l]=1;++l;
						}
					}
				}
			}
			if(f[i-1][j]&&jud[i])f[i][j]=1;
		}
	}
	if(f[m][n])printf("true");else printf("false");
	return 0;
}
