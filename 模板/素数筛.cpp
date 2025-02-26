#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
const int MAX=0x20000;
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    Eratosthenes(n);
    for(int i=0;i<head;++i){
        printf("%d ",prime[i]);
    }
    return 0;
}