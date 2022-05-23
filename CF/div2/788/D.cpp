#include <bits/stdc++.h>

using namespace std;

int t;
#define ll long long
int n;

ll calc(int lines) {
	ll l1, l2, l3;
	l1 = l2 = l3 = lines / 3;
	int remain = lines % 3;
	if (remain > 0) {
		l1++;
		remain--;
	}
	if (remain > 0) {
		l2++;
		remain--;
	}
	return 2 * (l1 * l2 + l1 * l3 + l2 * l3); 
}

int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		int low = 1;
		int high = max(n, (int)(10));
		while(low < high) {
			int mid = (low + high) >> 1;
			ll nn = calc(mid);
			if (nn >= n) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		cout << low << endl;

	}
}