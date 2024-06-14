#include <bits/stdc++.h>
using namespace std;

int steps(int x, int y){
    int count = 2*(y - 1) ;
    int x_loop = 1;
    x_loop = x_loop + (y-1);
    if ((x + x_loop)%2 == 0){
        count = count + 2*(x - x_loop);
    }
    else{
        count = count + 2*(x - x_loop) - 1;
    }
    return count;
}

int main() {
    int n, m, ans;
    cin >> n >> m;
    if(m >= n){
        ans = steps(n, m);
    }
    else{
        ans = steps(m, n);
    }
    cout << ans;
    return 0;
}
