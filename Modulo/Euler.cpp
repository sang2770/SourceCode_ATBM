#include<bits/stdc++.h>
using namespace std;
int phi(int n)
{
    int result = 1;
    for (int i = 2; i < n; i++)
        if (__gcd(i, n) == 1)
            result++;
    return result;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	int n;
	cout<<"Nhap so n:"<<endl;
	cin>>n;
	cout << "phi("<<n<<") = " << phi(n) << endl;
    return 0;
}

