#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
int qpow(int a, int b){
	ll now = a, ans = 1;
	while(b){
		if(b & 1){
			ans = (ans * now) % MOD;
		}
		now = (now * now) % MOD;
		b >>= 1;
	}
	return ans;
}
int inv(int a){
	return qpow(a, MOD - 2);
}
int p;
struct Matrix{
	ll num[11][11];
	struct Matrix operator * (struct Matrix b){
		struct Matrix ans;
		rep(i, 1, 10){
			rep(j, 1, 10){
				ans.num[i][j] = 0;
				rep(k, 1, 10){
					ans.num[i][j] = (ans.num[i][j] + num[i][k] * b.num[k][j]) % MOD;
				}
			}
		}
		return ans;
	};
	void print(){
		rep(i, 1, 10){
			rep(j, 1, 10){
				cout <<num[i][j] << " ";
			}
			cout <<endl;
		}
	}
};
struct Matrix f;
void inil(){
	rep(i, 1, 10){
		rep(j, 1, 10){
			f.num[i][j] = 0;
		}
	}
	f.num[1][1] = p;
	f.num[1][2] = p;
	f.num[1][5] = p;
	f.num[1][10] = p;
	f.num[2][1] = (1 - p + MOD) % MOD;
	f.num[2][4] = (1 - p + MOD) % MOD;
	f.num[2][5] = (1 - p + MOD) % MOD;
	f.num[3][2] = (1 - p + MOD) % MOD;
	f.num[3][3] = (1 - p + MOD) % MOD;
	f.num[4][3] = p;
	f.num[5][4] = p;

	f.num[1 + 5][1 + 5] = p;
	f.num[1 + 5][2 + 5] = p;
	f.num[1 + 5][5 + 5] = p;
	f.num[2 + 5][1 + 5] = (1 - p + MOD) % MOD;
	f.num[2 + 5][4 + 5] = (1 - p + MOD) % MOD;
	f.num[2 + 5][5 + 5] = (1 - p + MOD) % MOD;
	f.num[3 + 5][2 + 5] = (1 - p + MOD) % MOD;
	f.num[3 + 5][3 + 5] = (1 - p + MOD) % MOD;
	f.num[4 + 5][3 + 5] = p;
	f.num[5 + 5][4 + 5] = p;
	return;
}
struct Matrix jzksm(struct Matrix a, int b){
	struct Matrix now = a, ans;
	rep(i, 1, 10){
		rep(j, 1, 10){
			ans.num[i][j] = (i==j);
		}
	}
	while(b){
		if(b & 1){
			ans = ans * now;
		}
		now = now * now;
		now.print();
		b >>= 1;
	}
	return ans;
};
signed main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b, n;
		scanf("%d%d%d", &a, &b, &n);
		p = ((ll)a * inv(b)) % MOD;
		inil();
		struct Matrix ans;
		rep(i, 1, 10){
			rep(j, 1, 10){
				ans.num[i][j] = 0;
			}
		}
		ans.num[6][1] = 1;
		ans = jzksm(f, n) * ans;
		cout << ans.num[1][1] << endl;
	}

	return 0;
}
