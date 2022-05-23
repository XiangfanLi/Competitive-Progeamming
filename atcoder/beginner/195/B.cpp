#include <bits/stdc++.h>


using namespace std;

int A, B, W;

int main()
{
	cin>> A >> B >> W;
	W *= 1000;
	int Max = floor((double)W / (double) A);
	int Min = ceil((double)W / (double)B);
	if( Min > Max || (double)W / Max < A || (double)W / Max > B || (double)W / Min < A || (double)W / Min > B)
	{
		cout << "UNSATISFIABLE" << endl;
		
	}
	else
	{
		cout << Min << " " << Max << endl;
	}
	
}
