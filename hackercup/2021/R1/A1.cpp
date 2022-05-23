#include <bits/stdc++.h>


using namespace std;

int T;
int N;

string W;

const int INF = (int)(1e9);

int main() {
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> N;
		cin >> W;
		int l = 0, r = 0;
		for(int i = 0; i < N; ++i) {
			if (W[i] == 'F') {
					
			} else if (W[i] == 'X') {
				l = min(l, r + 1);
				r = INF;
			} else {
				r = min(r, l + 1);
				l = INF;
			}
		}
		cout << "Case #" << t << ": " << min(l, r) << endl;
	}
}
