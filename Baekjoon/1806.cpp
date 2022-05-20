#include <iostream>

using namespace std;

int arr[100001];
int N, S;

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int st = 0;
	int end = 0;
	int sum = arr[0];
	int ans = 0;

	while (st <= end && end <= N) {
		int len = end - st + 1;
		if (sum < S)
			sum += arr[++end];
		else {
			if (ans == 0)
				ans = len;
			else if (ans > len)
				ans = len;
			sum -= arr[st++];
		}
	}

	cout << ans;
	return 0;
}