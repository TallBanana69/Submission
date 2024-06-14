#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int x = 0; x < T; x++){
        int n, k;
        cin >> n >> k;
        vector<int> height(n);
        for (int i = 0; i < n; i++){
            cin >> height[i];
        }
        sort(height.rbegin(), height.rend());
        int l = 0;
        while(k>0){
            k = k - height[l];
            
            if(k > 0){
                height[l]--;
            }
            if (height[l+1] > height[l] && l!=n-1){
                l++;
            }
            else if (l!=0 && height[l-1] >= height[l]){
                l--;
            }
            else if(l == n-1){
                l = 0;
            }
        }
        int ans;
        if (height[0] < 0){
            height[0] = 0;
        }
        cout << height[0] <<endl;
    }
    return 0;
}
