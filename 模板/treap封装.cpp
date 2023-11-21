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
const int MAXN = 1000010;
template<typename T>
struct treap{
	struct node{
		T w;
		int rnd, l, r, siz;
		node(T w): w(w), rnd(rand()), l(0), r(0), siz(1){
		}
		node(T w, int siz): w(w), rnd(rand()), l(0), r(0), siz(siz){
		}
		node(): siz(0){
		}
	};
	private:
	vector<struct node> tree;
	int root = 0;
	#define ls tree[p].l
	#define rs tree[p].r
	void upd(int p){
		tree[p].siz = tree[ls].siz + tree[rs].siz + 1;
		return;
	}
	int merge(int x, int y){
		if(!x || !y) return x ^ y;
		if(tree[x].rnd < tree[y].rnd){
			tree[x].r = merge(tree[x].r, y);
			upd(x);
			return x;
		}
		else{
			tree[y].l = merge(x, tree[y].l);
			upd(y);
			return y;
		}
	}
	void split1(int p, T w, int &x, int &y){
		if(!p){
			x = y = 0;
			return;
		}
		if(tree[p].w <= w){
			x = p;
			split1(rs, w, rs, y);
		}
		else{
			y = p;
			split1(ls, w, x, ls);
		}
		upd(p);
		return;
	}
	void split2(int p, int k, int &x, int &y){
		if(!p){
			x = y = 0;
			return;
		}
		if(tree[ls].siz + 1 <= k){
			x = p;
			split2(rs, k - (tree[ls].siz + 1), rs, y);
		}
		else{
			y = p;
			split2(ls, k, x, ls);
		}
		upd(p);
	}
	public:
	treap(T v){
		tree.push_back(node(v, 0));
		return;
	}
	~treap(){
		tree.clear();
		return;
	}
	void add(T w){
		tree.push_back(node(w));
		int x, y;
		split1(root, w, x, y);
		root = merge(merge(x, tree.size() - 1), y);
		return;
	}
	T kth(int k){
		int x, y, z;
		split2(root, k, x, z);
		split2(root, k - 1, x, y);
		T ans = tree[y].w;
		root = merge(merge(x, y), z);
		return ans;
	}
	int maxp(int p){
		if(rs) return maxp(rs);
		else return p;
	}
	int minp(int p){
		if(ls) return minp(ls);
		else return p;
	}
	T max(int p){
		return tree[maxp(p)].w;
	}
	T min(int p){
		return tree[minp(p)].w;
	}
	T pre(T w){
		int x, y;
		split1(root, w, x, y);
		T ans = max(x);
		root = merge(x, y);
		return ans;
	}
	T nxt(T w){
		int x, y;
		split1(root, w, x, y);
		T ans = min(y);
		root = merge(x, y);
		return ans;
	}
	void del(T w){
		int x, y;
		split1(root, w, x, y);
		T ans = max(x);
		if(ans == w){
			int tmp;
			split2(x, tree[x].siz - 1, x, tmp);
			root = merge(x, y);
			return;
		}
		else return;
	}
	#undef ls
	#undef rs
};
struct node{
	int w, id;
	bool operator < (node b){
		return w < b.w;
	}
	bool operator == (node b){
		return w == b.w;
	}
	bool operator <= (node b){
		return (*this) < b || (*this) == b;
	}
	node(int w, int id) : w(w), id(id){
	}
	node(){
	}
};
treap<node> t(node(-1, -1));
struct in{
	int x, y, id;
	in(){
	}
	in(int x, int y, int id): x(x), y(y), id(id){
	}
}input[MAXN];
int ans[MAXN];
int main(){
	int n = read();
	rep(i, 1, n){
		int x = read(), y = read();
		input[i] = in(x, y, i);
	}
	sort(input + 1, input + n + 1, [&](in a, in b){
		return a.x < b.x;
	});
	int cnt = 0;
	rep(i, 1, n){
		struct node now = t.pre(node(input[i].x - 1, 0x3f3f3f3f));
		if(now == node(-1, -1)){
			t.add(node(input[i].y, ++cnt));
			ans[input[i].id] = cnt;
		}
		else{
			t.del(now);
			t.add(node(input[i].y, now.id));
			ans[input[i].id] = now.id;
		}
	}
	printf("%d\n", cnt);
	rep(i, 1, n){
		printf("%d ", ans[i]);
	}
	return 0;
}
