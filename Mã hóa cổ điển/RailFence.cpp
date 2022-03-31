#include<iostream>
using namespace std;
string alphabet="abcdefghijklmnopqrstuvwxyz";
string RailFenceEncryption(string plaintext,int row)
{
	string cipher;
	int len=plaintext.length();
	int col=len/row;
	if(len%row) col++;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			int c=j*row+i;
			if(c<len) cipher+=plaintext[c];
		}
	}
	return cipher;
}
string RailFenceDecryption(string cipher,int row)
{
	string plaintext;
	int len=cipher.length();
	int col=len/row;
	if(len%row) col++;
	for(int j=0; j<col; j++)
	{
		for(int i=0; i<row; i++)
		{
			int p=i*col+j;
			if(p<len) plaintext+=cipher[p];
		}
	}
	return plaintext;
}
int main()
{
	string plaintext="meetmeafterthetogaparty";
	int row=3;
	cout<<"\nPlaintext: "<<plaintext<<" "<<plaintext.length();
	string cipher=RailFenceEncryption(plaintext,row);
	cout<<"\nCiphertext: "<<cipher<<" "<<cipher.length();
	cout<<"\nDecryption: "<<RailFenceDecryption(cipher,row);
}
