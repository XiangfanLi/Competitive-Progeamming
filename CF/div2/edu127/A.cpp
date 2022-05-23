#include <bits/stdc++.h>


using namespace std;

const string strs[4] = {"aa", "aaa", "bb", "bbb"};

string S;
int t;
int main() {
	cin >> t;
	while (t--) {
		cin >> S;
		vector<bool> dp((int)S.size()+1, false);
		dp[0] = true;
		for (int i = 0; i < (int)S.size(); ++i) {
			for (const string& str: strs) {
				if (i + 1 >= (int)str.size() && str == S.substr(i - (int)str.size() + 1, (int)str.size()) && dp[i - (int)str.size() + 1]) {
					dp[i+1] = true;
				}
			}
		}
		if (dp[(int)S.size()]) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}