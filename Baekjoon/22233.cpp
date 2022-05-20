#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
unordered_set<string> memo;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	string s = "", tmp = "", t = "";
	for(int i = 0; i < N; i++) {
		cin >> s;
		memo.insert(s);
	}
	
	while(M > 0) {
		cin >> tmp;
		int pos = 0;
		while(pos < tmp.size()) {
			int next = tmp.find(",", pos);
			if(next == -1) {
				t = tmp.substr(pos);
				if(memo.find(t) != memo.end())
					memo.erase(t);
				break;
			}
			else {
				t = tmp.substr(pos, next - pos);
				if(memo.find(t) != memo.end())
					memo.erase(t);
				pos = next + 1;
			}
		}
		cout << memo.size() << '\n';
		M--;
	}
	
	return 0;		
}