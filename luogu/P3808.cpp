#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define mid ((l + r) >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define tmp(a, b) (tmp[a] >> (n - (b)) & 1)
typedef long long ll;
typedef unsigned long long ull;
#define Maxq priority_queue<int,vector<int>,greater<int> >
using namespace std;
int mylog(int a) {
	int ans=0;
	if(a&0xffff0000) {
		ans+=16;
		a>>=16;
	}
	if(a&0x0000ff00) {
		ans+=8;
		a>>=8;
	}
	if(a&0x000000f0) {
		ans+=4;
		a>>=4;
	}
	if(a&0x0000000c) {
		ans+=2;
		a>>=2;
	}
	if(a&0x00000002) {
		ans+=1;
		a>>=1;
	}
	return ans;
}
inline int read() {
	register int a=0,b=0;
	register char c;
	c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')b=1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}
const int MAXN = 1e6 + 10;
int fail[MAXN], tree[MAXN][26], cnt[MAXN], endd;
char tmp[MAXN], s[MAXN];
int ans;
void add(char* t){
	int p = 0;
	int len = strlen(t);
	frep(i, 0, len){
		if(tree[p][t[i] - 'a']) p = tree[p][t[i] - 'a'];
		else{
			tree[p][t[i] - 'a'] = ++endd;
			p = tree[p][t[i] - 'a'];
		}
	}
	++cnt[p];
	return;
}
void build(){
	queue<int> q;
	frep(i, 0, 26){
		if(tree[0][i]) q.push(tree[0][i]);
	}
	while(!q.empty()){
		int p = q.front();
		q.pop();
		frep(i, 0, 26){
			if(tree[p][i]){
				fail[tree[p][i]] = tree[fail[p]][i];
				q.push(tree[p][i]);
			}
			else{
				tree[p][i] = tree[fail[p]][i];
			}
		}
	}
	return;
}
void query(){
	int p = 0;
	int len = strlen(s);
	frep(i, 0, len){
		p = tree[p][s[i] - 'a'];
		for(int j = p; j && cnt[j] != -1; j = fail[j]){
			ans += cnt[j];
			cnt[j] = -1;
		}
	}
	return;
}
int main(){
	int n = read();
	rep(i, 1, n){
		scanf("\n%s", tmp);
		add(tmp);
	}
	build();
	scanf("\n%s", s);
	query();
	printf("%d", ans);
	return 0;
}