#include <iostream>
using namespace std;

typedef long long ll;
const int MN = 101;
ll p[MN];
int T, N;

ll solve(int n) {
	if(n <= 3) return 1;
	if(p[n]) return p[n];
	return p[n] = solve(n-3) + solve(n-2);	
}

int main() {
	cin >> T;
	for(int i = 0; i < T; i++) {
		cin >> N;
		cout << solve(N) << '\n';
	}
	return 0;
}