#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void create_table(char table[26][26])
{
	char x='A';
	char y=x;
	int i, j;
	for(i=0; i<26; i++)
	{
		for(y=x, j=0; j<26; j++)
		{
			table[i][j]=y;
			if(y=='Z')
				y='A';
			else
				y++;
		}
		x++;
	}
	cout<<"\n\n\n";
	cout<<"\t\tVIGENERE TABLE\n";
	cout<<"\t";
	for(x='A'; x<='Z'; x++)
	{
		cout<<x<<" ";
	}
	cout<<"\n\t";
	for(i=0; i<26; i++)
	{
		cout<<"_ ";
	}
	cout<<"\n";
	for(x='A', i=0; i<26; i++)
	{
		cout<<x<<"|\t";
		for(j=0; j<26; j++)
		{
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
		x++;
	}
}

int search(char table[][26], char ct, char k)
{
	for(int i=0; i<26; i++)
	{
		if(table[i][k-97]==ct)
		{
			return i;
		}
	}
}

void decrypt(char ctext[], char key[], char table[][26])
{
	int i, k;
	cout<<"\nTe decrypted text is:\t";
	for(i=0, k=0; i<strlen(ctext); i++)
	{
		if(ctext[i]==' ' || (ctext[i]>='0' && ctext[i]<='9'))
		{
			cout<<ctext[i];
			continue;
		}
		int temp=search(table, ctext[i], key[k]);
		cout<<(char)(temp+97);
		k++;
		if(k==strlen(key))
			k=0;
	}
}
		
void encrypt(char ptext[], char key[], char table[][26])
{
	int i, k;
	char cipher[50];
	for(i=0, k=0; i<strlen(ptext); i++)
	{
		if(ptext[i]==' ' || (ptext[i]>='0' && ptext[i]<='9'))
		{
			cipher[i]=ptext[i];
			continue;
		}
		cipher[i]=table[key[k]-97][ptext[i]-97];
		k++;
		if(k==strlen(key))
			k=0;
	}
	cipher[i]='\0';
	cout<<"\nThe encrypted text is:\t";
	for(i=0; i<strlen(cipher); i++)
	{
		cout<<cipher[i];
	}
	decrypt(cipher, key, table);
}
int main()
{
	char plaintext[50], key[50];
	cin.ignore(50, '\n');
	cout<<"\nEnter the plaintext:\t";
	cin.getline(plaintext, 50);
	cin.ignore(50, '\n');
	cout<<"\nEnter the key:\t";
	cin.getline(key, 50);
	char table[26][26];
	create_table(table);
	encrypt(plaintext, key, table);
	return 0;
}
