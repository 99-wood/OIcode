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
const int MAXM = 100010;
const int MOD = 1e9 + 7;
struct Matrix{
	int n, m;
	int **data;
	Matrix(int e) : n(e), m(e){
		data = new int*[n + 1];
		rep(i, 0, n){
			data[i] = new int[m + 1];
		}
		rep(i, 1, n){
			data[i][i] = 1;
		}
	}
	Matrix(int n, int m) : n(n), m(m){
		data = new int*[n + 1];
		rep(i, 0, n){
			data[i] = new int[m + 1];
		}
	}
	Matrix(const Matrix & other) : n(other.n), m(other.m){
		data = new int*[n + 1];
		rep(i, 0, n){
			data[i] = new int[m + 1];
		}
		rep(i, 1, n){
			rep(j, 1, m){
				data[i][j] = other.data[i][j];
			}
		}
	}
	~Matrix(){
		rep(i, 0, n){
			delete[] data[i];
		}
		delete[] data;
	}
	Matrix& operator= (const Matrix & other){
		if(&other == this) return *this;
		rep(i, 0, n){
			delete[] data[i];
		}
		delete[] data;
		n = other.n;
		m = other.m;
		data = new int*[n + 1];
		rep(i, 0, n){
			data[i] = new int[m + 1];
		}
		rep(i, 1, n){
			rep(j, 1, m){
				data[i][j] = other.data[i][j];
			}
		}
		return *this;
	}
	Matrix operator* (const Matrix &other){
		Matrix ans(n, other.m);
//		ans.n = n;
//		ans.m = other.m;
		rep(i, 1, ans.n){
			rep(j, 1, ans.m){
				ans.data[i][j] = 0;
				rep(k, 1, m){
					ans.data[i][j] = ((ll)ans.data[i][j] + (ll)data[i][k] * other.data[k][j] % MOD) % MOD;
					if(ans.data[i][j] < 0){
						cout << 1;
					}
				}
			}
		}
		return ans;
	}
};
Matrix ksm(Matrix a, int k){
	if(k == 0) return Matrix(a.n);
	if(k == 1) return a;
	if(k & 1){
		Matrix tmp = ksm(a, k >> 1);
		return tmp * tmp * a;
	}
	else{
		Matrix tmp = ksm(a, k >> 1);
		return tmp * tmp;
	}
}
int s[MAXM], l[MAXM];
signed main(){
	int m = read(), n = read();
	rep(i, 1, m) s[i] = read();
	rep(i, 1, m) l[i] = read();
	Matrix A(m, 2), B(2, m);
	rep(i, 1, m){
		A.data[i][1] = s[i] + l[i];
		A.data[i][2] = l[i];
	}
	rep(i, 1, m){
		B.data[1][i] = s[i] + l[i];
		B.data[2][i] = MOD - l[i];
	}
	Matrix a0(m, 1);
	rep(i, 2, m) a0.data[i][1] = 0;
	a0.data[1][1] = 1;
	Matrix tmp = ksm(B * A, n - 1) * B * a0;
	Matrix ans = A * tmp;
	ll sum = 0;
	rep(i, 1, m) sum += ans.data[i][1];
	printf("%lld", sum % MOD);
    return 0;
}
