#include<iostream>
#include<ctype.h>
#include<math.h>
#include<string.h>
using namespace std;
void decrypt(char ctext[], char table[26])
{
	int index;
	cout<<"\n The Decrypted message is:\t";
	for(int i=0; i<strlen(ctext); i++)
	{
		if(ctext[i]==' ')
		{
			cout<<" ";
			continue;
		}
		if(ctext[i]>='0' && ctext[i]<='9')
		{
			cout<<ctext[i];
			continue;
		}
		for(int j=0; j<26; j++)
		{
			if(ctext[i]==table[j])
			{
				index=j;
				break;
			}
		}
		cout<<(char)(index+97);
	}
}
int search_duplicates(char str[], char ch)
{
	for(int i=0; i<strlen(str); i++)
	{
		if(str[i]==ch)
		{
			return 1;
		}
	}
	return 0;
}
void encrypt(char ptext[], char word[])
{
	char table[26], x='a';
	for(int i=0; i<26; i++)
		table[i]='.';
	char ciphertext[50], y='a';
	for(int i=0, j=0; i<26;)
	{
		if(j<strlen(word))
		{
			if(word[j]==' ')
			{
				j++;
				continue;
			}
			int temp=(int)(x-97);
			int flag=search_duplicates(table, word[j]);
			if(flag==0)
			{
				table[temp]=word[j];
				j++;
				i++;
				x++;
				continue;
			}
			else if (flag==1)
			{
				j++;
				continue;
			}
		}
		else
		{
			int temp=(int)(x-97);
			int flag=search_duplicates(table, y);
			if(flag==0)
			{
				table[temp]=y;
				y++;
				i++;
				x++;
				continue;
			}
			else if(flag==1)
			{
				y++;
				continue;
			}
		}
	}
	cout<<"\n\t TABLE\n";
	for(char i='a'; i<='z'; i++)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	for(int i=0; i<26; i++)
	{
		cout<<(char)(table[i]-97+65)<<" ";
	}
	int j=0;
	for(int i=0; i<strlen(ptext); i++)
	{
		if(ptext[i]==' ' || (ptext[i]>='0' && ptext[i]<='9'))
		{
			ciphertext[j]=ptext[i];
			j++;
			continue;
		}
		ciphertext[j]=table[ptext[i]-97];
		j++;
	}
	ciphertext[j]='\0';
	cout<<"\n The Ciphertext is:\t";
	for(int i=0; i<strlen(ciphertext); i++)
	{
		if(ptext[i]==' ' || (ptext[i]>='0' && ptext[i]<='9'))
		{
			cout<<ciphertext[i];
			continue;
		}
		cout<<(char)(ciphertext[i]-97+65);
	}
	decrypt(ciphertext, table);
}
int main()
{
	char plaintext[50], word[50];
	cin.ignore(50, '\n');
	cout<<"\nEnter the plaintext:\t";
	cin.getline(plaintext, 50);
	cin.ignore(50, '\n');
	cout<<"\nEnter a word:\t";
	cin.getline(word, 50);
	encrypt(plaintext, word);
	return 0;
}
