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
//#include<unordered_map>
#include<chrono>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;
typedef long long ll;
//ll lcm = 1000000007;
const int MAXN = 1010;
bool f[50][MAXN][MAXN];
int a[MAXN];
double S(double a, double b, double c){
	if(c < a + b && c > fabs(a - b)){
		double p=(a+b+c)/2;
    	return sqrt(p*(p-a)*(p-b)*(p-c))*100;
	}
	else return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int W = 0;
	rep(i, 1, n){
		cin >> a[i];
		W += a[i];
	}
	f[0][0][0] = 1;
	rep(i, 1, n){
		rep(j, 0, W / 2){
			rep(k, 0, W / 2){
				if(f[i - 1][j][k]){
					f[i][j][k] = true;
					f[i][j + a[i]][k] = true;
					f[i][j][k + a[i]] = true;
				}
			}
		}
	}
	double ans = -1;
	rep(i, 0, W / 2){
		rep(j, 0, W / 2){
			if(f[n][i][j]){
				ans = max(ans, S(i, j, W - i - j));
			}
		}
	}
	printf("%d", (int)floor(ans));
    return 0;
}
