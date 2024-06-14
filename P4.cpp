#include <bits/stdc++.h>
using namespace std;

int oreo(int n, int k, vector<int>& num, vector<int>& cost, vector<vector<int>>& store){
    if(store[n][k] != -1){
        return store[n][k];
    }
    if (n == 0 || k == 0){
        return store[n][k] = 0;
    }
    else if(cost[n-1] > k){
        return store[n][k] = oreo(n-1, k, num, cost, store);
    }
    else{
        int a = oreo(n-1, k, num, cost, store);
        int b = num[n-1] + oreo(n-1, k-cost[n-1], num, cost, store);
        return store[n][k] = max(a, b);
    }
}

int main() {
    int T;
    cin >> T;
    for(int x = 0; x < T; x++){
        int n, k;
        cin >> n >> k;
        vector<int> cost(n);
        vector<int> num(n);
        vector<vector<int>> store(n+1, vector<int>(k+1, -1));
        for (int i = 0; i < n; i++){
            cin >> cost[i] >> num[i];
        }
        cout << oreo(n, k, num, cost, store) << endl;
    }
    return 0;
}
