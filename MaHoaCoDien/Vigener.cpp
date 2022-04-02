#include<iostream>
using namespace std;
string alphabet="abcdefghijklmnopqrstuvwxyz";
string plaintext="THETRUTHWILLO";
string key="THEGRASS";
int position(char ch)
{
	int p;
	if(ch>='a'&&ch<='z')
		p=ch-'a';
	else if(ch>='A'&&ch<='Z')
		p=ch-'A';
	return p;
}
string VigenerEncryption(string plaintext,string key)
{
	string cipher;
	int p,k,c;
	int m=key.length();
	for(int i=0; i<plaintext.length(); i++)
	{
		p=position(plaintext[i]);
		k=position(key[i%m]);
		c=(p+k)%26;
		cipher+=alphabet[c];
	}
	return cipher;
}
string VigenerDecryption(string cipher, string key)
{
	string plaintext;
	int p,k,c;
	int m=key.length();
	for(int i=0; i<cipher.length(); i++)
	{
		c=position(cipher[i]);
		k=position(key[i%m]);
		p=(c-k+26)%26;
		plaintext+=alphabet[p];
	}
	return plaintext;
}
int main()
{
	
	cout<<"\nPlaintext: "<<plaintext<<" "<<plaintext.length();
	string cipher=VigenerEncryption(plaintext,key);
	cout<<"\nCiphertext: "<<cipher<<" "<<cipher.length();
	cout<<"\nDecryption: "<<VigenerDecryption(cipher,key);
}
