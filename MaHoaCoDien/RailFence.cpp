#include<iostream>
using namespace std;
string alphabet="abcdefghijklmnopqrstuvwxyz";
string plaintext="HONESTYISTHEBESTPO";
int k=6;
string RailFenceEncryption(string plaintext,int k)
{
	string cipher;
	int len=plaintext.length();
	int col=len/k;
	if(len%k) col++;
	for(int i=0; i<k; i++)
	{
		for(int j=0; j<col; j++)
		{
			int c=j*k+i;
			if(c<len) cipher+=plaintext[c];
		}
	}
	return cipher;
}
string RailFenceDecryption(string cipher,int k)
{
	string plaintext;
	int len=cipher.length();
	int col=len/k;
	if(len%k) col++;
	for(int j=0; j<col; j++)
	{
		for(int i=0; i<k; i++)
		{
			int p=i*col+j;
			if(p<len) plaintext+=cipher[p];
		}
	}
	return plaintext;
}
int main()
{
	cout<<"\nPlaintext: "<<plaintext<<" "<<plaintext.length();
	string cipher=RailFenceEncryption(plaintext,k);
	cout<<"\nCiphertext: "<<cipher<<" "<<cipher.length();
	cout<<"\nDecryption: "<<RailFenceDecryption(cipher,k);
}
