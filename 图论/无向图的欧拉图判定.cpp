#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> a[110];
vector<int> path;

void dfs(int start)
{
	while (!a[start].empty())
	{
		int tmp = a[start].back();
		a[start].pop_back();
		auto i = find(a[tmp].begin(), a[tmp].end(), start);

		if (i != a[tmp].end())
		{
			a[tmp].erase(i);
		}

		dfs(tmp);
	}

	path.push_back(start);
}

void print()
{
	for (int i = path.size() - 1; i >= 0; i --)
	{
		cout << path[i] << " ";
	}

	cout << endl;
}

void check()
{
	int odd = 0, start = 1;

	for (int i = 1; i <= n; i ++)
	{
		if (a[i].size() % 2 == 1)
		{
			odd ++;
			start = i;
		}
	}

	if (odd == 1 || odd == 2)
	{
		dfs(start);
	}
	else
	{
		cout << 0 << endl;
	}
}

int main()
{
	cin >> n >> m;
	int x, y;

	for (int i = 1; i <= n; i ++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	check();
	print();
	return 0;
}
