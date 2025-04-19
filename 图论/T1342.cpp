#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <climits>

using namespace std;

const double INF = 1e9; 

int main() {
    int n;
    cin >> n;
    vector<pair<double, double>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // 初始化邻接矩阵
    vector<vector<double>> dist(n, vector<double>(n, INF));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0; // 自己到自己的距离是0
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; 
        b--;
        double dx = points[a].first - points[b].first;
        double dy = points[a].second - points[b].second;
        double distance = sqrt(dx * dx + dy * dy);
        dist[a][b] = distance;
        dist[b][a] = distance; // 无向图，双向距离
    }

    int s, t;
    cin >> s >> t;
    s--;
    t--;

    // Floyd算法
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 输出结果，保留两位小数
    cout << fixed << setprecision(2) << dist[s][t] << endl;

    return 0;
}