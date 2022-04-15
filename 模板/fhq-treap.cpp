#include<iostream>
#include<cstdio>
#include<cstdlib>
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
typedef long long ll;
typedef unsigned long long ull;
#define Maxq priority_queue<int,vector<int>,greater<int> >
using namespace std;
int mylog(int a){
	int ans=0;
	if(a&0xffff0000){
		ans+=16;
		a>>=16;
	}
	if(a&0x0000ff00){
		ans+=8;
		a>>=8;
	}
	if(a&0x000000f0){
		ans+=4;
		a>>=4;
	}
	if(a&0x0000000c){
		ans+=2;
		a>>=2;
	}
	if(a&0x00000002){
		ans+=1;
		a>>=1;
	}
	return ans;
}
inline int read(){
	register int a=0,b=0;
	register char c;
	c=getchar();
	while(c<'0'||c>'9'){
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
const int MAXN = 200010;
int siz[MAXN], val[MAXN], rnd[MAXN], tree[MAXN][2], root, endd;
void upd(int p){
	if(p == 0){
		siz[p] = 0;
		return;
	}
	siz[p] = siz[tree[p][0]] + siz[tree[p][1]] + 1;
	return;
}
void split1(int p, int w, int &x, int &y){
	//权值裂开
	if(!p){
		x = 0;
		y = 0;
	}
	else if(val[p] <= w){
		x = p;
		split1(tree[p][1], w, tree[p][1], y);
	}
	else{
		y = p;
		split1(tree[p][0], w, x, tree[p][0]);
	}
	upd(p);
	return;
}
void split2(int p, int k, int &x, int &y){
	//排名裂开
	if(!p){
		x = 0;
		y = 0;
	}
	else if(siz[tree[p][0]] + 1 <= k){
		x = p;
		split2(tree[p][1], k - (siz[tree[p][0]] + 1), tree[p][1], y);
	}
	else{
		y = p;
		split2(tree[p][0], k, x, tree[p][0]);
	}
	upd(p);
	return;
}
int merge(int a, int b){
	if(!a || !b) return a + b;
	if(rnd[a] < rnd[b]){
		tree[a][1] = merge(tree[a][1], b);
		upd(a);
		return a;
	}
	else{
		tree[b][0] = merge(a, tree[b][0]);
		upd(b);
		return b;
	}
}
void add(int a){
	++endd;
	siz[endd] = 1;
	val[endd] = a;
	rnd[endd] = rand();
	int x = 0, y = 0;
	split1(root, a, x, y);
	root = merge(merge(x, endd), y);
	return;
}
void del(int a){
	int x = 0, y = 0, z = 0;
	split1(root, a - 1, x, z);
	split1(z, a, y, z);
	root = merge(merge(x, merge(tree[y][0], tree[y][1])), z);
	return;
}
int myrank(int a){
	int x = 0, y = 0;
	split1(root, a - 1, x, y);
	int ans = siz[x] + 1;
	root = merge(x, y);
	return ans;
}
int fmin(int p){
	if(p == 0) return 0x7f7f7f7f;
	else return min(val[p], fmin(tree[p][0]));
}
int fmax(int p){
	if(p == 0) return -0x7f7f7f7f;
	else return max(val[p], fmax(tree[p][1]));
}
int kth(int k){
	int x = 0, y = 0;
	split2(root, k, x, y);
	int ans = fmax(x);
	root = merge(x, y);
	return ans;
}
int pre(int a){
	int x = 0, y = 0;
	split1(root, a - 1, x, y);
	int ans = fmax(x);
	root = merge(x, y);
	return ans;
}
int nxt(int a){
	int x = 0, y = 0;
	split1(root, a, x, y);
	int ans = fmin(y);
	root = merge(x, y);
	return ans;
}
int main(){
	int q = read();
	while(q--){
		int op = read(), x = read();
		if(op == 1){
			add(x);
		}
		else if(op == 2){
			del(x);
		}
		else if(op == 3){
			printf("%d\n", myrank(x));
		}
		else if(op == 4){
			printf("%d\n", kth(x));
		}
		else if(op == 5){
			printf("%d\n", pre(x));
		}
		else{
			printf("%d\n", nxt(x));
		}
	}
	return 0;
}