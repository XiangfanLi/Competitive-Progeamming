#include <bits/stdc++.h>

using namespace std;

int T, N;
int A[100010];

priority_queue<double> q;
#define ll long long

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		while(!q.empty()) {
			q.pop();
		}
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
			// q.push(-A[i]);
		}
		sort(A+1, A+N+1);
		ll suf = 0;
		for (int i = 1; i <= N; ++i)
			suf += A[i];
		double pre = 0;
		double ans = 0.0;
		for (int i = 1; i < N; ++i) {
			pre += A[i];
			suf -= A[i];
			ans = max(ans, (pre / i + suf) / (N - i + 1));
		}
		cout << fixed << setprecision(6) << ans << endl;
		
	}
}