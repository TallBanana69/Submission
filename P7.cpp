#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int m = 998244353;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B, int t) {

    vector<vector<ll>> mat(t, vector<ll>(t, 0));

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            for (int k = 0; k < t; k++) {
                mat[i][j] = (mat[i][j] + A[i][k] * B[k][j]) % m;
            }
        }
    }
    return mat;
}

vector<vector<ll>> pow(vector<vector<ll>> mat, ll pow, int t) {

    vector<vector<ll>> exp(t, vector<ll>(t, 0));

    for (int i = 0; i < t; i++) {
        exp[i][i] = 1;
    }


    while (pow) {
        if (pow % 2 == 1) {
            exp = multiply(exp, mat, t);
        }
        mat = multiply(mat, mat, t);
        pow = pow/2;
    }

    return exp;
}

ll solve(ll n, int k) {

    vector<ll> F(k, 0);

    if (n == 0) return 1;
    
    if (n <= k) return (1LL << n) % m;

    

    F[0] = 1;
    for (int i = 1; i < k; i++) {
        F[i] = (F[i-1] << 1) % m;
    }

    vector<vector<ll>> T(k, vector<ll>(k, 0));
    for (int i = 0; i < k-1; i++) {
        T[i][i+1] = 1;
    }
    for (int i = 0; i < k; i++) {
        T[k-1][i] = 1;
    }

    vector<vector<ll>> Tn = pow(T, n-k, k);

    ll exp = 0;
    for (int i = 0; i < k; i++) {
        exp = (exp + Tn[k-1][i] * F[k-1-i]) % m;
    }

    return exp;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll N;
        int K;
        cin >> N >> K;
        cout << solve(N, K) << endl;
    }
    return 0;
}
