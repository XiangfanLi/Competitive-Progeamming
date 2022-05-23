#include <bits/stdc++.h>

using namespace std;

int A[100010];
int T, N;
int main() {
	cin >> T;
	while(T--) {
		cin >> N;
		int cnt[2] = {0};
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
			cnt[A[i]]++;
		}
		int turn = 0; // Alice
		while(cnt[0] + cnt[1] > 1) {
			if (turn == 0) {
				if (cnt[0] > 0) {
					cnt[0]--;
				}else {
					cnt[1]--;
				}
			} else {
				if (cnt[1] > 0) {
					cnt[1]--;
				} else {
					cnt[0]--;
				}
			}
			turn = 1 - turn;
		}
		cout << ((cnt[0] == 1) ? 0 : 1) << endl;
	}
}