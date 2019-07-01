#include <iostream>
#include <deque>
using namespace std;
deque<int> deq;

int n, m, r=0;

int main(){

	cin >> n >> m ;

	for(int i=1; i<=n; i++) deq.push_back(i);

	while(m--){

		int a;
		cin>> a ;

		for(int i=0; i<deq.size(); i++){

			if(a==deq[i]){

				if(i < deq.size() - i){
					while(deq[0]!=a){

						deq.push_back(deq.front());
						deq.pop_front();
						r++;
					}


				}

				else{
					while(deq[0]!=a){
						deq.push_front(deq.back());
						deq.pop_back();
						r++;
					}


				}




			}


		}


		deq.pop_front();  


	}



	cout << r << endl;
	return 0;

}











