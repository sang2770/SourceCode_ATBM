#include<iostream>
using namespace std;
string alphabet="abcdefghijklmnopqrstuvwxyz";
string plaintext="STILLWATERSRUNDE";
int key=17;
int                     
{
	int p;
	if(ch>='a'&&ch<='z')
		p=ch-'a';
	else if(ch>='A'&&ch<='Z')
		p=ch-'A';
	return p;
}
//m� H�a
string CeaserEncryption(string input, int k)
{
	string cipher="";
	for(char ch : input)
	{
		int p=position(ch);
		int c=(p+k)%26;
		cipher+=alphabet[c];
	}
	return cipher;
}
//giai m�
string CeaserDecryption(string input, int k)
{
	string plaintext="";
	for(char ch:input)
	{
		int c=position(ch);
		int p=(c-k+26)%26;
		plaintext+=alphabet[p];
	}
	return plaintext;
}
int main()
{
	cout<<"Plaintext: "<<plaintext<<endl;
	cout<<"Key: "<<key<<endl;
//	cin>>key;
	string cipher=CeaserEncryption(plaintext,key);
	cout<<"\nCiphertext: "<<cipher;
	cout<<"\nDecryption: "<<CeaserDecryption(cipher,key);
}
