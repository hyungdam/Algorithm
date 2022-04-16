#include <iostream>
#include <string>
using namespace std;

const int MN = 10001;
int R, C;
string MAP[MN];
bool visit[MN][501];
bool flag;
int ans;

int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};

void dfs(int x, int y) {
	visit[x][y] = true;	
	if(y == C-1) {
		ans++;
		flag = true;
		return;
	}
	for(int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0 <= nx && nx < R && 0 <= ny && ny < C) {
			if(MAP[nx][ny] == '.' && !visit[nx][ny]) {
				dfs(nx, ny);
				if(flag == true) return;
			}
		}	
	}
}

int main() {
	cin >> R >> C;
	for(int i = 0; i < R; i++) {
		cin >> MAP[i];
	}
	
	for(int i = 0; i < R; i++) {
		flag = false;
		dfs(i, 0);
	}
	
	cout << ans << '\n';
}