#include <iostream>
#include <cstring>

using namespace std;

const int MN = 300;
int N, M;
int Map[MN][MN];
int tmp_Map[MN][MN];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool visit[MN][MN];
int year;

void melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int cnt = 0;
			if (Map[i][j] > 0) {
				for (int k = 0; k < 4; k++) {
					if (Map[i + dx[k]][j + dy[k]] <= 0)
						cnt++;
				}
				tmp_Map[i][j] = Map[i][j] - cnt;
			}
		}
	}
	year++;
}

void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			if (Map[nx][ny] > 0 && !visit[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	//input
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}

	while (1) {
		memset(visit, 0, sizeof(visit));
		memset(tmp_Map, 0, sizeof(tmp_Map));
		int count = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (Map[i][j] > 0 && !visit[i][j]) {
					dfs(i, j);
					count++;
				}
			}
		}

		if (count >= 2) {
			cout << year << '\n';
			break;
		}
		if (count == 0) {
			cout << 0 << '\n';
			break;
		}

		melt();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				Map[i][j] = tmp_Map[i][j];
			}
		}
	}

	return 0;
}