#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int arr[2001];

int main() {
	//input
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	int ans = 0;
	sort(arr, arr+N);
	for(int i = 0; i < N; i++) {
		int l = 0, r = N - 1;
		int sum;
		while(l < r) {
			sum = arr[l] + arr[r];
			if(sum == arr[i]) {
				if(l != i && r != i) {
					ans++;
					break;
				}
				else {
					if(l == i)
						l++;
					else
						r--;
				}
			}
			else if(sum < arr[i])
				l++;
			else
				r--;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
