#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define drep(i, a, b) for(int i = a; i >= (b); --i)
using namespace std;
int read(){
	char c = getchar();
	bool b = false;
	while(c < '0' || c > '9'){
		if(c == '-') b = !b;
		c = getchar();
	}
	int a = 0;
	while(c >= '0' && c <= '9'){
		a *= 10;
		a += c - '0';
		c = getchar();
	}
	return b ? -a : a;
}
const int MAXN = 1e6 + 10;
int n, m;
char s[MAXN];
int sa[MAXN], rk[MAXN], b[MAXN], tp[MAXN << 1];
void rsort(){
	rep(i, 1, m) b[i] = 0;
	rep(i, 1, n) b[rk[i]]++;
	rep(i, 1, m) b[i] += b[i - 1];
	drep(i, n, 1) sa[b[rk[tp[i]]]--] = tp[i];
	return;
}
void SA(){
	n = strlen(s + 1), m = 100;
	rep(i, 1, n){
		rk[i] = s[i] - '0' + 1;
		tp[i] = i;
	}
	rsort();
	for(int k = 1, p = 0; p < n; m = p, k <<= 1){
		p = 0;
		rep(i, 1, k) tp[++p] = n - k + i;
		rep(i, 1, n) if(sa[i] > k) tp[++p] = sa[i] - k;
		rsort();
		rep(i, 1, n) tp[i] = rk[i];
		rk[sa[1]] = p = 1;
		rep(i, 2, n) rk[sa[i]] = tp[sa[i]] == tp[sa[i - 1]] && tp[sa[i] + k] == tp[sa[i - 1] + k] ? p : ++p;
	}
}
int main(){
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	rep(i, 1, len){
		s[i + len] = s[i];
	}
	SA();
	rep(i, 1, len << 1){
		if(sa[i] <= len)
			printf("%c", s[sa[i] + len - 1]);
	}
}
