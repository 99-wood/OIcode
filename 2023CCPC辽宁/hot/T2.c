#include<bits/stdc++.h>
using namespace std;
int main(){
	scanf("%lf",&x);n=3000;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			double y=(double)j/i;
			if(fabs(y-x)<=0.00001){
				printf("%d",i);
				return 0;
			}
		}
	}
}
