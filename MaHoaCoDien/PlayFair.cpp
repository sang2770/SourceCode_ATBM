#include<iostream>
using namespace std;
string alphabet="abcdefghijklmnopqrstuvwxyz";
string plaintext="ACLEANFASTISB";
string key="EASTO";
int position(char ch)
{
	int p;
	if(ch>='a'&&ch<='z')
		p=ch-'a';
	else if(ch>='A'&&ch<='Z')
		p=ch-'A';
	return p;
}
string CreateMatrixKey(string key)
{
	string MatrixKey;
	int flag[26];
	for(int k=0; k<26;k++) flag[k]=0;
	for(char c:key)
	{
		int p=position(c);
		if(!flag[p])
		{
			MatrixKey+=c;
			flag[p]=1;
		}
	}
	if(flag[position('i')]) flag[position('j')]=1;
	else if(flag[position('j')]) flag[position('i')]=1;
	else flag[position('j')]=1;
	for(int i=0; i<26; i++)
	if(flag[i]==0) MatrixKey+=alphabet[i];
	return MatrixKey;
}
string Split(string input)
{
	string plaintext="";
	int len=input.length();
	int i=0;
	while(i<len)
	{
		if(input[i]==input[i+1])
		{
			plaintext+=input[i];
			plaintext+='x';
			i+=1;
		}
		else
		{
			plaintext+=input[i];
			if(i+1<len) plaintext+=input[i+1];
			i+=2;
		}
	}
	if(plaintext.length()%2) plaintext+='x';
	return plaintext;
}
int *CreateIndex(string matrixKey)
{
	int* index=new int[26];
	for(int i=0; i,26; i++)
	{
		int pos=position(matrixKey[i]);
		index[pos]=i;
	}
	index[position('j')]=index[position('i')];
	return index;
}
string PlayFairEncryption(string input, string key)
{
	string plaintext=Split(input);
	cout<<"\nplaintext after Split: "<<plaintext<<" "<<plaintext.length();
	string matrixKey=CreateMatrixKey(key);
	int *index=CreateIndex(matrixKey);
	string ciphertext="";
	for(int i=0; i<=input.length(); i+=2)
	{
		int p1=index[position(plaintext[i])];
		int p2=index[position(plaintext[i+1])];
		int row1=p1/5, col1=p1%5;
		int row2=p2/5, col2=p2%5;
		int c1, c2;
		if(row1==row2)
		{
			col1=(col1+1)%5;
			col2=(col2+1)%5;
			c1=row1*5+col1;
			c2=row2*5+col2;
		}
		else if(col1==col2)
		{
			row1=(row1+1)%5;
			row2=(row2+1)%5;
			c1=row1*5+col1;
			c2=row2*5+col2;
		}
		else
		{
			c1=row1*5+col2;
			c2=row2*5+col1;
		}
		ciphertext+=matrixKey[c1];
		ciphertext+=matrixKey[c2];
	}
	return ciphertext;
}
//string PlayFairDecryption(string input, string key)
//{
	
//}
int main()
{
	cout<<"\nmatrixKey: "<<CreateMatrixKey(key);
	cout<<"\nPlaintext: "<<plaintext<<" "<<plaintext.length();
	string cipher=PlayFairEncryption(plaintext, key);
	cout<<"\nCiphertext: "<<cipher<<" "<<cipher.length();
	//cout<<"\nDecryption: "<<PlayFairDecryption(cipher, key);
}
