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
		if(n%2 !=0)
	 		res = (res * r) % d;
	 	r = (r * r) %d;
		n =n/2;
	}
	return res;
}

int main()
{
//	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	//q, a, Xa;
	ld q, a, Xa;
	cout<<"Nhap so nguyen to q:";
	cin>>q;
	cout<<"Nhap so a la can nguyen thuy cua q:";
	cin>>a;
	cout<<"Nhap khoa rieng cua A Xa:";
	cin>>Xa;
	cout<<"=====Cau a====="<<endl;
	//a, PU={q,a, Ya}
	//+ YA=a^Xa mod q;
	ld Ya=Modulo(a, Xa, q);
	cout<<"Khoa cong khai cua A la:"<<endl;
	cout<<"PU={"<<q<<","<<a<<","<<Ya<<"}"<<endl;
	cout<<"=====Cau b====="<<endl;
	ld k, M;
	//b, MÃ hóa (C1, C2) cho k, M
	cout<<"Nhap gia tri k:";
	cin>>k;
	cout<<"Nhap gia tri M:";
	cin>>M;
	//+, K=(Ya)^k mod q;
	ld K=Modulo(Ya, k, q);
	cout<<"Gia tri K="<<K<<endl;
	//+ C1=a^k mod q;
	ld C1=Modulo(a, k, q);
	cout<<"Gia tri C1="<<C1<<endl;
	//+ C2=K*M mod q;
	ld C2=Modulo(K*M, 1, q);
	cout<<"Gia tri C2="<<C2<<endl;
	cout<<"Ban Ma (C1, C2)="<<"("<<C1<<","<<C2<<")"<<endl;
	
	//c, Giai ma
	cout<<"=====Cau c: Giai ma====="<<endl;
	//+, K=(C1)^Xa mode q;
	ld K1=Modulo(C1, Xa, q);
	cout<<"Gia tri K="<<K1<<endl;
	//+, M=(C2*K^-1) mode q
	ld M1=Modulo(C2*ModInv(K, q), 1, q);
	cout<<"Gia tri gia ma M="<<M1<<endl;
	
	
	
}

