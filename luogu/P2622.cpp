#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define drep(i, a, b) for(int i = a; i >= (b); --i)
using namespace std;
int read(){
	char c = 0;
	int res = 0;
	bool b = 0;
	while(c < '0' || c > '9'){
		if(c == '-') b = true;
		c = getchar();
	}
	while(c >= '0' && c <='9'){
		res = (res << 3) + (res << 1) + (c - '0');
		c = getchar();
	}
	return b ? -res : res;
}
const int W = (1 << 20);
const int MAXN = 110;
int dis[W];
bool vis[W];
struct trans{
	int a, b;
}tr[MAXN];
queue<int> q;
int main(){
	memset(dis, 0x3f, sizeof(dis));
	int n = read(), m = read();
	rep(i, 1, m){
		tr[i].a = (1 << n) - 1;
		tr[i].b = 0;
		rep(j, 0, n - 1){
			int a = read();
			if(a == 1){
				tr[i].a ^= (1 << j);
			}
			else if(a == -1){
				tr[i].b ^= (1 << j);
			}
		}
	}
	dis[(1 << n) - 1] = 0;
	q.push((1 << n) - 1);
	vis[(1 << n) - 1] = true;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		vis[p] = false;
		rep(i, 1, m){
			int x = p & tr[i].a | tr[i].b;
			if(dis[x] > dis[p] + 1){
				dis[x] = dis[p] + 1;
				if(!vis[x]){
					q.push(x);
					vis[x] = true;
				}
			}
		}
	}
	printf("%d", dis[0] == 0x3f3f3f3f ? -1 : dis[0]);
	return 0;
}
