#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, q;
int cow[222222], sum[222222];
int ans;
int main() {
    scanf("%d %d", &n, &q);

	for (int i = 0; i < n; i++) {
		scanf("%d", &cow[i]);
		sum[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			sum[i] *= cow[(i + j) % n];
		}
		ans += sum[i];
	}
	int temp;
    for(int i=0; i<q; i++){
        scanf("%d", &temp);
		temp--;
		for (int i = 0; i < 4; i++) {
			int idx = (temp - i + n) % n;
            ans -= sum[idx];
			sum[idx] *= -1;
			ans += sum[idx];
		}
		printf("%d\n", ans);
    }
		
	
}