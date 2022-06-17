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
#include<bitset>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
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
	while(c>='0'&&c<='9'){
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}
const int MAXN = 6e5 + 10;
struct node{
	int l, r, cnt;
} trie[MAXN * 100];
int a[MAXN], s[MAXN], root[MAXN], endd;
#define ls trie[p].l
#define rs trie[p].r
int clone(int p){
	trie[++endd] = trie[p];
	return endd;
}
int insert(int p, int x, int dep){
	p = clone(p);
	++trie[p].cnt;
	if(!dep) return p;
	if((x >> (dep - 1)) & 1) rs = insert(rs, x, dep - 1);
	else ls = insert(ls, x, dep - 1);
	return p;
}
int query(int p1, int p2, int x, int dep){
	if(!dep) return 0;
	if(trie[trie[p2].r].cnt - trie[trie[p1].r].cnt == 0)  return query(trie[p1].l, trie[p2].l, x, dep - 1);
	else if(trie[trie[p2].l].cnt - trie[trie[p1].l].cnt == 0) return (1 << (dep - 1)) | query(trie[p1].r, trie[p2].r, x, dep - 1);
	else if(((x >> (dep - 1)) & 1) ^ 1) return (1 << (dep - 1)) | query(trie[p1].r, trie[p2].r, x, dep - 1);
	else return query(trie[p1].l, trie[p2].l, x, dep - 1);
}
int main(){
	int n = read(), m = read();
	++n;
	root[1] = insert(0, 0, 24);
	rep(i, 2, n){
		a[i] = read();
		s[i] = s[i - 1] ^ a[i];
		root[i] = insert(root[i - 1], s[i], 24);
	}
	rep(i, 1, m){
		char c;
		scanf("\n%c", &c);
		if(c == 'A'){
			a[++n] = read();
			s[n] = s[n - 1] ^ a[n];
			root[n] = insert(root[n - 1], s[n], 24);
		}
		else{
			int x = read(), y = read(), w = read();
			++x; ++y;
			printf("%d\n", query(root[x - 2], root[y - 1], w ^ s[n], 24) ^ w ^ s[n]);
		}
	}
	return 0;
}