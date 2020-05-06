#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include <iostream>
using namespace std;
int N, M, T,A[52][52];
void move(int x, int d, int k)
{
	for (int t = 0; t < k; t++)
		for (int i = 1; i <= N; i++)
			if (i%x == 0)
			{
				if (d == 0)
				{
					int tmp = A[i][M];
					for (int j = M; j > 1; j--) A[i][j] = A[i][j - 1];
					A[i][1] = tmp;
				}
				else if (d == 1)
				{
					int tmp = A[i][1];
					for (int j = 1; j <= M; j++) A[i][j] = A[i][j + 1];
					A[i][M] = tmp;
				}
			}
}
void c(int a[52][52])
{
	int cnt = 0;
	double sum = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (a[i][j] != 0)
			{
				sum += a[i][j];
				cnt++;
			}
	if (cnt != 0) sum /= cnt;
    
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (a[i][j] != 0)
			{
				if (a[i][j] > sum) a[i][j]--;
				else if (a[i][j] < sum) a[i][j]++;
			}
}
void mark()
{
	int V[52][52];
	memcpy(V, A, sizeof(V));
	bool k = 0;
	for (int i = 1; i <= N; i++) {
		A[i][0] = A[i][M];
		for (int j = 1; j <= M; j++)
		{
			if (A[i][j] == 0) continue;
			if (A[i][j] == A[i][j - 1])
			{
				V[i][j] = 0;
				if (j == 1) V[i][M] = 0;
				else V[i][j - 1] = 0;
				k = 1;
			}
			if (A[i + 1][j] == A[i][j])
			{
				k = 1;
				V[i + 1][j] = 0;
				V[i][j] = 0;
			}
		}
	}
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"@@@@@@@@@@@@@"<<endl;
    
	if (!k) c(V);
	memcpy(A, V, sizeof(A));
}
int f()
{
	int sum = 0;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) sum += A[i][j];
	return sum;
}
int main()
{
	scanf("%d %d %d", &N, &M, &T);
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++)scanf("%d", &A[i][j]);
	for (int i = 0; i < T; i++)
	{
		int x, d, k;
		scanf("%d %d %d", &x, &d, &k);
		move(x, d, k);
		mark();
	}
	printf("%d", f());
}