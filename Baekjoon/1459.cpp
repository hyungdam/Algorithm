#include <iostream>
#include <cstdlib>
using namespace std;

typedef unsigned long long ll;
ll x, y, w, s;

int main() {
	cin >> x >> y >> w >> s;
	ll ans1, ans2, ans3;
	
	ans1 = w*(x+y);
	
	if((x+y) % 2 == 0)
		ans2 = max(x, y) * s;
	else
		ans2 = (max(x, y) - 1) * s + w;
	
	ans3 = min(x, y) * s + abs(x-y) * w;
	
	cout << min(ans1, min(ans2, ans3)) << '\n';
	return 0;
}