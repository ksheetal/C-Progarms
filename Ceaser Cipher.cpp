#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
void ceasercipher_decrypt(char ctext[], int k)
{
	char ptext[100];
	for(int i=0; i<strlen(ctext); i++)
	{
		if(ctext[i]==' ')
		{
			ptext[i]=' ';
			continue;
		}
		else if(ctext[i]>='0' && ctext[i]<='9')
		{
			int temp=(int)ctext[i]-48;
			temp=temp-k+10;
			temp=temp%10;
			temp=temp+48;
			ptext[i]=(char)temp;
			continue;
		}
		int temp=(int)ctext[i];
		temp-=65;
		temp=((temp-k+26)%26)+97;
		ptext[i]=(char)temp;
	}
	cout<<"\nThe decrypted text is:\t";
	for(int i=0; i<strlen(ptext); i++)
	{
		cout<<ptext[i];
	}
}
void ceasercipher_encrypt(char ptext[], int k)
{
	char ctext[100];
	for(int i=0; i<strlen(ptext); i++)
	{
		if(ptext[i]==' ')
		{
			ctext[i]=' ';
			continue;
		}
		else if(ptext[i]>='0' && ptext[i]<='9')
		{
			int temp=(int)ptext[i]-48;
			temp+=k;
			temp=temp%10;
			temp+=48;
			ctext[i]=(char)temp;
			continue;
		}
		int temp=(int)ptext[i];
		temp-=97;
		temp=((temp+k)%26)+65;
		ctext[i]=(char)temp;
	}
	cout<<"The Ciphertext is :\t";
	for(int i=0; i<strlen(ctext); i++)
	{
		cout<<ctext[i];
	}
	ceasercipher_decrypt(ctext, k);
}

int main()
{
	int k;
	char ciphertext[100], plaintext[100];
	cout<<"\nEnter the key:\t";
	cin>>k;
	k%=26;
	cout<<"\nEnter the plain text:\t";
	cin.ignore(100, '\n');
	cin.getline(plaintext, 100);
	ceasercipher_encrypt(plaintext, k);
	return 0;
}
