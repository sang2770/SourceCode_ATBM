#include <iostream>
#include <cmath>
 #define ld long
using namespace std;
 // Tìm Modulo
ld Modulo(ld a, ld n, ld d)
{
	ld r, res;
//	a=2013;
//	n=32;
//	d=7349;
	res = 1;
	r = a % d;
	while (n > 0)
	{
		if(n & 1)
			res = (res * r) % d;
		r = (r * r) %d;
		n >>= 1;

	}
	return res;
}
int main()
{
	ld a, r, res, d, n;
	a=2013;
	n=32;
	d=7349;
	res = 1;
	r = a % d;

	while (n > 0)
	{
		if(n%2 !=0)
	 		res = (res * r) % d;
	 	r = (r * r) %d;
		n =n/2;
	}
 
	cout << "res: " << res<<endl;
	
	return 0;
}
