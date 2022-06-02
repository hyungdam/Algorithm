#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void AB(string s, string t) {
	if(s == t) {
		cout << 1 << '\n';
		exit(0);
	}
	string tmp;
	if(t[t.size() - 1] == 'A') {
		tmp = t;
		tmp.erase(t.size() - 1);
		AB(s, tmp);
	}
	if(t[0] == 'B') {
		tmp = t;
		reverse(tmp.begin(), tmp.end());
		tmp.erase(t.size() - 1);
		AB(s, tmp);
	}
}

int main() {
	string s, t;
	cin >> s >> t;
	AB(s, t);
	
	cout << 0 << '\n';
	return 0;	
}