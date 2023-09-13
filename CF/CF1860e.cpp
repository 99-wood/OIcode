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
#define ls tree[p].l
#define rs tree[p].r
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
const int MAXSIZE = 30;
const int MAXN = 5e4 + 10;
//vector<int>[MAXSIZE][MAXSIZE];
#define trans(a, b) ((a - 'a') * MAXSIZE + (b - 'a'))
int n;
struct line{
	int nxt, dis;
	line() : nxt(), dis(){}
	line(int nxt, int dis) : nxt(nxt), dis(dis){}
};
vector<struct line> nxt[MAXN + 2000];
vector<struct line> pre[MAXN + 2000];
char str[MAXN];
int dis1[trans('z','z') + 10][MAXN + 2000];
int dis2[trans('z','z') + 10][MAXN + 2000];
deque<int> q;
bool vis[MAXN * 10];
void bfs(char a, char b){
	int tr = trans(a, b);
	dis1[tr][n + tr] = 0;
	q.push_back(n + tr);
	vis[n + tr] = true;
	while(!q.empty()){
		int p = q.front();
		q.pop_front();
		vis[p] = false;
		frep(i, 0, nxt[p].size()){
			int pp = nxt[p][i].nxt, dis = nxt[p][i].dis;
			if(dis1[tr][p] + dis < dis1[tr][pp]){
				dis1[tr][pp] = dis1[tr][p] + dis;
				if(!vis[pp]){
					if(dis){
						q.push_back(pp);
						vis[pp] = true;
					}
					else{
						q.push_front(pp);
						vis[pp] = true;
					}
				}
			}
		}
	}

	dis2[tr][n + tr] = 0;
	q.push_back(n + tr);
	vis[n + tr] = true;
	while(!q.empty()){
		int p = q.front();
		q.pop_front();
		vis[p] = false;
		frep(i, 0, pre[p].size()){
			int pp = pre[p][i].nxt, dis = pre[p][i].dis;
			if(dis2[tr][p] + dis < dis2[tr][pp]){
				dis2[tr][pp] = dis2[tr][p] + dis;
				if(!vis[pp]){
					if(dis){
						q.push_back(pp);
						vis[pp] = true;
					}
					else{
						q.push_front(pp);
						vis[pp] = true;
					}
				}
			}
		}
	}
}
int main(){
	memset(dis1, 0x3f, sizeof(dis1));
	memset(dis2, 0x3f, sizeof(dis2));
	scanf("%s", str + 1);
	n = strlen(str + 1);
	frep(i, 1, n){
		if(i + 1 < n){
			nxt[i].push_back(line(i + 1, 1));
			nxt[i + 1].push_back(line(i, 1));
			pre[i].push_back(line(i + 1, 1));
			pre[i + 1].push_back(line(i, 1));
		}
		nxt[i].push_back(line(n + trans(str[i], str[i + 1]), 1));
		nxt[n + trans(str[i], str[i + 1])].push_back(line(i, 0));
		pre[i].push_back(line(n + trans(str[i], str[i + 1]), 0));
		pre[n + trans(str[i], str[i + 1])].push_back(line(i, 1));
	}
	rep(a, 'a', 'z'){
		rep(b, 'a', 'z'){
			bfs(a, b);
		}
	}
	int m = read();
	while(m--){
		int s = read(), t = read();
		int ans = abs(t - s);
		rep(a, 'a', 'z'){
			rep(b, 'a', 'z'){
				ans = min(ans, dis1[trans(a, b)][s] + dis2[trans(a, b)][t]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}