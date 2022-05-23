#include <bits/stdc++.h>

using namespace std;

int t, n;
#define MAXN 100010
char s[MAXN];
int k;
char c;
int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		vector<bool> special(26, false);
		scanf("%s", s+1);
		cin >> k;
		while(k--) {
			cin >> c;
			special[c-'a'] = true;
		}
		int ans = 0;
		int last = -1;
		for (int i = n; i >= 1; --i) {
			if (last != -1)
				ans = max(last - i, ans);
			if (special[s[i]-'a']) {
				last = i;
			}
		}
		cout << ans << endl;
	}
}