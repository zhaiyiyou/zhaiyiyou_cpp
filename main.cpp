#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 25005;
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, cost;
};

vector<Edge> graph[MAXN];
int dist[MAXN];
bool inQueue[MAXN];

void SPFA(int start, int n) {
    memset(dist, 0x3f, sizeof(dist));
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    inQueue[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false;

        for (auto &edge : graph[u]) {
            int v = edge.to;
            int w = edge.cost;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }
}

int main() {
    int T, R, P, S;
    cin >> T >> R >> P >> S;

    // 读取公路（双向）
    for (int i = 0; i < R; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    // 读取航路（单向）
    for (int i = 0; i < P; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
    }

    SPFA(S, T);

    for (int i = 1; i <= T; ++i) {
        if (dist[i] == INF) {
            cout << "NO PATH" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}