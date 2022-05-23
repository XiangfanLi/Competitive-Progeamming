#include <bits/stdc++.h>

using namespace std;

int T, N, X;
int A[210];

int main() {
	cin >> T;
	while(T--) {
		cin >> N >> X;
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		int ans1 = 0;
		int ans2 = 0;
		for (int i = 1; i <= N; ++i) {
			ans1 += int(ceil((double)A[i] / X));
			ans2 = max(ans2, A[i]);
		}
		cout << min(ans1, ans2) << endl;
	}
}