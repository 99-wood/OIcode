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
const int MAXN = 100;
char str[MAXN][MAXN];
//char enable[10][10][10] = {
//	{"11", "10"},{"11", "01"},{"10", "11"},{"01", "11"},
//}
bool vis[MAXN][MAXN];
int cnt = 0;
int n, m;
bool enable(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m && !vis[x][y] && str[x][y] == '*';
}
bool enable_(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m && vis[x][y];
}
int sx, sy;
void dfs(int x, int y){
	++cnt;
	if(cnt > 3) return;
	vis[x][y] = true;
	rep(i, x - 1, x + 1){
		rep(j, y - 1, y + 1){
			if(enable(i, j)){
				if(abs(i - sx) > 1 || abs(j - sy) > 1){
					cnt = 100;
					return;
				}
				else dfs(i, j);
			}
		}
	}
//	vis[x][y] = false;
	return;
}
//void clean(int x, int y){
////	++cnt;
////	if(cnt > 3) return;
//	vis[x][y] = false;
//	rep(i, x - 1, x + 1){
//		rep(j, y - 1, y + 1){
//			if(enable_(i, j)) clean(i, j);
//		}
//	}
////	vis[x][y] = false;
//	return;
//}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int t;
	scanf("%d", &t);
	while(t--){
//		int n, m;
		memset(str, 0, sizeof(str));
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &m);
		rep(i, 1, n){
			scanf("\n%s", str[i] + 1);
		}
		bool flag = true;
		rep(i, 1, n){
			rep(j, 1, m){
				if(enable(i, j)){
					cnt = 0;
//					clean(i, j);
					sx = i;
					sy = j;
					dfs(i, j);
					if(cnt == 3){
						int p = i, q = j;
						int js = (int)(str[i - 1][j] == '*') + (int)(str[i + 1][j] == '*') + (int)(str[i][j - 1] == '*') + (int)(str[i][j + 1] == '*');
//						if(js == 1){
//							if(str[i - 1][j] == '*'){
//								p = i - 1;
//								q = j;
//							}
//							if(str[i + 1][j] == '*'){
//								p = i + 1;
//								q = j;
//							}
//							if(str[i][j - 1] == '*'){
//								p = i;
//								q = j - 1;
//							}
//							if(str[i][j + 1] == '*'){
//								p = i;
//								q = j + 1;
//							}
//						}
						if(js == 0){
							flag = false;
							break;
						}
						if(js == 1 && str[i][j + 1] == '*' && str[i + 1][j - 1] == '*'){
							flag = false;
							break;
						}
					}
					else{
						flag = false;
						break;
					}
				}
			}
			if(!flag) break;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}
