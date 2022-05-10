#include <iostream>
#include <cstring>
using namespace std;

int T, n;
const int MN = 100001;
int score[2][MN];
int dp[2][MN];

void solve() {
	// 초기화
	memset(score, 0, sizeof(score));
	memset(dp, 0, sizeof(dp));
	
	// 값 입력
	for(int i = 0; i < 2; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> score[i][j];
		}
	}
	
	// dp
	dp[0][1] = score[0][1];
	dp[1][1] = score[1][1];
	for(int i = 2; i <= n; i++) {
		dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + score[0][i];
		dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + score[1][i];
	}
}

int main() {
	cin >> T;
	while(T--) {
		cin >> n;
		solve();
		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
	return 0;
}