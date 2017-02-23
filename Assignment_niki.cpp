#include "bits/stdc++.h"

#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)

using namespace std;

typedef long long LL;

const int MOD = 1e9+7;
const int dim = 2;


class Matrix
{
	int mat[dim][dim];

public:
	Matrix(bool flag = true) {
		if(flag) {
			mat[0][0] = 1, mat[0][1] = 1;
			mat[1][0] = 1, mat[1][1] = 0;
		}
		else{
			mat[0][0] = 1, mat[0][1] = 0;
			mat[1][0] = 0, mat[1][1] = 1;
		}
	}

	Matrix operator*(Matrix o) {
		Matrix result(false);
		for (int i = 0; i < dim; ++i)
		{
			REP(j, dim) {
				LL temp = 0;
				REP(k, dim) {
					temp = ((temp%MOD) + ((LL)mat[i][k]*(LL)o.mat[k][j])%MOD)%MOD;
				}
				result.mat[i][j] = temp%MOD;
			}
		}
		return result;
	}

	LL getResult() {
		LL ans = ((LL)mat[0][0]*2 + mat[0][1]*1)%MOD;
		return ans;
	}


	Matrix exponentiation(Matrix fibo, LL n) {
		Matrix res(false);

		while(n > 0) {
			if(n%2)
				res = res*fibo;
			fibo = fibo*fibo;
			n/=2;
		}
		return res;
	}


	void printMatrix() {
		REP(i,2) {
			REP(j,2) {
				cout << this->mat[i][j] << " ";
			}
			cout << endl;
		}
	}
};



LL fib(LL n){
	Matrix fibo(true);
	Matrix result = fibo.exponentiation(fibo, n);
	LL ans = result.getResult();
	return ans;
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	LL t,n, ans = 1;

	cin >> t;

	while(t--){
		cin >> n;
		if(n>=1)
			ans = fib(n-1);
		cout << ans << endl;
	}

	return 0;

}
