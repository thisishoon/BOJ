#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
    int N;
    int *arr;
    int *P;
    int maxIndex = 0;
    
    vector<int> v;
    vector<int> out;
    vector<int>::iterator lower;
    
    
    cin >> N;
    
    arr = new int[N+1];
    P   = new int[N+1];
    
    
    v.push_back(INT_MIN);
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        v.push_back(INT_MAX);
    }
    
    for (int i = 1; i <= N; i++)
    {
        lower = lower_bound(v.begin(), v.end(), arr[i]);
        v.at((lower - v.begin())) = arr[i];
        P[i] = (int)(lower-v.begin());
        if (maxIndex < P[i])
            maxIndex = P[i];
    }
    
    cout << maxIndex << endl;
    
    for (int i = N, index = maxIndex; i >= 1; i--)
    {
        if (index == P[i])
        {
            out.push_back(arr[i]);
            index--;
        }
    }
    
    for (int i = (out.size()-1); i >= 0; i--)
        cout << out[i] << " ";
    
    cout << endl;
    
    return 0;
}

