#include<bits/stdc++.h>
using namespace std;
#define ld long
//TIm nghich dao
ld ModInv(ld b, ld n){
  ld A3=n,B3=b,A2=0,B2=1;
  while(true){
    ld q=A3/B3;
    ld t=A2-q*B2;
    ld r=A3-q*B3;
    A2=B2;B2=t;
    A3=B3;B3=r;
    if(B3==0)
    {
    	return -1;
	}
	else if(B3==1){
		return B2>0?B2:B2+n;
	}
  }
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	cout<<ModInv(247, 11);

}

