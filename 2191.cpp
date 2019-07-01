#include <iostream>
#include <stack>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string.h>
using namespace std;


struct mouse {
	int x;
	int y;
};
mouse mou[111];
bool visited[111];
int B[111];
int n, m, s, v;
vector<int> vec[111];

bool dfs(int now) {
	visited[now] = true;

	for (int i = 0; i < vec[now].size(); i++) {
		int next = vec[now][i];
		int next_mouse = B[next];
		if (!visited[next_mouse]) {
			if (!next_mouse || dfs(next_mouse)) {
				B[next] = now;
				return true;
			}

		}
	}
	return false;
}

int main() {
	cin >> n >> m >> s >> v;

	for (int i = 1; i <= n; i++) {
		float  a, b;
		cin >> a >> b;
		mou[i].x = (int)a;
		mou[i].y = (int)b;
	}
	int limit = (s*v)*(s*v);

	for (int i = 1; i <= m; i++) {
		float c, d;
		cin >> c >> d;
		int a = (int)c;
		int b = (int)d;
		for (int j = 1; j <= n; j++) {
			int temp = (a - mou[j].x)*(a - mou[j].x) + (b - mou[j].y)*(b - mou[j].y);
			if (temp <= limit) {
				vec[j].push_back(i);
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) result++;
	}

	cout << n - result << endl;


	return 0;
}
