#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <deque>

using namespace std;

const int MAXN = 20005;
const int MAXM = 200005;

vector<pair<int, int>> adj[MAXN];
int dist[MAXN];
bool inQueue[MAXN];

void spfa(int n) {
    for (int i = 1; i <= n; ++i) {
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    deque<int> q;
    q.push_back(1);
    inQueue[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        inQueue[u] = false;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int l = edge.second;
            if (dist[u] != INT_MAX && dist[u] + l < dist[v]) {
                dist[v] = dist[u] + l;
                if (!inQueue[v]) {                   // SLF优化：如果新距离小于队首距离，插入队首
                    if (!q.empty() && dist[v] < dist[q.front()]) {
                        q.push_front(v);
                    } else {
                        q.push_back(v);
                    }
                    inQueue[v] = true;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].push_back({v, l});
    }
    spfa(n);
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << endl;
    }
    return 0;
}
