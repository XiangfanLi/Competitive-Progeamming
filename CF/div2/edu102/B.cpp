
#include <bits/stdc++.h>

using namespace std;
int q;
string s, t;
int GCD(int a,int b){           // 求最大公约数
    int temp=0;
    while(b!=0){
        temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}

int LCM(int a, int b) {
	
	return a * b / GCD(a, b);
}



int main()
{
	cin >> q;
	while(q--) {
		cin >> s >> t;
		int lcm = LCM((int)s.size() , (int)t.size());
		//cout << "lcm = " << lcm << endl;
		string ss, tt;
		while((int)ss.size() < lcm)
			ss += s;
		while((int)tt.size() < lcm)
			tt += t;
		if(ss == tt)
			cout << ss << endl;
		else
			cout << -1 << endl;
				
	}
		return 0;
}
