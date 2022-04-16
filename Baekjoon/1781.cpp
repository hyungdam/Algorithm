#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
ll ans;
int N;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

void solve() {
	for(int i = 0; i < N; i++) {
		if(pq.size() < v[i].first) {
			pq.push(v[i].second);
		}
		else {
			if(pq.top() < v[i].second) {
				pq.pop();
				pq.push(v[i].second);
			}
		}
	}
	
	while(!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	
	solve();
	cout << ans << '\n';
	return 0;
}