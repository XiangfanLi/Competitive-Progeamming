#include <bits/stdc++.h>

using namespace std;

int T, N;
#define ll long long
ll A[200010];

int main(){
	cin >> T;
	while (T--) {
		cin >> N;
		ll sum = 0;
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
			sum += A[i];
		}
		// sum /= (N / 2);
		if ((sum % (N / 2) == 0) && ((sum / (N/2)) % 2 == 1)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		// if (sum %2 == 1) {
		// 	cout << "YES\n";
		// } else {
		// 	cout << "NO\n";
		// }
	}
}