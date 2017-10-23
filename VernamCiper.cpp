#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
void decrypt(char cipher[], int key[], int j)
{
	int k=0;
	cout<<"\nThe decrypted text is:\t";
	for(int i=0; i<strlen(cipher); i++)
	{
		if(cipher[i]==' ' || (cipher[i]>='0' && cipher[i]<='9'))
		{
			cout<<cipher[i];
			continue;
		}
		int temp=(int)(cipher[i]-65)-key[k];
		while(temp<0)
			temp+=26;
		cout<<(char)(temp+97);
		k++;
	}
}
void encrypt(char ptext[])
{
	int length=strlen(ptext);
	int randarr[length], sum[length], mod[length];
	char cipher[length];
	srand(time(0));
	cout<<"\n Index :\t";
	int j=0;
	for(int i=0; i<length; i++)
	{
		if(ptext[i]==' ' || (ptext[i]>='0' && ptext[i]<='9'))
		{
			cipher[i]=ptext[i];
			continue;
		}
		cout<<(int)(ptext[i]-97)<<"\t";
		randarr[j]=rand()%100;
		sum[j]=randarr[j]+(int)(ptext[i]-97);
		mod[j]=sum[j]%26;
		cipher[i]=(char)(mod[j]+65);
		j++;
	}
	cout<<"\n Random:\t";
	for(int i=0; i<j; i++)
	{
		cout<<randarr[i]<<"\t";
	}
	cout<<"\n Sum :\t\t";
	for(int i=0; i<j; i++)
	{
		cout<<sum[i]<<"\t";
	}
	cout<<"\n mod 26:\t";
	for(int i=0; i<j; i++)
	{
		cout<<mod[i]<<"\t";
	}
	cout<<"\n\n The ciphertext is:\t";
	for(int i=0; i<length; i++)
	{
		cout<<cipher[i];
	}
	decrypt(cipher, randarr, j);
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
