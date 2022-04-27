#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define ll long long
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
//priority_queue<int,vector<int>,greater<int> > q;
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
int in = -1;
inline ll read() {
	if(in!=-1) {
		int temp = in;
		in = -1;
		return temp;
	}
	register ll a=0,b=1;
	register char c;
	c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')b=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return a*b;
}
const int MAXN = 100010;
int ch[MAXN][2], fa[MAXN], val[MAXN], cnt[MAXN], size[MAXN], rt = 0, tot = 0;

void print(int p) {
	if(ch[p][0])print(ch[p][0]);
	printf("%d %d %d\n",val[p],ch[p][0],ch[p][1]);
	if(ch[p][1])print(ch[p][1]);
}

//change the size of x
void maintain(int x) {
	size[x] = size[ch[x][0]] + size[ch[x][1]] + cnt[x];
	return;
}

//get the x's position of its father
bool get(int x) {
	return x == ch[fa[x]][1];
}

//clear x
void clear(int x) {
	ch[x][0] = ch[x][1] = fa[x] = val[x] = size[x] = cnt[x] = 0;
	return;
}

//rotate x
void rotate(int x) {
	int y = fa[x], z = fa[y], chk = get(x);
	ch[y][chk] = ch[x][chk ^ 1];
	if(ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y;
	ch[x][chk ^ 1] = y;
	fa[y] = x;
	fa[x] = z;
	if(z) ch[z][y == ch[z][1]] = x;
	maintain(y);
	maintain(x);
	return;
}

// splay x
void splay(int x) {
	for(int f = fa[x]; f = fa[x],f; rotate(x)) {
		if(fa[f]) rotate(get(x) == get(f) ? f : x);
	}
	rt = x;
	return;
}

// add x
void add(int x) {
	if(!rt) {
		val[++tot] = x;
		++cnt[tot];
		rt = tot;
		maintain(rt);
		return;
	}
	int cur = rt, f = 0;
	while(true) {
		if(val[cur] == x) {
			maintain(cur);
			maintain(f);
			++cnt[cur];
			splay(cur);
			break;
		}
		f = cur;
		cur = ch[cur][val[cur] < x];
		if(!cur) {
			val[++tot] = x;
			++cnt[tot];
			fa[tot] = f;
			ch[f][val[f] < x] = tot;
			maintain(tot);
			maintain(f);
			splay(tot);
			break;
		}
	}
	return;
}

//the rank of x
int rk(int x) {
	int cur = rt, ans = 0;
	while(true) {
		if(x < val[cur])cur = ch[cur][0];
		else {
			ans += size[ch[cur][0]];
			if(val[cur] == x) {
				splay(cur);
				return ans+1;
			}
			ans += cnt[cur];
			cur = ch[cur][1];
		}
	}
}

//the position whose rank is x
int kth(int x) {
	int cur = rt;
	while(true) {
		if(ch[cur][0] && size[ch[cur][0]]>=x) {
			cur = ch[cur][0];
		} else {
			x -= size[ch[cur][0]] + cnt[cur];
			if(x <= 0) {
				splay(cur);
				return cur;
			}
			cur = ch[cur][1];
		}
	}
}

int pre() {
	int cur = ch[rt][0];
	while(ch[cur][1]) {
		cur = ch[cur][1];
	}
	splay(cur);
	return cur;
}

int nxt() {
	int cur = ch[rt][1];
	while(ch[cur][0]) {
		cur = ch[cur][0];
	}
	splay(cur);
	return cur;
}

//delate x 
void del(int x) {
	rk(x);
	if(cnt[rt]>1) {
		--cnt[rt];
		maintain(rt);
		return;
	}
	if(!ch[rt][0] && !ch[rt][1]) {
		clear(rt);
		rt = 0;
		return;
	}
	if(!ch[rt][0]) {
		int cur = rt;
		rt = ch[rt][1];
		fa[rt] = 0;
		clear(cur);
		return;
	}
	if(!ch[rt][1]) {
		int cur = rt;
		rt = ch[rt][0];
		fa[rt] = 0;
		clear(cur);
		return;
	}
	int cur = rt, pr = pre();
	fa[ch[cur][1]] = pr;
	ch[pr][1] = ch[cur][1];
	clear(cur);
	maintain(rt);
	return;
}
int main() {
	int t = read();
	while(t--) {
		int opt = read(), v = read();
		if(opt == 1) add(v);
		if(opt == 2) del(v);
		if(opt == 3) printf("%d\n",rk(v));
		if(opt == 4) printf("%d\n",val[kth(v)]);
		if(opt == 5) {
			add(v);
			printf("%d\n",val[pre()]);
			del(v);
		}
		if(opt == 6) {
			add(v);
			
			printf("%d\n",val[nxt()]);
			del(v);
		}
	}
	return 0;
}
