#include<iostream>
#include<string.h>
using namespace std;
void initialize_table(char pi[], char ci[])
{
	char C='a';
	for(int i=0; i<=25; i++)
	{
		pi[i]=C;
		C++;
	}
	cout<<"\n";
	for(int i=0; i<=25; i++)
	{
		cout<<pi[i]<<": \t";
		cin>>C;
		if(islower(C))
		{
			C=(int)C-97+65;
		}
		ci[i]=C; 
	}
}
int search(char arr[], char x)
{
	for(int i=0; i<26; i++)
	{
		if(arr[i]==x)
		{
			return i;
		} 
	}
	return -1;
}
void decrypt(char ctext[], char pi[26], char ci[26])
{
	cout<<"\nThe decrypted message is:\t";
	for(int i=0; i<strlen(ctext); i++)
	{
		if(ctext[i]==' ' || (ctext[i]>='0' && ctext[i]<='9') )
		{
			cout<<ctext[i];
			continue;
		}
		int index=search(ci, ctext[i]);
		cout<<pi[index];
	}
}
void encrypt(char ptext[], char ctext[], char pi[26], char ci[26])
{
	cout<<"\nThe Encrypted text is:\t";
	for(int i=0; i<strlen(ptext); i++)
	{
		if(ptext[i]==' ' || (ptext[i]>='0' && ptext[i]<='9') )
		{
			cout<<ptext[i];
			ctext[i]=ptext[i];
			continue;
		}
		int index=search(pi, ptext[i]);
		cout<<ci[index];
		ctext[i]=ci[index];
	}
}
int main()
{
	char pi[26], ci[26], plaintext[100], ciphertext[100];
	cout<<"\nEnter the plaintext:\t";
	cin.ignore(100, '\n');
	cin.getline(plaintext, 100, '\n');
	initialize_table(pi, ci);
	encrypt(plaintext, ciphertext, pi, ci);
	decrypt(ciphertext, pi, ci);
}
