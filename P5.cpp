#include <bits/stdc++.h>
using namespace std;

int sum(string array, int size){
    int sum = 0;
    for (int i=0; i < size; i++){
        sum = sum + int(array[i] - '0');
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int count = 0;
    vector<string> v;  
    for(int x = 0; x < n; x++){
        string temp;
        cin >> temp;
        v.push_back(temp); 
    }
    vector<pair<int, int>> p;
    for (int i=0;i<n;i++){
        int len = v[i].size();
        p.push_back(make_pair(len, sum(v[i], len)));
        if ((v[i].size() == 6) && sum(v[i], len) == 25){
            count++;
        }
    }
    sort(p.begin(), p.end());

    int a = 0;
    int b = n-1;
    while(a < b){
        int sum = p[a].first + p[b].first;
        if(sum == 12){
            if(p[a].second + p[b].second == 50){
                count++;
                count++;
            }
            a++;
            b--;
        }
        else if(sum < 12){
            a++;
        }
        else{
            b--;
        }
    }
    cout<<count;
    return 0;
}
