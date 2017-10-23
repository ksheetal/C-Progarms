#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
void decrypt(char ciphertext[], char table[26])
{
	char ptext[50];
	for(int i=0; i<strlen(ciphertext); i++)
	{
		if(ciphertext[i]==' ' || (ciphertext[i]>='0' && ciphertext[i]<='9'))
		{
			ptext[i]=ciphertext[i];
			continue;
		}
		int index;
		for(int j=0; j<26; j++)
		{
			if(ciphertext[i]==table[j])
			{
				index=j;
				break;
			}
		}
		ptext[i]=(char)(index+97);
	}
	cout<<"\nThe Decrypted text is:\t";
	for(int i=0; i<strlen(ptext); i++)
	{
		cout<<ptext[i];
	}
}
int check_duplicate(char str[], char c)
{
	for(int i=0; i<strlen(str); i++)
	{
		if(str[i]==c)
			return 1;
	}
	return 0;
}
void encrypt(char ptext[])
{
	char table[26];
	char x='a'; 
	cout<<"\n\t TABLE\n";
	for(int i=0; i<26; i++)
	{
		cout<<x<<" ";
		x++;
	}
	x='a';
	srand(time(0));
	for(int i=0; i<26; )
	{
		int r=rand();
		int temp=(x-97+r)%26;
		int flag=check_duplicate(table, temp+97);
		if(flag==1)
		{
			continue;
		}
		table[i]=(char)(temp+97);
		i++;
	}
	cout<<endl;
	for(int i=0; i<26; i++)
	{
		cout<<(char)(table[i]-97+65)<<" ";
	}
	char ctext[50];
	int index;
	for(int i=0; i<strlen(ptext); i++)
	{
		if(ptext[i]==' ' || (ptext[i]>='0' && ptext[i]<='9'))
		{
			ctext[i]=ptext[i];
			continue;
		}
		index=ptext[i]-97;
		ctext[i]=table[index];
	}
	cout<<"\n\nThe excrypted text is:\t";
	for(int i=0; i<strlen(ctext); i++)
	{
		if(ctext[i]>='0' && ctext[i]<='9')
		{
			cout<<ctext[i];
			continue;
		}
		cout<<(char)(ctext[i]-97+65);
	}
	decrypt(ctext, table);
}
int main()
{
	char plaintext[50];
	cin.ignore(50, '\n');
	cout<<"\nEnter the plaintext:\t";
	cin.getline(plaintext, 50);
	encrypt(plaintext);
	return 0;
}
