#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

typedef struct pos {
    ll x, y;
    ll cmp;
};

double dist(pos p1, pos p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int N;
pos p[100002];

bool cmp1(pos p1, pos p2) {
    return p1.x < p2.x || (p1.x == p2.x) && (p1.y < p2.y);
}

ll ccw(pos p1, pos p2, pos p3) {
    return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}

bool cmp2(pos p1, pos p2) {
    ll c = ccw(p[0], p1, p2);
    if (c > 0) return 1;
    if (c < 0) return 0;
    else {
        if (dist(p[0], p1) < dist(p[0], p2)) return 1;
        else return 0;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%lld %lld", &p[i].x, &p[i].y);
    sort(p, p + N, cmp1);
    sort(p + 1, p + N, cmp2);
    
    vector<pos> v;
    v.push_back(p[0]);
    v.push_back(p[1]);
    
    for (int i = 2; i < N; i++) {
        while (v.size() >= 2 && ccw(v[v.size() - 2], v.back(), p[i]) <= 0) {
            v.pop_back();
        }
        v.push_back(p[i]);
    }
    
    double ans = -1;
    int len = v.size();
    
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            ans = max(ans, dist(v[i], v[j]));
        }
    }
    printf("%.6f", ans);
}
