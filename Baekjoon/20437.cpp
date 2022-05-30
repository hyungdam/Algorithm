#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int T;
int arr[26];

int main() {
	cin >> T;
	string s = "";
	for(int i = 0; i < T; i++) {
		cin >> s;
		int n;
		
		for(int j = 0; j < s.size(); j++) {
			arr[s[j] - 'a']++;
		}
		
		cin >> n;
		int min_len = 10001, max_len = 0;
		for(int j = 0; j < s.size(); j++) {
			if(arr[s[j] - 'a'] >= n) {
                int cnt = 0, len;
				for(int k = j; k < s.size(); k++) {
                    if(s[k] == s[j])
                        cnt++;
                    if(cnt == n) {
                        len = k - j + 1;
                        min_len = min(min_len, len);
				        max_len = max(max_len, len);
						break;
                    }
                }
			}
		}
		if(min_len == 10001 || max_len == 0)
			cout << "-1" << '\n';
		else 
			cout << min_len << ' ' << max_len << '\n';
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}