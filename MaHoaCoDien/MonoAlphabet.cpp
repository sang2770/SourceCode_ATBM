#include<iostream>
using namespace std;
string alphabet="abcdefghijklmnopqrstuvwxyz";
string k="JEHFAVZNOXUBMYPKDLGSRCTWQI";
string plaintext="MONEYMAKESTHEMAR";
int position(char ch)
{
	int p;
	if(ch>='a'&&ch<='z')
		p=ch-'a';
	else if(ch>='A'&&ch<='Z')
		p=ch-'A';
	return p;
}
int *inverseKey(string cipher)
{
	int *index=new int[26];
	for(int i=0; i<26; i++)
		index[position(k[i])]=i;
	return index;
}
string monoalphabeticEncyption(string input)
{
	string ciphertext="";
	for(char ch:input)
	{
		int p=position(ch);
		ciphertext+=k[p];
	}   
	return ciphertext;
}
string monoalphabeticDecryption(string input)
{
	int *index=inverseKey(cipher);
	string plaintext="";
	for(char ch:input)
	{
		int p=position(ch);
		plaintext+=alphabet[index[p]];
	}
	return plaintext;
}
int main()
{
	cout<<"\nPlaintext: "<<plaintext;
	string cipher=monoalphabeticEncyption(plaintext);
	cout<<"\nCiphertext: "<<cipher;
	cout<<"\nDecryption: "<<monoalphabeticDecryption(cipher);
}
