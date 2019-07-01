#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string.h>

using namespace std;
int n, m, x;

struct edge {
	int to;
	int weight;
};
vector<edge> vec[1011];
vector<edge> rvec[1011];
int dist[1011];
int rdist[1011];
int result;

int main() {
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		rvec[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = 999999999;
		rdist[i] = 999999999;
	}
	dist[x] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push({ 0,x });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int num = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[num].size(); i++) {
			int next = vec[num][i].to;
			int next_weight = vec[num][i].weight;
			if (cost + next_weight < dist[next]) {
				dist[next] = cost + next_weight;
				pq.push({ -dist[next], next });
			}
		}
	}
	rdist[x] = 0;
	pq.push({ 0,x });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int num = pq.top().second;
		pq.pop();

		for (int i = 0; i < rvec[num].size(); i++) {
			int next = rvec[num][i].to;
			int next_weight = rvec[num][i].weight;
			if (cost + next_weight < rdist[next]) {
				rdist[next] = cost + next_weight;
				pq.push({ -rdist[next], next });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		result = max(result, dist[i] + rdist[i]);
	}
	cout << result << endl;


	return 0;
}


  

  