#include <iostream>
#include <cmath>
 
using namespace std;
 
int main()
{
	long long a, r, res, d, n;
	a=2013;
	n=32;
	d=7349;
	res = 1;
	r = a % d;

	// So d? nhân Ai C?p
	while (n > 0)
	{
		if(n & 1)
			res = (res * r) % d;

		r = (r * r) %d;
		n >>= 1;
	}
 
	cout << "res: " << res;
 
	return 0;
}
