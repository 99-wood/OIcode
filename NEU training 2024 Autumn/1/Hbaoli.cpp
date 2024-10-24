#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
	int T=10;
	srand(time(0));
	while(1){
		int n=rand()%1000,m=rand()%1000;
		cout<<n<<"AND"<<m<<endl;bool flag=0;
		int G=__gcd(n,m);
		cout<<G<<'&'<<n-G<<endl;
		for(int i=1;i<=n;i++){
			int x=i,y=n-i;
			if(x*y/__gcd(x,y)==m){
				cout<<"ANSWER"<<x<<' '<<y<<endl;
				flag=1;
			}
		}
		if(flag==1){T--;getchar();}
	}
}
