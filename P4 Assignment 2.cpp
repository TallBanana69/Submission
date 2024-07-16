#include <iostream>
#include <vector>
#define read(x) int x; cin >> x
using namespace std;

int main() {
    read(n);
    read(m);

    vector<vector<int>> list(n);
    vector<bool> visit(n, false);
    
    for (int i = 0; i < m; i++) {
        read(x);
        read(y);
        x--;
        y--;
        list[x].push_back(y);
        list[y].push_back(x);
    }
    
    vector<pair<int, int>> connect;
    
    for (int i = 0; i < n; i++) {
        if (visit[i] == false) {
            if (i > 0) {
                connect.push_back({i - 1, i});
            }
            //DFS
            vector<int> stack;
            stack.push_back(i);
            while (!stack.empty()) {
                int node = stack.back();
                stack.pop_back();
                if (!visit[node]) {
                    visit[node] = true;
                    for (int j = 0; j < list[node].size(); j++) {
                        int neighbor = list[node][j];
                        if (!visit[neighbor]) {
                            stack.push_back(neighbor);
                        }
                    }
                }
            }
        }
    }
    
    cout << connect.size() << endl;
    for (int i = 0; i < connect.size(); i++) {
        cout << connect[i].first + 1 << " " << connect[i].second + 1 << endl;
    }
    
    return 0;
}
