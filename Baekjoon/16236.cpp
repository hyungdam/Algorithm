#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct {
	int x;
	int y;
	int size;
	int cnt;
	int time;
}Shark;

typedef struct {
	int x;
	int y;
	int dist;
}Fish;

int N;
int space[20][20];
bool visit[20][20];
Shark s;
vector<Fish> f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	q.push({{x, y}, 0});
	visit[x][y] = true;
	
	while(!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(0 <= nx && nx < N && 0 <= ny && ny < N) {
				if(!visit[nx][ny]) {
					if(space[nx][ny] == 0) {
						visit[nx][ny] = true;
						q.push({{nx, ny}, dist+1});
					}
					else if(space[nx][ny] < s.size) {
						Fish tmp;
						tmp.x = nx;
						tmp.y = ny;
						tmp.dist = dist + 1;
						
						f.push_back(tmp);
						visit[nx][ny] = true;
						q.push({{nx, ny}, dist+1});
					}
					else if(space[nx][ny] == s.size) {
						visit[nx][ny] = true;
						q.push({{nx, ny}, dist+1});
					}
				}
			}
		}
	}
}

bool cmp(Fish a, Fish b) {
	if(a.dist <= b.dist) {
		if(a.dist == b.dist) {
			if(a.x <= b.x) {
				if(a.x == b.x) {
					if(a.y < b.y) {
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

void solve() {
	while(1) {
		f.clear();
		memset(visit, false, sizeof(visit));
		
		bfs(s.x, s.y);
		if(f.size() == 0) {
			cout << s.time << '\n';
			break;
		}
		else if(f.size() == 1) {
			space[f[0].x][f[0].y] = 9;
			space[s.x][s.y] = 0;
			s.x = f[0].x;
			s.y = f[0].y;
			s.cnt++;
			s.time += f[0].dist;
			
			if(s.cnt == s.size) {
				s.cnt = 0;
				s.size++;
			}
		}
		else {
			sort(f.begin(), f.end(), cmp);
			space[f[0].x][f[0].y] = 9;
			space[s.x][s.y] = 0;
			s.x = f[0].x;
			s.y = f[0].y;
			s.cnt++;
			s.time += f[0].dist;
			
			if(s.cnt == s.size) {
				s.cnt = 0;
				s.size++;
			}
		}
	}
}

int main() {
	cin >> N;
	// input
	int x, y;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> space[i][j];
			if(space[i][j] == 9) {
				s.x = i;
				s.y = j;
				s.size = 2;
				s.cnt = 0;
				s.time = 0;
			}
		}
	}
	
	solve();
	return 0;
}