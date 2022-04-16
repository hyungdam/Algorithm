#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
vector<pair<int, int>> v;

int main() {
	cin >> N >> L;
	int end = 0;
	for(int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	
	int com = 0;
	int ans = 0;
	for(int i = 0; i < N; i++) {
		if(com >= v[i].second)
			continue;
		com = max(com, v[i].first);
		int size = v[i].second - com;
		if(size % L == 0) {
			ans += size / L ;
			com += size;
		}
		else {
			ans += size / L + 1;
			com += L*(size / L + 1);
		}
	}
	
	cout << ans << '\n';
	return 0;
}