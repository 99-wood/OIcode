#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
const int MAX=0x20000;
using namespace std;
int prime[MAX];
int head=0;
int number[MAX*10];
void Eratosthenes(int n){
    for(int i=2;i<=n;++i){
        if(number[i]==0){
            number[i]=i;
            prime[head++]=i;
        }
        for(int j=0;j<head&&prime[j]*i<=n;++j){
            if(prime[j]>number[i]){
                break;
            }
            number[prime[j]*i]=prime[j];
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    Eratosthenes(n);
    for(int i=0;i<head;++i){
        printf("%d ",prime[i]);
    }
    return 0;
}