#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, ans;
vector<int> arr;

int main() {
	cin >> N >> K;
	for(int i = 0; i < N; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	
	vector<int> dif;
	for(int i = 0; i < N-1; i++) {
		int a;
		a = arr[i+1] - arr[i];
		dif.push_back(a);
	}
	sort(dif.begin(), dif.end());
	
	for(int i = 0; i < N-K; i++)
		ans += dif[i];
	cout << ans << '\n';
	return 0;
}