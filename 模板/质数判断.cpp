#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
bool isprime(int n){
	int sqrtt=sqrt(n);
	for(int i=2;i<=sqrtt;++i){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%s",isprime(n)?"prime":"no");
    return 0;
}
