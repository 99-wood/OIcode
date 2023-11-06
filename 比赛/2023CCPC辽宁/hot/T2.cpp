#include<bits/stdc++.h>
using namespace std;
double x;int n,X,Y;
int main(){
	scanf("%lf",&x);X=x*100;x/=100;  n=3000;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			double y=(double)j/i;
			int Y=round(y*10000.0);
			if(X==Y){
				printf("%d",i);
				return 0;
			}
		}
	}
}
