#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <limits.h>
using namespace std;

int n, m, s;
vector<int> a[110];
queue<int> q;
int d[110];//距离
bool v[110];

void bfs(int s)
{
	d[s] = 0;
	q.push(s);
	v[s] = 1;
	memset(d, INT_MAX, sizeof(d));
	d[s] = 0;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < a[x].size(); i ++)
		{
			int y = a[x][i];

			if (!v[y])
			{
				v[y] = 1;
				d[y] = d[x] + 1;
				q.push(y);
			}
		}`
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i ++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	cin >> s;
	bfs(s);

	for (int i = 0; i < n; i ++)
	{
		cout << d[i] << " ";
	}

	cout << endl;

	return 0;
}
