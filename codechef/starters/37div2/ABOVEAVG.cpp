#include <bits/stdc++.h>


using namespace std;

int T;
int N, M, X;

int main() {
	cin >> T;
	while (T--) {
		cin >> N >> M >> X;
		int A = 0;
		if (X == M) {
			cout << 0 << endl;
			continue;
		}
		// int low = 0;
		// int high = N;
		// while (low + 1 < high) {
		// 	int mid = (low + high) >> 1;
		// 	int x = mid * (X+1);
		// 	if (x > N * X) {
		// 		high = mid - 1;
		// 	} else {
		// 		low = mid;
		// 	}
		// }
		cout << N * X / (X + 1) << endl;
		// cout << low << endl;
	}
}