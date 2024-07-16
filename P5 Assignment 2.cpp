#include <bits/stdc++.h>
#define read(x) int x; cin >> x 
#define INF 1e18
#define pii pair<long long, int>
using namespace std;



void dijkstra(int n, vector<vector<pii>>& graph) {

    vector<long long> dist(n + 1, INF);
    vector<int> visited(n + 1, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

 
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        int u = top.second;
        long long d = top.first;

       
        if (visited[u]) continue;
        visited[u] = 1;

    
        for (pii edge : graph[u]) {
            int v = edge.second;
            long long weight = edge.first;

            
            if (visited[v]) continue;

           
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

   
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }

    dijkstra(n, graph);

    return 0;
}
