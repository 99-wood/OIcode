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
const int MAXN = 600;
const int MOD = 1e9 + 7;
int set[14], pos[14], m;
int le[14][MAXN], gr[14][MAXN];
int a[MAXN];
int c[MAXN];
bool vis[1 << 14];
void add(int a){
	while(a){
		c[a] += 1;
		a -= a & (-a);
	}
	return;
}
void del(int a){
	while(a){
		c[a] -= 1;
		a -= a & (-a);
	}
	return;
}
int ask(int p){
	int ans = 0;
	while(p <= 500){
		ans += c[p];
		p += p &(-p);
	}
	return ans;
}
vector<int> ans[1 << 14];
vector<int> que[1 << 14];
int check(int a){
	int cnt = 0;
	while(a){
		cnt += a&1;
		a >>= 1;
	}
	return cnt;
}
int main(){
	freopen("inv.in", "r", stdin);
	freopen("inv.out", "w", stdout);
	int n = read(), l = read(), r = read();
	int cnt = 0;
	rep(i, 1, n){
		a[i] = read();
		if(a[i]){
			cnt += ask(a[i]);
			vis[a[i]] = true;
			add(a[i]);
		}
		else{
			pos[m++] = i;
		}
	}
	rep(i, 1, n){
		if(a[i]){
			del(a[i]);
		}
	}
	m = 0;
	l -= cnt;
	r -= cnt;
	rep(i, 1, n){
		if(!vis[i]){
			rep(j, 1, n){
				if(!a[j]){
					le[m][j] = le[m][j - 1];
					gr[m][j] = gr[m][j - 1];
				}
				else{
					le[m][j] = le[m][j - 1] + (a[j] < i);
					gr[m][j] = gr[m][j - 1] + (a[j] > i);
				}
			}
			set[m++] = i;
		}
	}
	if(m <= 7){
		memset(vis, false, sizeof(vis));
		ans[0].push_back(0);
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			int now = q.front();
			q.pop();
			int p = check(now);
			frep(j, 0, m){
				if((1 << j) & now) continue;
				if(!vis[now | (1 << j)]){
					q.push(now | (1 << j));
					vis[now | (1 << j)] = true;
				}
				for(auto x : ans[now]){
					if(x + gr[j][pos[p]] + le[j][n] - le[j][pos[p]] + check(now & ((1 << m) - (1 << j))) > r) continue;
					ans[now | (1 << j)].push_back(x + gr[j][pos[p]] + le[j][n] - le[j][pos[p]] + check(now & ((1 << m) - (1 << j))));
				}
			}
		}
		int cnt = 0;
		for(auto x : ans[(1 << m) - 1]){
			cnt += (l <= x && x <= r);
		}
		printf("%d", cnt % MOD);
	}
	else{
		memset(vis, false, sizeof(vis));
		ans[0].push_back(0);
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			int now = q.front();
			q.pop();
			int p = check(now);
			if(p == 7) continue;
			frep(j, 0, m){
				if((1 << j) & now) continue;
				if(!vis[now | (1 << j)]){
					q.push(now | (1 << j));
					vis[now | (1 << j)] = true;
				}
				for(auto x : ans[now]){
					if(x + gr[j][pos[p]] + le[j][n] - le[j][pos[p]] + check(now & ((1 << m) - (1 << j))) > r) continue;
					ans[now | (1 << j)].push_back(x + gr[j][pos[p]] + le[j][n] - le[j][pos[p]] + check(now & ((1 << m) - (1 << j))));
				}
			}
		}
		memset(vis, false, sizeof(vis));
		que[0].push_back(r);
		q.push(0);
		while(!q.empty()){
			int now = q.front();
			q.pop();
			int p = check(now);
			if(p == m - 7) continue;
			frep(j, 0, m){
				if((1 << j) & now) continue;
				if(!vis[now | (1 << j)]){
					q.push(now | (1 << j));
					vis[now | (1 << j)] = true;
				}
				for(auto x : que[now]){
					if(x - (gr[j][pos[p + 7]] + le[j][n] - le[j][pos[p + 7]] + check(now & ((1 << m) - (1 << j)))) < 0) continue;
					que[now | (1 << j)].push_back(x - (gr[j][pos[p + 7]] + le[j][n] - le[j][pos[p + 7]] + check(now & ((1 << m) - (1 << j)))));
				}
			}
		}
		frep(i, 0, 1 << m){
			if(check(i) == 7){
				sort(ans[i].begin(), ans[i].end());
			}
		}
		ll res = 0;
		frep(i, 0, 1 << m){
			if(check(i) == 7){
				int j = i ^ ((1 << m) - 1);
				int cnt = 0;
				frep(k, 0, m){
					if(j & (1 << k)){
						cnt += check(i & ((1 << m) - (1 << k)));
					}
				}
				for(auto x : que[j]){
					if(x - cnt < 0 || !ans[i].size()) continue;
					int a = 0, b = ans[i].size() - 1;
					while(a < ans[i].size() && ans[i][a] < x - cnt - (r - l)) ++a;
					while(b && ans[i][b] > x - cnt) --b;
//					int a = lower_bound(ans[i].begin(), ans[i].end(), x - cnt - (r - l)) - ans[i].begin();
//					int b = upper_bound(ans[i].begin(), ans[i].end(), x - cnt) - ans[i].begin() - 1;
					if(b >= a) res = (res + (b - a + 1)) % MOD;
				}
			}
		}
		printf("%lld", res);
	}
	return 0;
}