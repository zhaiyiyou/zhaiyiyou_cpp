#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[110];
vector<int> path;
void dfs(int p) {
	while (!a[p].empty()) {
		int tmp = a[p].back();
		a[p].pop_back();
		auto i = find(a[tmp].begin(), a[tmp].end(), p);
		if (i != a[tmp].end()) {
			a[tmp].erase(i);
		}
		dfs(tmp);
	}
	path.push_back(p);
}
void check() {
	int start = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i].size() % 2 == 1) {
			start = i;
			break;
		}
	}
	dfs(start);
}
void print() {
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
}
int main() {
	cin >> n >> m;
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	check();
	print();
	return 0;
}
