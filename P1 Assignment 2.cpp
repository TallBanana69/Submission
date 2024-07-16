#include <bits/stdc++.h>
#define read(x) int x; cin >> x 
using namespace std;

int main() {
    int m= 1e9+7;
    read(n);
    read(x);
    vector<int> array(n);
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }

    vector<vector<int>> table(n+1,vector<int>(x+1,0));
    table[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {

            table[i][j] = table[i-1][j];
            int left = j-array[i-1];

            if (left >= 0) {
                (table[i][j] += table[i][left]) %= m;
            }
        }
    }
    cout << table[n][x];
}