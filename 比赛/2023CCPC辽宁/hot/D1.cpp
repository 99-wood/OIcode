#include<bits/stdc++.h>
using namespace std;
int X,Y,X1,Y1,X2,Y2,T;
double ans=1000000;
int main(){
	scanf("%d",&T);
	while(T--){ans=1000000;
		scanf("%d%d%d%d%d%d",&Y,&X,&X1,&Y1,&X2,&Y2);double K=(double)Y/X;
		if(X1*X1+Y1*Y1<X2*X2+Y2*Y2)swap(X1,X2),swap(Y1,Y2);
		cout<<X1<<' '<<Y1<<endl;
		for(int i=1;i<=100;i++){
			if(i==X1){
				if(X1<X2)continue;
				double h=K*X1;cout<<h<<' '<<X1<<endl;
				ans=min(ans,(double)h*X1);
				continue;
			}
			for(int j=100;j>=1;j--){
				double k=(Y1-j)/(X1-i);
				double b=(double)(Y1-k*X1);
				double A=(-b/k);
				if(A<=0)continue;if(K==k)continue;
				if(b*b/(k*k+1)>(X2*X2+Y2*Y2)){
					double h=K*b/(K-k);
					ans=min(ans,A*h);
				}
			}
		}printf("%lf",ans/2.0);
	}
	return 0;
}
