#include <bits/stdc++.h>


using namespace std;

int T;
string S;


bool IsVowel(char c) {
	return (c == 'A') 
	|| (c == 'E')
	|| (c == 'I')
	|| (c == 'O')
	|| (c == 'U');
}


int solve() {
	const int N = (int)S.size();
	int ans = 2 * N;
	for(int k = 0; k < 26; ++k) {
		int curr_ans = 0;
		char result = (char)('A' + k);
		for(int i = 0; i < N; ++i) {
			if (S[i] == result) {
				
			}
			else if (IsVowel(S[i]) != IsVowel(result)) {
				curr_ans += 1;
			} else {
				curr_ans += 2;
			}
		}	
		ans = min(ans, curr_ans);
	}
	return ans;
}



int main()
{
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> S;
		std::cout << "Case #" << t << ": " << solve() << std::endl;
	}
	
}
